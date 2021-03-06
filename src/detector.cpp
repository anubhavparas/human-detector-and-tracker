/**
 * MIT License
 *
 * Copyright (c) 2021 Anubhav Paras, Sakshi Kakde, Siddharth Telang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * @file detector.cpp
 * @author Anubhav Paras (anubhav@umd.edu)
 * @author Sakshi Kakde (sakshi@umd.edu)
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief Implementation of Detector class
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <detector.hpp>
#include <memory>
#include <unordered_map>
#include <iostream>
#include <limits>
#include <string>
#include <opencv2/opencv.hpp>

typedef HumanDetector HD;

HD::HumanDetector(std::unique_ptr<Model<DetectionOutput, Image>> model,
                  std::unique_ptr<FrameTransformation> robotFrame):
                  model(std::move(model)),
                  robotFrame(std::move(robotFrame)) {
}


HD::~HumanDetector() {
}

std::vector<Coord2D> HD::getCentroids(const Rectangles& boundingBoxes) {
  std::vector<Coord2D> centroids;
  for (const cv::Rect& box : boundingBoxes) {
    Coord2D centroid;
    centroid.x = (box.tl().x + box.br().x)/2.0;
    centroid.y = (box.tl().y + box.br().y)/2.0;
    centroids.push_back(centroid);
    std::cout << centroid.x << "," << centroid.y << std::endl;
  }
  return centroids;
}

std::vector<Coord3D> HD::getRobotFrameCoordinates(
                                const Rectangles& boundingBoxes) {
  std::vector<Coord2D> centroids = this->getCentroids(boundingBoxes);
  std::vector<Coord3D> robotFrameCoordinates;
  for (const Coord2D& centroid : centroids) {
    Coord3D robotFrameCoord = this->robotFrame->getRobotFrame(centroid);
    robotFrameCoordinates.push_back(robotFrameCoord);
  }
  return robotFrameCoordinates;
}

void HD::displayOutput(const cv::Mat &image,
                       const DetectionOutput &predictionOutput,
                       bool isTestMode) {
  Rectangles boundingBoxes = predictionOutput.getData().first;
  std::vector<double> confidenceScores = predictionOutput.getData().second;
  int i = 0;
  for (cv::Rect &box : boundingBoxes) {
    // draw bounding box
    cv::rectangle(image, box.tl(), box.br(), cv::Scalar(0, 255, 0), 2);

    std::string text = "ID: " + std::to_string(i + 1) + " | Score: "
                        + std::to_string(confidenceScores[i]);

    // put ID and confidence score
    cv::putText(image, text, cv::Point(box.x, box.y + 50),
                cv::FONT_HERSHEY_SIMPLEX,
                1, cv::Scalar(0, 255, 0));

    i++;
  }
  if (!isTestMode) {
    cv::imshow("Detected Humans", image);
    cv::waitKey(600);
  }
}

std::vector<Coord3D> HD::detect(const cv::Mat &inputData, bool isTestMode) {
  std::cout << "Detecting objects" << std::endl;
  DetectionOutput predictionOutput = this->model->predict(inputData);
  Rectangles boundingBoxes = predictionOutput.getData().first;
  if (boundingBoxes.size() < 1) {
    std::cout << "No humans detected for the given image." << std::endl;
    return {};
  }

  // get coordinates in robot frame:
  // TODO(Anubhav, Sakshi)
  std::vector<Coord3D> coordinates =
                          this->getRobotFrameCoordinates(boundingBoxes);

  // draw bounding boxes for each detected human and set the id
  this->displayOutput(inputData, predictionOutput, isTestMode);

  return coordinates;
}


double HD::evaluateModel(const cv::Mat &inputData,
                         std::vector<Centroid> gt_centroids) {
  std::cout << "Evaluating model" << std::endl;
  DetectionOutput predictionOutput = this->model->predict(inputData);
  Rectangles boundingBoxes = predictionOutput.getData().first;
  if (boundingBoxes.size() < 1) {
    std::cout << "No humans detected for the given image." << std::endl;
    return -1;
  }
  if (gt_centroids.size() < 1) {
    std::cout << "No ground truth centroids found." << std::endl;
    return -1;
  }
  std::vector<Coord2D> centroids = this->getCentroids(boundingBoxes);

  // find average error in centroids
  double average_error = this->getAverageErrorInDetectionCentroid(centroids,
                                                                  gt_centroids);

  return average_error;
}

double HD::getAverageErrorInDetectionCentroid(
                                const std::vector<Coord2D>& detected_centroids,
                                std::vector<Centroid> gt_centroids) {
  double average_error = 0.0;
  double total_err = 0.0;
  int matched_points = 0;
  for (auto& centroid : detected_centroids) {
    double min_error = std::numeric_limits<double>::max();

    std::unordered_map<double, Centroid&> checkedPoints;
    for (auto& gt_centroid : gt_centroids) {
      if (!gt_centroid.checked) {
        double error = cv::norm(centroid - gt_centroid.coordinate);
        checkedPoints.insert({error, gt_centroid});
        if (error < min_error) {
          min_error = error;
        }
      }
    }
    auto min_error_centroid = checkedPoints.find(min_error);
    if (min_error_centroid != checkedPoints.end()) {
      min_error_centroid->second.checked = true;
      total_err += min_error;
      matched_points++;
    }
  }
  average_error = static_cast<double>(total_err / matched_points);
  return average_error;
}



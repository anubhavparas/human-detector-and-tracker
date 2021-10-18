/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <detector.hpp>
#include <memory>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

typedef HumanDetector HD;

HD::HumanDetector() {}


HD::HumanDetector(std::unique_ptr<Model<DetectionOutput, Image>> model,
                  std::unique_ptr<FrameTransformation> robotFrame) {
    this->model = std::move(model);
    this->robotFrame = std::move(robotFrame);
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
                       const DetectionOutput &predictionOutput) {
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

  cv::imshow("Detected Humans", image);
  cv::waitKey(600);
}

std::vector<Coord3D> HD::detect(const cv::Mat &inputData) {
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
  this->displayOutput(inputData, predictionOutput);

  return coordinates;
}



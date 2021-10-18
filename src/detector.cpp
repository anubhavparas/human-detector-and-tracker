/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <detector.hpp>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

typedef HumanDetector HD;

HD::HumanDetector() {}


HD::HumanDetector(Model<DetectionOutput, Image>* model,
                  FrameTransformation* robotFrame) {
  this->model = model;
  this->robotFrame = robotFrame;
}


HD::~HumanDetector() {
  if (this->model != nullptr) {
    delete this->model;
    this->model = nullptr;
  }
  if (this->robotFrame != nullptr) {
    delete this->robotFrame;
    this->robotFrame = nullptr;
  }
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
  
}

std::vector<Coord3D> HD::detect(const cv::Mat &inputData) {
  std::cout << "Detecting objects" << std::endl;
  std::vector<Coord3D> coordinates;

  return coordinates;
}



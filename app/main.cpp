/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <iostream>
#include <memory>
#include <opencv2/opencv.hpp>

#include <driver.hpp>
#include <datareader.hpp>
#include <preprocessor.hpp>
#include <model.hpp>
#include <detector.hpp>
#include <frame_transformation.hpp>
#include <types.hpp>

int main() {
  std::cout << "Welcome to Human Detector and Tracker."
            << std::endl;

  DataReader<cv::Mat>* dataReader = new ImageReader();
  PreProcessor* preProcessor = new PreProcessor();
  Model<DetectionOutput, Image>* svmModel = new SVMHumanClassifier();
  FrameTransformation* robotFrame = new FrameTransformation();

  Detector* humanDetector = new HumanDetector(svmModel, robotFrame);
  Driver* detectionDriver = new Driver(dataReader, preProcessor, humanDetector);

  std::string test_dir = "../data/testdata";
  detectionDriver->executeDetectionPipeLine(test_dir);

  delete detectionDriver;

  cv::destroyAllWindows();
  return 0;
}



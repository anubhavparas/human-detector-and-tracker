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

  std::unique_ptr<DataReader<cv::Mat>> dataReader(new ImageReader());
  std::unique_ptr<PreProcessor> preProcessor(new PreProcessor());
  std::unique_ptr<Model<DetectionOutput, Image>> svmModel(
                                            new SVMHumanClassifier());
  std::unique_ptr<FrameTransformation> robotFrame(new FrameTransformation());


  std::unique_ptr<Detector> humanDetector(new HumanDetector(std::move(svmModel),
                                              std::move(robotFrame)));

  Driver* detectionDriver = new Driver(std::move(dataReader),
                                       std::move(preProcessor),
                                       std::move(humanDetector),
                                       false);

  std::string test_dir = "../data/testdata/pos";
  detectionDriver->executeDetectionPipeLine(test_dir);

  delete detectionDriver;

  cv::destroyAllWindows();
  return 0;
}



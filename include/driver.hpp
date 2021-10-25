/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_DRIVER_HPP_
#define INCLUDE_DRIVER_HPP_

#include <vector>
#include <memory>
#include <string>
#include <datareader.hpp>
#include <detector.hpp>
#include <model.hpp>
#include <preprocessor.hpp>
#include <types.hpp>

/**
 * @brief This class is responsible for executing the complete detection pipline
 * 
 */
class Driver {
 public:
  /**
   * @brief Construct a new Driver object
   * 
   */
  Driver();

  /**
   * @brief Construct a new Driver object
   * 
   * @param dataReader to read the images or video/camera feed
   * @param preProcessor for the preprocessing of the data 
   * @param detector to detect the objects in the image data
   * @param isTestMode to check if Driver is being instantiated while unit testing
   */
  Driver(std::unique_ptr<DataReader<cv::Mat>> dataReader,
         std::unique_ptr<PreProcessor> preProcessor,
         std::unique_ptr<Detector> detector,
         bool isTestMode);

  /**
   * @brief Destroy the Driver object
   * 
   */
  virtual ~Driver();

  /**
   * @brief starts the detection flow given the path to the test data
   * 
   * @param data_path 
   */
  bool executeDetectionPipeLine(std::string data_path);

  /**
   * @brief To evaluate the performance of the detector
   * 
   * @param data_path directory path of the test_data
   * @return double average error in the detected bounding boxes 
   * across all the test images
   */
  double evaluateModel(std::string data_path);

 private:
    std::unique_ptr<DataReader<cv::Mat>> dataReader;
    std::unique_ptr<PreProcessor> preProcessor;
    std::unique_ptr<Detector> humanDetector;
    bool isTestMode;

    /**
     * @brief to read the ground truth centroid values of detected bounding boxes
     *  from a file
     * 
     * @param file file where centroids information for a image is stored
     * return vector of ground truth centroids of detected bounding boxes
     */
    std::vector<Centroid> read_groundtruth_centroids(std::string file);
};

#endif  //  INCLUDE_DRIVER_HPP_

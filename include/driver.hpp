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
 * *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * @file driver.hpp
 * @author Anubhav Paras (anubhav@umd.edu)
 * @author Sakshi Kakde (sakshi@umd.edu)
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief header file for driver.cpp
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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
  bool executeDetectionPipeLine(const std::string& data_path);

  /**
   * @brief To evaluate the performance of the detector
   * 
   * @param data_path directory path of the test_data
   * @return double average error in the detected bounding boxes 
   * across all the test images
   */
  double evaluateModel(const std::string& data_path);

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

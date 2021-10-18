/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_DATAREADER_HPP_
#define INCLUDE_DATAREADER_HPP_

#include <memory>
#include <string>
#include <opencv2/opencv.hpp>
#include <types.hpp>

/**
 * @brief Generic datareader class
 * 
 * @tparam T type of the data to be returned
 * @tparam U type of the source to read the data from
 */
template <class T, class U = std::string>
class DataReader {
 public:
  virtual ~DataReader() {}
  virtual T readData(U source) = 0;
};

class ImageReader : public DataReader<cv::Mat> {
 public:
  /**
   * @brief Construct a new Image Reader object
   * 
   */
  ImageReader();

  /**
   * @brief Destroy the Image Reader object
   * 
   */
  ~ImageReader();

  /**
   * @brief read the image type data from given string path
   * 
   * 
   * @param path location of the image file
   * @return cv::Mat output frame
   */
  cv::Mat readData(std::string path = "") override;
};


#endif  // INCLUDE_DATAREADER_HPP_

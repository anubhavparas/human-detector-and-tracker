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

// class VideoReader : public DataReader<cv::Mat> {
//  public:
//   /**
//    * @brief Construct a new Video Reader object
//    * 
//    * @param path location of the video file
//    */
//   explicit VideoReader(std::string path);

//   /**
//    * @brief Destroy the Video Reader object
//    * 
//    */
//   ~VideoReader();

//   /**
//    * @brief read the video type data from given string path
//    * 
//    * @param frame output frame
//    * @param path 
//    * @return cv::Mat output frame
//    */
//   cv::Mat readData(std::string path = "") override;

//  private:
//   std::unique_ptr<cv::VideoCapture> video_cap;
// };

// class CameraReader : public DataReader<cv::Mat> {
//  public:
//   /**
//    * @brief Construct a new Camera Reader object
//    * 
//    */
//   explicit CameraReader(int id);

//   /**
//    * @brief Destroy the Camera Reader object
//    * 
//    */
//   ~CameraReader();

//   /**
//    * @brief read the feed from the camera and store that in the output frame
//    * 
//    * @param frame output frame
//    * @param path 
//    * @return cv::Mat output frame 
//    */
//   cv::Mat readData(std::string path = "") override;

//  private:
//   std::unique_ptr<cv::VideoCapture> video_cap;
// };

#endif  // INCLUDE_DATAREADER_HPP_
/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <datareader.hpp>

// ImageReader
ImageReader::ImageReader() {}

ImageReader::~ImageReader() {}

cv::Mat ImageReader::readData(std::string path) {
  cv::Mat frame = cv::imread(path);
  return frame;
}


// // VideoReader
// VideoReader::VideoReader(std::string path) {
//   this->video_cap = std::make_unique<cv::VideoCapture>(
//                                     new cv::VideoCapture(path));
// }

// VideoReader::~VideoReader() {}

// cv::Mat VideoReader::readData(std::string path) {
//   cv::Mat frame;
//   if (this->video_cap->isOpened()) {
//       bool success = this->video_cap->read(frame);
//   }

//   return frame;
// }


// // CameraReader
// CameraReader::CameraReader(int id) {
//   this->video_cap = std::make_unique<cv::VideoCapture>(
//                                     new cv::VideoCapture());
//   this->video_cap->open(id);
// }

// CameraReader::~CameraReader() {}

// cv::Mat CameraReader::readData(std::string path) {
//   cv::Mat frame;
//   if (this->video_cap->isOpened()) {
//       bool success = this->video_cap->read(frame);
//   }

//   return frame;
// }


template class DataReader<cv::Mat>;

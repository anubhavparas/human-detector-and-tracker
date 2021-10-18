/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <datareader.hpp>

// ImageReader
ImageReader::ImageReader() {}

ImageReader::~ImageReader() {}

cv::Mat ImageReader::readData(std::string path) {
  cv::Mat frame = cv::imread(path);
  return frame;
}


template class DataReader<cv::Mat>;

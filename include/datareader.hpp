/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_DATAREADER_HPP_
#define INCLUDE_DATAREADER_HPP_

#include <memory>
#include <string>
#include <optional>
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



#endif  // INCLUDE_DATAREADER_HPP_
/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_MOCK_MOCK_DATAREADER_HPP_
#define INCLUDE_MOCK_MOCK_DATAREADER_HPP_

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

#include <datareader.hpp>
#include <types.hpp>

class MockDataReader : public DataReader<cv::Mat> {
 public:
  MOCK_METHOD1(readData, cv::Mat(std::string));
};

#endif  // INCLUDE_MOCK_MOCK_DATAREADER_HPP_

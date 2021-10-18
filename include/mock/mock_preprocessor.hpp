/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_MOCK_PREPROCESSOR_HPP_
#define INCLUDE_MOCK_PREPROCESSOR_HPP_

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

#include <preprocessor.hpp>
#include <types.hpp>

class MockPreProcessor : public PreProcessor {
 public:
  MOCK_METHOD3(resize, void(cv::InputArray, cv::OutputArray, cv::Size));
};

#endif  // INCLUDE_MOCK_PREPROCESSOR_HPP_
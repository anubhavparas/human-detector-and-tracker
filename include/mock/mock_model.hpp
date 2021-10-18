/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_MOCK_MOCK_MODEL_HPP_
#define INCLUDE_MOCK_MOCK_MODEL_HPP_

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <model.hpp>
#include <types.hpp>

class MockModel : public Model<DetectionOutput, Image> {
 public:
  MOCK_METHOD1(predict, DetectionOutput(Image));
};

#endif  // INCLUDE_MOCK_MOCK_MODEL_HPP_

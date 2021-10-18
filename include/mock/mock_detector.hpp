/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_MOCK_DETECTOR_HPP_
#define INCLUDE_MOCK_DETECTOR_HPP_

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

#include <detector.hpp>
#include <types.hpp>

class MockDetector : public Detector {
 public:
  MOCK_METHOD1(detect, std::vector<Coord3D>(const cv::Mat &));
};

#endif  // INCLUDE_MOCK_DETECTOR_HPP_
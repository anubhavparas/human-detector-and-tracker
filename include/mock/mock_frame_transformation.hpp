/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_FRAMETRANSFORMATION_HPP_
#define INCLUDE_FRAMETRANSFORMATION_HPP_

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <frame_transformation.hpp>
#include <types.hpp>

class MockFrameTR : public FrameTransformation{
 public:
  MOCK_METHOD1(getRobotFrame, Coord3D(Coord2D));
};

#endif  // INCLUDE_FRAMETRANSFORMATION_HPP_
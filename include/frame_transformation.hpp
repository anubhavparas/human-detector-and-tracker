/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_FRAME_TRANSFORMATION_HPP_
#define INCLUDE_FRAME_TRANSFORMATION_HPP_

#include <vector>
#include <types.hpp>

class FrameTransformation {
 public:
  FrameTransformation();
  virtual ~FrameTransformation();
  virtual Coord3D getRobotFrame(Coord2D imageCoordinates);
};

#endif  // INCLUDE_FRAME_TRANSFORMATION_HPP_

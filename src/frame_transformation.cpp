/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <frame_transformation.hpp>

FrameTransformation::FrameTransformation() {}

FrameTransformation::~FrameTransformation() {}

Coord3D FrameTransformation::getRobotFrame(Coord2D imageCoordinates) {
  // logic goes here
  imageCoordinates.x = imageCoordinates.x;
  return Coord3D(0, 0, 0);
}

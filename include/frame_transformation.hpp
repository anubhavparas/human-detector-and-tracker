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
 private:
  Eigen::MatrixXf K;
  Eigen::MatrixXf T_c;
  Eigen::MatrixXf T_r;
  Eigen::MatrixXf P;
};

#endif  // INCLUDE_FRAME_TRANSFORMATION_HPP_

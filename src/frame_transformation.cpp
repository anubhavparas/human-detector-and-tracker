/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <frame_transformation.hpp>

FrameTransformation::FrameTransformation() {
    // camera intrinsic matrix
    this->K = Eigen::MatrixXf(3, 3);
    this->K << 964.828979, 0, 643.788025, 0, 964.828979, 484.407990, 0, 0, 1;
    this->T_c = Eigen::MatrixXf(3, 4);
    this->T_c << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0;
    this->T_r = Eigen::MatrixXf(4, 4);;
    this->T_r<< 0, 0, 1, 10, -1, 0, 0, 10, 0, -1, 0, 10, 0, 0, 0, 1;
    // Projection matrix
    this->P = this->K * this->T_c * this->T_r;
}

FrameTransformation::~FrameTransformation() {}

Coord3D FrameTransformation::getRobotFrame(Coord2D imageCoordinates) {
  // logic goes here
  // Calculate P inverse
  Eigen::MatrixXf P_T = this->P.transpose();
  Eigen::MatrixXf P_inv = P_T * (this->P * P_T).inverse();
  // Image coordinates to homogenous coordinates
  Eigen::MatrixXf x(3, 1);
  x << imageCoordinates.x, imageCoordinates.y, 1;
  Eigen::MatrixXf X = P_inv * x;
  // populate Coord3D
  Coord3D X_robot;
  if (X(3, 0) != 0) {
    X_robot.x = X(0, 0) / X(3, 0);
    X_robot.y = X(1, 0) / X(3, 0);
    X_robot.z = X(2, 0) / X(3, 0);
  } else {
    return Coord3D(0, 0, 0);
  }

  return X_robot;
}

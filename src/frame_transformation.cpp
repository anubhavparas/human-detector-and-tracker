/**
 * MIT License
 *
 * Copyright (c) 2021 Anubhav Paras, Sakshi Kakde, Siddharth Telang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * @file frame_transformation.cpp
 * @author Anubhav Paras (anubhav@umd.edu)
 * @author Sakshi Kakde (sakshi@umd.edu)
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief Performs frame transformation
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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

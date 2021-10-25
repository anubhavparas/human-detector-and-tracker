/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_TYPES_HPP_
#define INCLUDE_TYPES_HPP_

#include <utility>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <data.hpp>

typedef std::vector<cv::Rect> Rectangles;
typedef cv::InputArray Image;
typedef cv::HOGDescriptor SVMHOGModel;
typedef std::pair<Rectangles, std::vector<double>> RectanglesAndScores;
typedef Data<RectanglesAndScores> DetectionOutput;
typedef cv::Point3d Coord3D;
typedef cv::Point Coord2D;

typedef struct Centroid {
    cv::Point coordinate;
    bool checked = false;
} Centroid;

#endif  // INCLUDE_TYPES_HPP_

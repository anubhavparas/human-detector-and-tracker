/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_DETECTOR_HPP_
#define INCLUDE_DETECTOR_HPP_

#include <memory>
#include <vector>
#include <model.hpp>
#include <frame_transformation.hpp>
#include <types.hpp>

/**
 * @brief Generic object detection class
 * 
 */

class Detector {
 public:
  /**
   * @brief detects objects in image
   * 
   */
  virtual std::vector<Coord3D> detect(const cv::Mat &inputData) = 0;
  virtual ~Detector() {}
};

class HumanDetector : public Detector {
 public:
  /**
   * @brief Construct a new Human Detector object
   * 
   */
  HumanDetector();

  /**
   * @brief Construct a new Human Detector object
   * 
   * @param model model used to predict and fetch the bounding boxes
   * @param robotFrame frame transformation to get the coordinates in
   * robot frame
   */
  HumanDetector(std::unique_ptr<Model<DetectionOutput, Image>> model,
                  std::unique_ptr<FrameTransformation> robotFrame);

  /**
   * @brief Destroy the Human Detector object
   * 
   */
  ~HumanDetector();

  /**
   * @brief detects the humans in a given image data
   * displays the bounding boxes and the ids of all the humans detected
   * 
   * @param inputData input image data 
   * @return std::vector<Coord3D> coordinates of all the detected humans
   * in robot frame
   */
  std::vector<Coord3D> detect(const cv::Mat &inputData) override;

 private:
  // model to find the humans
  std::unique_ptr<Model<DetectionOutput, Image>> model;

  // to get the coordinates in robot frame
  std::unique_ptr<FrameTransformation> robotFrame;

  /**
   * @brief Get the list of centroid coordinates of the detected humans in an image
   * 
   * @param boundingBoxes list of bounding boxes of the humans detected
   * @return std::vector<Coord2D> list of centroid (x,y) coordinates
   */
  std::vector<Coord2D> getCentroids(const Rectangles& boundingBoxes);

  /**
   * @brief Get the Robot Frame Coordinates
   * 
   * @param boundingBoxes list of bounding boxes of the humans detected
   * @return std::vector<Coord3D> list of (x,y,z) coordinates in the robot frame
   */
  std::vector<Coord3D> getRobotFrameCoordinates(const Rectangles&);

  /**
   * @brief display the output with bounding boxes, confidence scores and id
   * 
   * @param inputData image data 
   * @param predictionOutput pair of bounding boxes and respective scores
   */
  void displayOutput(const cv::Mat &inputData,
                     const DetectionOutput &predictionOutput);
};

#endif  // INCLUDE_DETECTOR_HPP_

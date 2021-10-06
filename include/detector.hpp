/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_DETECTOR_HPP_
#define INCLUDE_DETECTOR_HPP_

/**
 * @brief Generic object detection class
 * 
 */
class Detector {
 public:
  /**
   * @brief Construct a new Detector object
   * 
   */
  Detector();

  /**
   * @brief Destroy the Detector object
   * 
   */
  ~Detector();

  /**
   * @brief detects objects in image
   * 
   */
  void detect();
};

#endif  // INCLUDE_DETECTOR_HPP_

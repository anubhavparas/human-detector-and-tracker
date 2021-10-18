/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_PREPROCESSOR_HPP_
#define INCLUDE_PREPROCESSOR_HPP_

#include <opencv2/opencv.hpp>
#include <types.hpp>

/**
 * @brief Class to do all the preprocessing of the data
 * 
 */
class PreProcessor {
 public:
  /**
   * @brief Construct a new Pre Processor object
   * 
   */
  PreProcessor();

  /**
   * @brief Destroy the Pre Processor object
   * 
   */
  virtual ~PreProcessor();

  /**
   * @brief 
   * 
   * @param input 
   * @param output 
   * @param size 
   */
  virtual void resize(cv::InputArray input,
                      cv::OutputArray output, cv::Size size);
};

#endif  // INCLUDE_PREPROCESSOR_HPP_

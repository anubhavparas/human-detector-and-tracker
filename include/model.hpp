/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_MODEL_HPP_
#define INCLUDE_MODEL_HPP_

#include <vector>
#include <memory>

#include <opencv2/opencv.hpp>
#include <data.hpp>
#include <types.hpp>

/**
 * @brief Abstract Model class for all the ML models
 * 
 * @tparam T return type of the prediction data
 * @tparam U type of the input data used for prediction
 */
template <class T, class U>
class Model {
 public:
  /**
   * @brief model to predict and return data of type T
   * for any given input of type U
   * 
   * @param data input data of type T for the prediction task 
   * @return T prediction data of type U
   */
  virtual T predict(U data) = 0;

  virtual ~Model() {}
};


class SVMHumanClassifier : public Model<DetectionOutput, Image> {
 public:
  /**
   * @brief Construct a new SVMHumanClassifier object
   * 
   */
  SVMHumanClassifier();

  /**
   * @brief Parameterized constructur to construct new SVMHumanClassifier object
   * 
   * @param baseModel base SVM model to  
   */
  // explicit SVMHumanClassifier(SVMHOGModel baseModel);

  /**
   * @brief Destroy the SVMHumanClassifier object
   * 
   */
  virtual ~SVMHumanClassifier();

  /**
   * @brief predicts the classification output
   * Takes an input image an returns the bounding boxes for the
   * detected humans
   * 
   * @param inputData input image data
   * @return Rectangles bounding boxes for all the humans detected
   */
  DetectionOutput predict(Image inputData) override;

 private:
  SVMHOGModel _baseModel;
};

#endif  // INCLUDE_MODEL_HPP_

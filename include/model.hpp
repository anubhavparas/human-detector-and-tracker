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
 * @file model.hpp
 * @author Anubhav Paras (anubhav@umd.edu)
 * @author Sakshi Kakde (sakshi@umd.edu)
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief header file for model.cpp
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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
/**
 * @brief Destroy the Model object
 * 
 */
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

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
 * @file datareader.hpp
 * @author Anubhav Paras (anubhav@umd.edu)
 * @author Sakshi Kakde (sakshi@umd.edu)
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief header file for datareader.cpp
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INCLUDE_DATAREADER_HPP_
#define INCLUDE_DATAREADER_HPP_

#include <memory>
#include <string>
#include <opencv2/opencv.hpp>
#include <types.hpp>

/**
 * @brief Generic datareader class
 * 
 * @tparam T type of the data to be returned
 * @tparam U type of the source to read the data from
 */
template <class T, class U = std::string>
class DataReader {
 public:
  virtual ~DataReader() {}
  virtual T readData(U source) = 0;
};

class ImageReader : public DataReader<cv::Mat> {
 public:
  /**
   * @brief Construct a new Image Reader object
   * 
   */
  ImageReader();

  /**
   * @brief Destroy the Image Reader object
   * 
   */
  ~ImageReader();

  /**
   * @brief read the image type data from given string path
   * 
   * 
   * @param path location of the image file
   * @return cv::Mat output frame
   */
  cv::Mat readData(std::string path = "") override;
};


#endif  // INCLUDE_DATAREADER_HPP_

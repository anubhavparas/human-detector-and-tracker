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
 * @file data.hpp
 * @author Anubhav Paras (anubhav@umd.edu)
 * @author Sakshi Kakde (sakshi@umd.edu)
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief header file for data.cpp
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INCLUDE_DATA_HPP_
#define INCLUDE_DATA_HPP_


/**
 * @brief Wrapper class for any encapsulate any datatype object
 * 
 * @tparam T - datatpye of the data being wrapped
 */
template <typename T>
class Data {
 public:
  /**
   * @brief Construct a new Data object
   * 
   */
  Data();

  /**
   * @brief parameterized constructer to  a new Data object
   * 
   * @param data 
   */
  explicit Data(T data);

  /**
   * @brief Destroy the Data object
   * 
   */
  virtual ~Data();

  /**
   * @brief Set the Data object
   * 
   * @param data of type T to be set in the _data attribute
   */
  virtual void setData(T data);

  /**
   * @brief Get the Data object
   * 
   * @return T returns the wrapped data of type T
   */
  virtual T getData() const;

 private:
  T _data;
};

#endif  // INCLUDE_DATA_HPP_

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
 * @file preprocessor.cpp
 * @author Anubhav Paras (anubhav@umd.edu)
 * @author Sakshi Kakde (sakshi@umd.edu)
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief Preprocessor to resize the data
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <preprocessor.hpp>

PreProcessor::PreProcessor() {}

PreProcessor::~PreProcessor() {}

void PreProcessor::resize(cv::InputArray input,
                          cv::OutputArray output, cv::Size size) {
    if (size != cv::Size()) {
        cv::resize(input, output, size);
    }
}

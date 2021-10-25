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
 * @file model.cpp
 * @author Anubhav Paras (anubhav@umd.edu)
 * @author Sakshi Kakde (sakshi@umd.edu)
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief Constructs SVMHumanClassifier model object
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <model.hpp>


SVMHumanClassifier::SVMHumanClassifier() {
    this->_baseModel.setSVMDetector(SVMHOGModel::getDefaultPeopleDetector());
}

// SVMHumanClassifier::SVMHumanClassifier(SVMHOGModel baseModel) {
//     this->_baseModel = baseModel;
// }

SVMHumanClassifier::~SVMHumanClassifier() {}

DetectionOutput SVMHumanClassifier::predict(Image inputData) {
    Rectangles boundingBoxes;
    std::vector<double> weights;
    DetectionOutput output;
    this->_baseModel.detectMultiScale(inputData, boundingBoxes, weights);
    output.setData(
        RectanglesAndScores(boundingBoxes, weights));  // pair of BB and scores
    return output;
}


template class Model<DetectionOutput, Image>;



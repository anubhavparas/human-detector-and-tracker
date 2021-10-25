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
 * @file test_model.cpp
 * @author Anubhav Paras (anubhav@umd.edu)
 * @author Sakshi Kakde (sakshi@umd.edu)
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief test file for model.cpp
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <model.hpp>


TEST(svm_model_test, check_prediction_with_human) {
    Model<DetectionOutput, Image> *svmModel = new SVMHumanClassifier();

    std::string test_path =
            "../data/testdata/unit_test_data/pos/FudanPed00028.png";
    cv::Mat image = cv::imread(test_path);
    DetectionOutput detectionOut = svmModel->predict(image);
    Rectangles boundingBoxes = detectionOut.getData().first;
    std::vector<double> scores = detectionOut.getData().second;

    EXPECT_GT(static_cast<int>(boundingBoxes.size()), 0);
    EXPECT_EQ(boundingBoxes.size(), scores.size());

    delete svmModel;
}


// TEST(svm_model_test, check_prediction_without_human) {
//     SVMHOGModel svmHOGModel;
//     svmHOGModel.setSVMDetector(SVMHOGModel::getDefaultPeopleDetector());
//     Model<DetectionOutput, Image> *svmModel =
//                 new SVMHumanClassifier(svmHOGModel);

//     std::string test_path = "../docs/images/horse.png";
//     cv::Mat image = cv::imread(test_path);
//     DetectionOutput detectionOut = svmModel->predict(image);
//     Rectangles boundingBoxes = detectionOut.getData().first;
//     std::vector<double> scores = detectionOut.getData().second;

//     EXPECT_EQ(boundingBoxes.size(), 0);
//     EXPECT_EQ(boundingBoxes.size(), scores.size());

//     delete svmModel;
// }

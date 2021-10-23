/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <gtest/gtest.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <model.hpp>


TEST(svm_model_test, check_prediction_with_human) {
    Model<DetectionOutput, Image> *svmModel = new SVMHumanClassifier();

    std::string test_path = "../data/testdata/FudanPed00028.png";
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

/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <gtest/gtest.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <preprocessor.hpp>


TEST(preprocessor_test, image_resize) {
    std::string test_path = "../docs/images/FudanPed00028.png";

    PreProcessor preProcessor;
    cv::Mat image = cv::imread(test_path);
    cv::Size originalSize = image.size();
    cv::Size expectedSize = cv::Size();
    preProcessor.resize(image, image, expectedSize);

    EXPECT_FALSE(image.empty());

}
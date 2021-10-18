/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <gtest/gtest.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <preprocessor.hpp>


TEST(preprocessor_test, image_resize) {
    std::string test_path = "../data/testdata/FudanPed00028.png";

    PreProcessor preProcessor;
    cv::Mat image = cv::imread(test_path);
    cv::Size originalSize = image.size();
    cv::Size expectedSize = cv::Size(100, 100);
    preProcessor.resize(image, image, expectedSize);

    EXPECT_TRUE(image.size().height != originalSize.height);
    EXPECT_EQ(image.size().height, expectedSize.height);

    EXPECT_TRUE(image.size().width != originalSize.width);
    EXPECT_EQ(image.size().width, expectedSize.width);
}

TEST(preprocessor_test, image_resize_no_resize) {
    std::string test_path = "../data/testdata/FudanPed00028.png";

    PreProcessor preProcessor;
    cv::Mat image = cv::imread(test_path);
    cv::Size originalSize = image.size();
    preProcessor.resize(image, image, cv::Size());

    EXPECT_EQ(image.size().height,  originalSize.height);
    EXPECT_EQ(image.size().width, originalSize.width);
}

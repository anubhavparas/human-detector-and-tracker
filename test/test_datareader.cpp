/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <gtest/gtest.h>
#include <string>
#include <datareader.hpp>


TEST(image_reader_test, image_read_success) {
    DataReader<cv::Mat> *imageReader = new ImageReader();
    std::string test_path = "../data/testdata/FudanPed00028.png";

    cv::Mat image = imageReader->readData(test_path);
    EXPECT_FALSE(image.empty());
    delete imageReader;
}


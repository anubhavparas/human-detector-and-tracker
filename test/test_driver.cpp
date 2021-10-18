/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <driver.hpp>
#include <mock/mock_datareader.hpp>
#include <mock/mock_preprocessor.hpp>
#include <mock/mock_detector.hpp>

using ::testing::_;

TEST(driver_test, test_executeDetectionPipeLine) {
    // SET
    MockDataReader mockDataReader;
    MockPreProcessor mockPreProcessor;
    MockDetector mockDetector;

    std::string test_dir = "../data/testdata";
    std::string test_image_path = "../data/testdata/FudanPed00028.png";

    cv::Mat test_image = cv::imread(test_image_path);
    cv::Mat empty_image;

    // ARRANGE
    std::vector<Coord3D> locations = {Coord3D(0, 0, 0), Coord3D(1, 2, 3)};

    EXPECT_CALL(mockDataReader, readData(_))
                .WillOnce(::testing::Return(empty_image))
                .WillRepeatedly(::testing::Return(test_image));

    EXPECT_CALL(mockPreProcessor, resize(_, _, _))
                .Times(::testing::AnyNumber());

    EXPECT_CALL(mockDetector, detect(_))
                .WillRepeatedly(::testing::Return(locations));

    // ACT
    Driver* detectionDriver = new Driver(
                    &mockDataReader, &mockPreProcessor, &mockDetector);
    bool status = detectionDriver->executeDetectionPipeLine(test_dir);

    EXPECT_TRUE(status);

    // delete detectionDriver;
}

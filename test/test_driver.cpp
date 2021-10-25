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
 * @file test_driver.cpp
 * @author Anubhav Paras (anubhav@umd.edu)
 * @author Sakshi Kakde (sakshi@umd.edu)
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief test file for driver.cpp
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

#include <driver.hpp>
#include <mock/mock_datareader.hpp>
#include <mock/mock_preprocessor.hpp>
#include <mock/mock_detector.hpp>

using ::testing::_;

TEST(driver_test, test_executeDetectionPipeLine) {
    // SET
    std::unique_ptr<MockDataReader> mockDataReader(new MockDataReader());
    std::unique_ptr<MockPreProcessor> mockPreProcessor(new MockPreProcessor());
    std::unique_ptr<MockDetector> mockDetector(new MockDetector());

    std::string test_dir = "../data/testdata/unit_test_data/pos";
    std::string test_image_path =
            "../data/testdata/unit_test_data/pos/FudanPed00028.png";

    cv::Mat test_image = cv::imread(test_image_path);
    cv::Mat empty_image;

    // ARRANGE
    std::vector<Coord3D> locations = {Coord3D(0, 0, 0), Coord3D(1, 2, 3)};

    EXPECT_CALL(*mockDataReader, readData(_))
                .WillOnce(::testing::Return(empty_image))
                .WillRepeatedly(::testing::Return(test_image));

    EXPECT_CALL(*mockPreProcessor, resize(_, _, _))
                .Times(::testing::AnyNumber());

    EXPECT_CALL(*mockDetector, detect(_, _))
                .WillRepeatedly(::testing::Return(locations));

    // ACT
    Driver* detectionDriver = new Driver(
                    std::move(mockDataReader),
                    std::move(mockPreProcessor),
                    std::move(mockDetector),
                    true);
    bool status = detectionDriver->executeDetectionPipeLine(test_dir);

    EXPECT_TRUE(status);

    delete detectionDriver;
    detectionDriver = nullptr;
}


TEST(driver_test, test_evaluate_model) {
    // SET
    std::unique_ptr<MockDataReader> mockDataReader(new MockDataReader());
    std::unique_ptr<MockPreProcessor> mockPreProcessor(new MockPreProcessor());
    std::unique_ptr<MockDetector> mockDetector(new MockDetector());

    std::string test_dir = "../data/testdata/unit_test_data";
    std::string test_image_path =
            "../data/testdata/unit_test_data/pos/FudanPed00028.png";

    cv::Mat test_image = cv::imread(test_image_path);
    cv::Mat empty_image;

    double detection_err_image = 5.0;

    EXPECT_CALL(*mockDataReader, readData(_))
                .WillOnce(::testing::Return(empty_image))
                .WillRepeatedly(::testing::Return(test_image));


    EXPECT_CALL(*mockDetector, evaluateModel(_, _))
                .WillOnce(::testing::Return(-1))
                .WillRepeatedly(::testing::Return(detection_err_image));

    // ACT
    Driver* detectionDriver = new Driver(
                    std::move(mockDataReader),
                    std::move(mockPreProcessor),
                    std::move(mockDetector),
                    true);

    double actual_error = detectionDriver->evaluateModel(test_dir);
    EXPECT_EQ(detection_err_image, actual_error);

    delete detectionDriver;
    detectionDriver = nullptr;
}

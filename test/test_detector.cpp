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
 * @file test_detector.cpp
 * @author Anubhav Paras (anubhav@umd.edu)
 * @author Sakshi Kakde (sakshi@umd.edu)
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief test file for detector.cpp
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <detector.hpp>
#include <mock/mock_model.hpp>
#include <mock/mock_frame_transformation.hpp>

using ::testing::_;


TEST(detector_test, test_detect) {
    // SET
    std::unique_ptr<MockModel> mockModel(new MockModel());
    std::unique_ptr<MockFrameTR> mockFrameTR(new MockFrameTR());

    std::string test_path =
            "../data/testdata/unit_test_data/pos/FudanPed00028.png";
    cv::Mat image = cv::imread(test_path);

    // ARRANGE
    Rectangles boundingBoxes;
    cv::Rect bb(10, 10, 10, 10);
    boundingBoxes.push_back(bb);

    std::vector<double> scores = {0.1};
    DetectionOutput expectedPrediction({boundingBoxes, scores});
    Coord3D expectedFrame(0, 0, 0);

    EXPECT_CALL(*mockModel, predict(_))
                .WillOnce(::testing::Return(expectedPrediction));

    EXPECT_CALL(*mockFrameTR, getRobotFrame(_))
                .WillOnce(::testing::Return(expectedFrame));


    // ACT
    Detector* detector = new HumanDetector(std::move(mockModel),
                                           std::move(mockFrameTR));
    std::vector<Coord3D> detectionOut = detector->detect(image, true);

    EXPECT_EQ(detectionOut.at(0).x, expectedFrame.x);
    EXPECT_EQ(detectionOut.at(0).y, expectedFrame.y);
    EXPECT_EQ(detectionOut.at(0).z, expectedFrame.z);

    std::cout << "testing done! for detection" << std::endl;

    // cv::destroyAllWindows();
    delete detector;
    detector = nullptr;
    ::testing::Mock::VerifyAndClearExpectations(mockModel.get());
    ::testing::Mock::VerifyAndClearExpectations(mockFrameTR.get());
}


TEST(detector_test, test_detect_no_boundingbox) {
    // SET
    std::unique_ptr<MockModel> mockModel(new MockModel());
    std::unique_ptr<MockFrameTR> mockFrameTR(new MockFrameTR());

    std::string test_path =
            "../data/testdata/unit_test_data/pos/horse.png";
    cv::Mat image = cv::imread(test_path);

    // ARRANGE
    Rectangles boundingBoxes;
    std::vector<double> scores;

    DetectionOutput expectedPrediction({boundingBoxes, scores});

    EXPECT_CALL(*mockModel, predict(_))
                .WillOnce(::testing::Return(expectedPrediction));

    // ACT
    Detector* detector = new HumanDetector(std::move(mockModel),
                                           std::move(mockFrameTR));
    std::vector<Coord3D> detectionOut = detector->detect(image, true);

    EXPECT_EQ(static_cast<int>(detectionOut.size()), 0);

    delete detector;
    detector = nullptr;
    ::testing::Mock::VerifyAndClearExpectations(mockModel.get());
    ::testing::Mock::VerifyAndClearExpectations(mockFrameTR.get());
}

TEST(detector_test, test_evaluate_no_boundingbox) {
    // SET
    std::unique_ptr<MockModel> mockModel(new MockModel());
    std::unique_ptr<MockFrameTR> mockFrameTR(new MockFrameTR());

    std::string test_path =
            "../data/testdata/unit_test_data/pos/horse.png";
    cv::Mat image = cv::imread(test_path);
    std::vector<Centroid> gt_centroids;

    // ARRANGE
    Rectangles boundingBoxes;
    std::vector<double> scores;

    DetectionOutput expectedPrediction({boundingBoxes, scores});

    EXPECT_CALL(*mockModel, predict(_))
                .WillOnce(::testing::Return(expectedPrediction));

    // ACT
    Detector* detector = new HumanDetector(std::move(mockModel),
                                           std::move(mockFrameTR));
    double actual_error = detector->evaluateModel(image, gt_centroids);

    EXPECT_EQ(actual_error, -1);

    delete detector;
    detector = nullptr;
}

TEST(detector_test, test_evaluate_no_gt_centroids) {
    // SET
    std::unique_ptr<MockModel> mockModel(new MockModel());
    std::unique_ptr<MockFrameTR> mockFrameTR(new MockFrameTR());

    std::string test_path =
            "../data/testdata/unit_test_data/pos/horse.png";
    cv::Mat image = cv::imread(test_path);
    std::vector<Centroid> gt_centroids;

    // ARRANGE
     Rectangles boundingBoxes;
    cv::Rect bb(10, 10, 10, 10);
    boundingBoxes.push_back(bb);

    std::vector<double> scores = {0.1};
    DetectionOutput expectedPrediction({boundingBoxes, scores});


    EXPECT_CALL(*mockModel, predict(_))
                .WillOnce(::testing::Return(expectedPrediction));

    // ACT
    Detector* detector = new HumanDetector(std::move(mockModel),
                                           std::move(mockFrameTR));
    double actual_error = detector->evaluateModel(image, gt_centroids);

    EXPECT_EQ(actual_error, -1);

    delete detector;
    detector = nullptr;
}


TEST(detector_test, test_evaluate_model) {
    // SET
    std::unique_ptr<MockModel> mockModel(new MockModel());
    std::unique_ptr<MockFrameTR> mockFrameTR(new MockFrameTR());

    std::string test_path =
            "../data/testdata/unit_test_data/pos/FudanPed00028.png";
    cv::Mat image = cv::imread(test_path);
    std::vector<Centroid> gt_centroids;
    Centroid gt_cent1({cv::Point(15, 15), false});
    Centroid gt_cent2({cv::Point(30, 30), false});
    gt_centroids.push_back(gt_cent1);
    gt_centroids.push_back(gt_cent2);

    // ARRANGE
    Rectangles boundingBoxes;
    cv::Rect bb1(10, 10, 10, 10);
    cv::Rect bb2(20, 20, 20, 20);
    boundingBoxes.push_back(bb1);
    boundingBoxes.push_back(bb2);

    std::vector<double> scores = {0.1, 0.2};
    DetectionOutput expectedPrediction({boundingBoxes, scores});

    EXPECT_CALL(*mockModel, predict(_))
                .WillOnce(::testing::Return(expectedPrediction));


    // ACT
    Detector* detector = new HumanDetector(std::move(mockModel),
                                           std::move(mockFrameTR));
    double actual_error = detector->evaluateModel(image, gt_centroids);

    EXPECT_EQ(actual_error, 0.0);

    delete detector;
    detector = nullptr;
}

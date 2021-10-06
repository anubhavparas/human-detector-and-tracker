/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */


#include <gtest/gtest.h>

#include <detector.hpp>

TEST(detector_test, dummy_detection_test) {
    Detector humanDetector;
    humanDetector.detect();
    EXPECT_TRUE(true);
}

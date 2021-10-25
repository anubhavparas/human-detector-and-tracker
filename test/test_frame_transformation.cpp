/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <gtest/gtest.h>
#include <string>
#include <frame_transformation.hpp>


TEST(frame_transformation_test, check_frame_transformation) {
    FrameTransformation *FT = new FrameTransformation();
    Coord2D x(0, 0);
    Coord3D expected_X(-79.26, 187.78, 108.62);
    Coord3D computed_X = FT->getRobotFrame(x);
    EXPECT_NEAR(computed_X.x, expected_X.x, 0.1);
    EXPECT_NEAR(computed_X.y, expected_X.y, 0.1);
    EXPECT_NEAR(computed_X.z, expected_X.z, 0.1);
    delete FT;
}

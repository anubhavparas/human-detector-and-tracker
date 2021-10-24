set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test_data.cpp
    test_datareader.cpp
    test_detector.cpp
    test_model.cpp
    test_preprocessor.cpp
    test_driver.cpp
    test_frame_transformation.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include
                                           ../vendor/googletest/googlemock/include)
target_link_libraries(cpp-test PUBLIC human_detector_tracker gtest gmock ${OpenCV_LIBS})

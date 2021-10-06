set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test_detector.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include
                                           ../vendor/googletest/googlemock/include)
target_link_libraries(cpp-test PUBLIC gtest gmock human_detector_tracker)

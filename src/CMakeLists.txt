include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_library(human_detector_tracker detector.cpp ${CMAKE_SOURCE_DIR}/include/detector.hpp)
target_include_directories(human_detector_tracker PUBLIC ../include)
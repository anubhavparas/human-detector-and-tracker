add_executable(human-detect-app main.cpp)
include_directories(
    ${OpenCV_INCLUDE_DIRS}	
)
target_link_libraries(human-detect-app PRIVATE human_detector_tracker ${OpenCV_LIBS})
add_executable(human-detect-app main.cpp)
add_executable(evaluate-human-detect-app evaluate.cpp)
# include_directories(
#     ${OpenCV_INCLUDE_DIRS}	
# )
target_link_libraries(human-detect-app PRIVATE human_detector_tracker ${OpenCV_LIBS})
target_link_libraries(evaluate-human-detect-app PRIVATE human_detector_tracker ${OpenCV_LIBS})
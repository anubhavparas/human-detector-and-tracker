include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# add_library(human_detector_tracker data.cpp ${CMAKE_SOURCE_DIR}/include/data.hpp datareader.cpp ${CMAKE_SOURCE_DIR}/include/datareader.hpp detector.cpp ${CMAKE_SOURCE_DIR}/include/detector.hpp driver.cpp ${CMAKE_SOURCE_DIR}/include/driver.hpp ${CMAKE_SOURCE_DIR}/include/frame_transformation.hpp model.cpp ${CMAKE_SOURCE_DIR}/include/model.hpp preprocessor.cpp ${CMAKE_SOURCE_DIR}/include/preprocessor.hpp ${CMAKE_SOURCE_DIR}/include/types.hpp)

add_library(human_detector_tracker
            data.cpp
            datareader.cpp 
            detector.cpp
            driver.cpp
            frame_transformation.cpp
            model.cpp
            preprocessor.cpp
            ${CMAKE_SOURCE_DIR}/include/data.hpp 
            ${CMAKE_SOURCE_DIR}/include/datareader.hpp 
            ${CMAKE_SOURCE_DIR}/include/detector.hpp 
            ${CMAKE_SOURCE_DIR}/include/driver.hpp 
            ${CMAKE_SOURCE_DIR}/include/frame_transformation.hpp 
            ${CMAKE_SOURCE_DIR}/include/model.hpp 
            ${CMAKE_SOURCE_DIR}/include/preprocessor.hpp 
            ${CMAKE_SOURCE_DIR}/include/types.hpp
            )

target_include_directories(human_detector_tracker PUBLIC ../include)
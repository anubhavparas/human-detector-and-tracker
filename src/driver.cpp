/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <driver.hpp>

Driver::Driver() {
}

Driver::Driver(std::unique_ptr<DataReader<cv::Mat>> dataReader,
         std::unique_ptr<PreProcessor> preProcessor,
         std::unique_ptr<Detector> detector) {
  this->dataReader = std::move(dataReader);
  this->preProcessor = std::move(preProcessor);
  this->humanDetector = std::move(detector);
}

Driver::~Driver() {
}

bool Driver::executeDetectionPipeLine(std::string data_path) {
    std::vector<cv::String> filePaths;
    cv::glob(data_path, filePaths);

    // read images one by one and detect humans
    for (auto& file : filePaths) {
        cv::Mat frame = this->dataReader->readData(file);

        if (frame.empty()) {
            std::cout << "Cannot read data from: " << file << std::endl;
            continue;
        }
        this->preProcessor->resize(frame, frame, cv::Size());
        std::vector<Coord3D> locations = this->humanDetector->detect(frame);

        // print the coordinates:
        std::cout << "For frame at " << file << "humans are at: " << std::endl;
        for (auto& coordinate : locations) {
            std::cout << "("
                      << coordinate.x << ","
                      << coordinate.y << ","
                      << coordinate.z << ")\n"
                      << std::endl;
        }
    }
    return true;
}

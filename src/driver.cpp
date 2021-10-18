/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <driver.hpp>

Driver::Driver() {
  this->dataReader = new ImageReader();
  this->preProcessor = new PreProcessor();
  this->humanDetector = new HumanDetector();
}

Driver::Driver(DataReader<cv::Mat> *dataReader, PreProcessor *preProcessor,
               Detector *detector) {
  this->dataReader = dataReader;
  this->preProcessor = preProcessor;
  this->humanDetector = detector;
}

Driver::~Driver() {
    if (dataReader != nullptr) {
        delete dataReader;
        dataReader = nullptr;
    }
    if (preProcessor != nullptr) {
        delete preProcessor;
        preProcessor = nullptr;
    }
    if (humanDetector != nullptr) {
        delete humanDetector;
        humanDetector = nullptr;
    }
}

void Driver::executeDetectionPipeLine(std::string data_path) {
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
}

/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <driver.hpp>

#include <fstream>

Driver::Driver() {
}

Driver::Driver(std::unique_ptr<DataReader<cv::Mat>> dataReader,
         std::unique_ptr<PreProcessor> preProcessor,
         std::unique_ptr<Detector> detector,
         bool isTestMode) {
  this->dataReader = std::move(dataReader);
  this->preProcessor = std::move(preProcessor);
  this->humanDetector = std::move(detector);
  this->isTestMode = isTestMode;
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
        std::vector<Coord3D> locations = this->humanDetector->detect(frame,
                                                        this->isTestMode);

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

std::vector<Centroid> Driver::read_groundtruth_centroids(std::string file) {
    std::cout << "Reading the ground truth centroids for::"
              << file
              << std::endl;
    std::vector<Centroid> gt_centroids;
    double x, y;
    char delim;
    std::ifstream gt_data_stream(file);
    while (gt_data_stream >> x >> delim >> y) {
        Centroid c({cv::Point(x, y), false});
        gt_centroids.push_back(c);
    }
    return gt_centroids;
}


double Driver::evaluateModel(std::string data_path) {
    std::vector<cv::String> filePaths;
    std::string imagePath = data_path + "/pos";
    std::string groundTruthPath = data_path + "/ground_truth/";
    cv::glob(imagePath, filePaths);
    double total_error = 0.0;
    double average_error = 0.0;
    int detection_count = 0;
    // read images one by one and detect humans
    for (auto& file : filePaths) {
        cv::Mat frame = this->dataReader->readData(file);

        if (frame.empty()) {
            std::cout << "Cannot read data from: " << file << std::endl;
            continue;
        }


        size_t last_slash = file.find_last_of("/");
        std::string image_file_name = file.substr(last_slash + 1);

        size_t lastdot = image_file_name.find_last_of(".");
        std::string gt_file_name = groundTruthPath
                                + image_file_name.substr(0, lastdot)
                                + ".txt";

        std::vector<Centroid> gt_centroids =
                            this->read_groundtruth_centroids(gt_file_name);
        double error = this->humanDetector->evaluateModel(frame, gt_centroids);

        if (error != -1) {
           total_error += error;
           detection_count++;
        }
    }
    average_error = static_cast<double>(total_error / detection_count);
    return average_error;
}

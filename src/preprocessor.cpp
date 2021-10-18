/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <preprocessor.hpp>

PreProcessor::PreProcessor() {}

PreProcessor::~PreProcessor() {}

void PreProcessor::resize(cv::InputArray input,
                          cv::OutputArray output, cv::Size size) {
    cv::resize(input, output, size);
}

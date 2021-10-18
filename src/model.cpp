/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <model.hpp>


SVMHumanClassifier::SVMHumanClassifier() {
}

// SVMHumanClassifier::SVMHumanClassifier(SVMHOGModel baseModel) {
//     this->_baseModel = baseModel;
// }

SVMHumanClassifier::~SVMHumanClassifier() {}

DetectionOutput SVMHumanClassifier::predict(Image inputData) {
    DetectionOutput output;
    return output;
}


template class Model<DetectionOutput, Image>;



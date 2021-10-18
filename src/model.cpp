/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <model.hpp>


SVMHumanClassifier::SVMHumanClassifier() {
    this->_baseModel.setSVMDetector(SVMHOGModel::getDefaultPeopleDetector());
}

// SVMHumanClassifier::SVMHumanClassifier(SVMHOGModel baseModel) {
//     this->_baseModel = baseModel;
// }

SVMHumanClassifier::~SVMHumanClassifier() {}

DetectionOutput SVMHumanClassifier::predict(Image inputData) {
    Rectangles boundingBoxes;
    std::vector<double> weights;
    DetectionOutput output;
    this->_baseModel.detectMultiScale(inputData, boundingBoxes, weights);
    output.setData(
        RectanglesAndScores(boundingBoxes, weights));  // pair of BB and scores
    return output;
}


template class Model<DetectionOutput, Image>;



# Human Detector and Tracker

Module to detect and track humans and return their coordinate position.

[![Build Status](https://app.travis-ci.com/anubhavparas/human-detector-and-tracker.svg?branch=main)](https://app.travis-ci.com/anubhavparas/human-detector-and-tracker)
[![Coverage Status](https://coveralls.io/repos/github/anubhavparas/human-detector-and-tracker/badge.png?branch=main)](https://coveralls.io/github/anubhavparas/human-detector-and-tracker?branch=main)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
---

Authors: 
- [Anubhav Paras](https://github.com/anubhavparas) (Navigator)
- [Sakshi Kakde](https://github.com/sakshikakde) (Heavy Driver)
- [Siddharth Telang](https://github.com/siddharthtelang) (Design Keeper)

## Overview

Object detection has become an essential part of all robotic applications. A robot perceives the environment through its sensors and on the basis of the data collected, it performs some action. Specifically, human detection is a core problem in object detection. Avoiding collision with humans during the work process is a critical task for any developer who is designing the robotic application. This avoidance is strictly enforced to avoid any harm, damage or loss of (in the worst case scenario) human life. To add to this, object detection and particularly human detection in a dynamic environment is a very challenging task and demands high precision.

Numerous human object detectors have been developed till date which work very smoothly and accurately and their applications are growing rapidly. In addition it is one of the most popular research topics. With the advent of machine learning it has become easier to design these trackers given a large data set. However, it takes a long time to train such models and require high computational power and efficiency.

Acme robotics would be launching their robotics based product next year and a human detection and tracking system is the heart of that product. They have given us the complete ownership of designing and developing this detector and tracker. For this application, we aim to use Histogram of Features(HoG) with a Support Vector Machine(SVM) classifier.

Initially, we aim to train our model to extract features which would recognize humans in any given data set. We plan to use the INRIA Person Dataset to train our model. Given the data, a HoG would be generated. Next, these HOG vectors or features will be used to train a SVM classifier to detect the location of a human in any image. An error function will calculate the error made in classification which would be then fed to the classifier as a feedback to improve the accuracy. After the training is completed, the classifier would be able to detect the human position and draw a bounding box around it in real time. In addition to this, the output of the classifier would be given to a tracking system to keep track of human(s) in real-time. Moreover, the tracked output will also be converted from image and camera frame to robot’s frame for further processing.


## Deliverables
- Project: Human(s) obstacle detector and tracker - Output in robot reference frame.
- Overview of proposed work including timeline, risks, and mitigations.
- UML diagrams.
- Github repository with [README](./readme.md)
- Travis code coverage setup with Coveralls.
- Developer-level documentation.

## Potential Risks and Mitigation
- HoG is not scale invariant.
- Missed detections: It may happen that the model sometimes misses the detection of human presence. In such a case, deploying more than one and different models can be more useful.
- False and duplicate detection: Can be reduced by training the model such that the parameters are well tuned and the loss on validation data set is minimum.
- Unreliable detection boundary: Can be made accurate by selecting an optimum classifier, like the Bayes classifier.
- Flickers in detection: Filter can be deployed for a better estimate.

## Design
The following are the proposed designs for the human detector and tracker: 

![alt text](./docs/images/HumanDetectorTracker_ClassDiagram.png?raw=true "PID Controller")

Activity flow diagrams can be found [here](./docs/images/).


## Standard install via command-line
```
git clone --recursive https://github.com/anubhavparas/human-detector-and-tracker.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```
or run: 
```
sh build_coverage_off.sh
```

## Building for code coverage
Install code-coverage tool, else the code coverage command will not work. It is a one time installation: 
```
sudo apt-get install lcov
```
```
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```

or run: 
```
sh build_coverage_on.sh
```

This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Run cppcheck and cpplint
Run cppcheck: Results are stored in `./results/cppcheck_process.txt`, `./results/cppcheck_result.txt` 
```
sh run_cppcheck.sh
```

Run cpplint: Results are stored in `./results/cpplint_result.txt`
```
sh run_cpplint.sh
```





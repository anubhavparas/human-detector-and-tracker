# Acme Robotics PID Controller
[![Build Status](https://app.travis-ci.com/anubhavparas/human-detector-and-tracker.svg?branch=main)](https://app.travis-ci.com/anubhavparas/human-detector-and-tracker)
[![Coverage Status](https://coveralls.io/repos/github/anubhavparas/human-detector-and-tracker/badge.png?branch=main)](https://coveralls.io/github/anubhavparas/human-detector-and-tracker?branch=main)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
---

Authors: 
- [Anubhav Paras](https://github.com/anubhavparas) (Navigator)
- [Sakshi Kakde](https://github.com/sakshikakde) (Driver)
- [Siddharth Telang](https://github.com/siddharthtelang) (Design Keeper)

## Overview



The following are the proposed designs for the human detector and tracker: 

TO BE ADDED.....!

Flow diagrams can be found [here](./docs/images/).



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





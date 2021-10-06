rm -rf build/
mkdir build
cd build
cmake -DCOVERAGE=ON -DCMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
test/cpp-test


# Coverage
sudo apt-get install -y -qq lcov

# OpenCV install
sudo apt-get install -y build-essential
sudo apt-get install -y cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt-get install -y python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

# # Download v3.3.0
curl -sL https://github.com/Itseez/opencv/archive/3.3.0.zip > opencv.zip
unzip opencv.zip
cd opencv-3.3.0
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE -D BUILD_EXAMPLES=OFF -D BUILD_opencv_apps=OFF -D BUILD_DOCS=OFF -D BUILD_PERF_TESTS=OFF -D BUILD_TESTS=OFF -D CMAKE_INSTALL_PREFIX=/usr/local ..
make -j4
sudo make install

sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
cd ../../

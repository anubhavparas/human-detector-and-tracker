/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

// #include <iostream>
// #include <opencv2/opencv.hpp>

// int main() {
//   std::cout << "Welcome to Human Detector and Tracker."
//             << std::endl;

//   cv::Mat image;
//   image = cv::imread("../docs/images/HumanDetectorTracker_ActivityDiagram.png");
//   if (!image.data) {
//     std::cout << "No image data" << std::endl;
//     return -1;
//   }
//   cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
//   cv::imshow("Display Image", image);
//   cv::waitKey(0);
//   return 0;
// }

#include <iostream>
#include <opencv2/opencv.hpp>

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;
using namespace cv::ml;

int main() {
  int deviceID = 0;             // 0 = open default camera
  int apiID = cv::CAP_ANY;      // 0 = autodetect default API
  VideoCapture cap;

  // cap.open(deviceID, apiID);
  // if (!cap.isOpened()) {
  //     cerr << "ERROR! Unable to open camera\n";
  //     return -1;
  // }
  // Mat current_frame;

  /// Set up the pedestrian detector --> let us take the default one
  HOGDescriptor hog;
  hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

  /// Set up tracking vector
  vector<Point> track;

  // while (true) {
    /// Grab a single frame from the video
    // cap >> current_frame;
    // cap.read(current_frame);
    Mat current_frame = imread("../docs/images/FudanPed00001.png");
    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display Image", current_frame);

    /// Check if the frame has content
    if (current_frame.empty()) {
      cerr << "Video has ended or bad frame was read. Quitting." << endl;
      return 0;
    }

    /// run the detector with default parameters. to get a higher hit-rate
    /// (and more false alarms, respectively), decrease the hitThreshold and
    /// groupThreshold (set groupThreshold to 0 to turn off the grouping completely).

    ///image, vector of rectangles, hit threshold, win stride, padding, scale, group th
    Mat img = current_frame.clone();
    // resize(img, img, Size(img.cols * 2, img.rows * 2));

    vector<Rect> found;
    vector<double> weights;

    hog.detectMultiScale(img, found, weights);

    /// draw detections and store location
    for (size_t i = 0; i < found.size(); i++) {
      Rect r = found[i];
      rectangle(img, found[i], cv::Scalar(0, 0, 255), 3);
      stringstream temp;
      temp << weights[i];
      putText(img, temp.str(), Point(found[i].x, found[i].y + 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));
      track.push_back(Point(found[i].x + found[i].width / 2, found[i].y + found[i].height / 2));
    }

    /// plot the track so far
    // for (size_t i = 1; i < track.size(); i++) {
    //   line(img, track[i - 1], track[i], Scalar(255, 255, 0), 2);
    // }

    /// Show
    cv::namedWindow("detected person", cv::WINDOW_AUTOSIZE);
    imshow("detected person", img);
    waitKey(0);
    destroyWindow("detected person");
  // }

  return 0;
}


//
// Created by narrow on 2021/10/21.
//
#include "test.h"

using namespace cv;

int main(){
    // input stream
    VideoCapture capture = VideoCapture(0);
    capture.set(CAP_PROP_FPS, 30);
    capture.set(CAP_PROP_SATURATION, 30);
    capture.set(CAP_PROP_HUE, 10);
    capture.set(CAP_PROP_CONTRAST, 50);
    LOG_IF(INFO, capture.isOpened()) << "Camera Not Open!";
    sleep(1);
    // image
    Mat frame;
    // detector
    QRCodeDetector detector;
    vector<Point2f> points;
    // solve Solver
    auto solver = Solver();
    // qrcode size (mm)
    constexpr float width = 40;
    constexpr float height = 40;
    // qrcode pose
    Pose pose;
    // key
    int key;
    while(true){
        capture >> frame;
        if(frame.empty()) break;
        detector.detect(frame, points);
        if(points.size() != 4) {
            goto show_image;
        }

//        for(const auto& p: points){
//            cout << p << " ";
//        }
//        cout << endl;

        pose = solver.solve(points, width, height);
        if(waitKey(1) == 's'){
            imwrite("../utils/"+ to_string(clock()) + ".png", frame);
        }
        draw(frame, points);
        for(int i=0;i<4;i++)
            putText(frame, to_string(i), points[i], FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255));
        putText(frame, to_string(pose.yaw), points[0], FONT_HERSHEY_COMPLEX, 1, Scalar(0, 255, 0));
        putText(frame, to_string(pose.t.x), points[3], FONT_HERSHEY_COMPLEX, 1, Scalar(0, 255, 0));
show_image:
        imshow("frame", frame);
        if(waitKey(1) == 'q'){
            break;
        }
    }
}
//
// Created by narrow on 2021/10/23.
//

//
// Created by narrow on 2021/10/21.
//
#include "test.h"

using namespace cv;

int main(){
    // input stream
//    VideoCapture capture = VideoCapture(0);
//    LOG_IF(INFO, capture.isOpened()) << "Camera Not Open!";
//    sleep(1);
    // image
//    Mat frame;
    // detector
//    QRCodeDetector detector;
    vector<Point2f> points;
    // solve Solver
    auto solver = Solver();
    // qrcode size (mm)
    constexpr float width = 50;
    constexpr float height = 50;
    // qrcode pose
    Pose pose;
    // step test
    constexpr float w = 640;
    constexpr float h = 480;
    constexpr int step = 6;
//    for(int s=0;s<step;s++){
//        float x = 1.0f*s*w/2/6;
//        float y = 1.0f*s*h/2/6;
//        float ww = w-1.0f*s*w/6;
//        float hh = h-1.0f*s*h/6;
//        points = {{x, y}, {x+ww, y}, {x+ww, y+hh}, {x, y+hh}};
//        pose = solver.solve(points, width, height);
//        cout << pose << endl;
//    }

//    float X = 50;
//    float Y = 50;
//    float ww = 50;
//    float hh = 50;
//    for(int i=0;i<100;i++){
//        float x = X+(i-50)*1.0f/100;
//        float y = Y+(i-50)*1.0f/100;
//        points = {{x, y}, {x+ww, y}, {x+ww, y+hh}, {x, y+hh}};
//        pose = solver.solve(points, width, height);
//        cout << pose << endl;
//    }

    float X = 50;
    float Y = 50;
    float W = 50;
    float H = 50;
    for(int i=0;i<100;i++){
        float x = X;
        float y = Y;
        float ww = W+(i-50)*1.0f/100;
        float hh = H+(i-50)*1.0f/100;
        points = {{x, y}, {x+ww, y}, {x+ww, y+hh}, {x, y+hh}};
        pose = solver.solve(points, width, height);
        cout << pose << endl;
    }
}
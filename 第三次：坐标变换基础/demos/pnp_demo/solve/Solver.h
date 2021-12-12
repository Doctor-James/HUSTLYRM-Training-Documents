//
// Created by narrow on 2021/10/21.
//

#ifndef PNP_DEMO_SOLVER_H
#define PNP_DEMO_SOLVER_H


#include <Eigen/Eigen>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include <fstream>
#include <vector>
#include <sophus/se3.h>
#include <sophus/so3.h>


#include "../log/Logger.h"

using namespace cv;
using namespace std;
using namespace Eigen;
using namespace Sophus;

class Pose{
public:

    Point3f t;
    double yaw;

    friend ostream& operator<<(ostream& out, const Pose& pose){
        out << pose.t << " " << pose.yaw << endl;
        return out;
    }
};

class Solver {
public:
    Solver();
    ~Solver() = default;
    Pose solve(const vector<Point2f> &points_2d, const float &width, const float &height);

private:
    Mat R;
    Mat tvec;
    Mat rvec;
    Mat cameraMatrix;
    Mat distCoeffs;

    Matrix3d e_R;
    Vector3d e_T;

    SE3 qrcode;
    SE3 qrcode_to_cam;
    SE3 cam_to_world;

    Pose pose;
};


#endif //PNP_DEMO_SOLVER_H

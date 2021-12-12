//
// Created by narrow on 2021/10/21.
//
#include "Solver.h"

using namespace std;

Solver::Solver() {
    cameraMatrix = (Mat_<double>(3, 3) << 570.8688, 0, 340.4646,
                                                    0, 573.1973, 247.6918,
                                                    0, 0, 1);
    // k1 k2 p1 p2 k3
    distCoeffs = (Mat_<double>(5, 1) << 0.0214,-0.1163,0.0029,-0.0010,0.1087);

    cam_to_world = SE3(Matrix3d::Identity(), Vector3d(-100, -100, 0));
}

Pose Solver::solve(const vector<Point2f> &points_2d, const float &width, const float &height) {

    // 1 0
    // 2 3
    static const vector<Point3f> points_3d = {
            {-width/2, -height/2, 0},
            {width/2, -height/2, 0},
            {width/2, height/2, 0},
            {-width/2, height/2, 0},
    };
    solvePnP(points_3d, points_2d,
             cameraMatrix, distCoeffs,
             rvec, tvec,
             false, SOLVEPNP_ITERATIVE);

    Rodrigues(rvec, R);
//    LOG(INFO) << R;
    double theta_z = atan2(R.at<double>(1, 0), R.at<double>(0, 0))/M_PI*180;
    double theta_x = atan2(R.at<double>(2, 1), R.at<double>(2, 2))/M_PI*180;
    double theta_y = atan2(-R.at<double>(2, 0),
                        sqrt(pow(R.at<double>(2, 0), 2) + pow(R.at<double>(2, 2), 2)))/M_PI*180;
    Point3f t(tvec);
    LOG(INFO) << "yaw: " << theta_y << " pitch: " << theta_x << " roll: " << theta_z;
    LOG(INFO) << t;
//    fstream file("../utils/points.txt", ios::in | ios::out | ios::app);
//    file << t.x << " " << t.y << " " << t.z << " " << theta_y << endl;

    cv2eigen(tvec, e_T);
    cv2eigen(R, e_R);
    qrcode_to_cam = SE3(e_R, e_T);

    const static SE3 qrcode = SE3(Matrix3d::Identity(), Vector3d(0, 0, 0));
    SE3 qrcode_in_cam = qrcode*qrcode_to_cam;
    SE3 qrcode_in_world = qrcode_in_cam*cam_to_world;

    Mat trans;
    eigen2cv(qrcode_in_world.translation(), trans);
    pose.t = Point3f(trans);
    pose.yaw = theta_y;

    return pose;
}

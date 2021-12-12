//
// Created by narrow on 2021/10/21.
//

#ifndef PNP_DEMO_TEST_H
#define PNP_DEMO_TEST_H

#include "opencv2/opencv.hpp"
#include <unistd.h>
#include "zbar.h"

#include "log/Logger.h"
#include "solve/Solver.h"

#define draw(img, points) \
    for(int i=0;i<points.size();i++)\
        line(img, points[i], points[(i+1)%points.size()], Scalar(0, 0, 255), 2)
#endif //PNP_DEMO_TEST_H

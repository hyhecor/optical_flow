//
// Created by h on 19. 6. 18.
//

#ifndef OPTFLOW_RUN_H
#define OPTFLOW_RUN_H

#ifdef __cplusplus

#include <opencv2/opencv.hpp>
#include <opencv2/optflow.hpp>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/ocl.hpp>
//#include <opencv2/core/core_c.h>
//#include <opencv2/imgproc/imgproc_c.h>
//#include <opencv2/videoio/videoio_c.h>
//#include <opencv2/highgui/highgui_c.h>


#include <iostream>

extern "C" {
#endif

#include "../../core.h"
#include "../opticalflow/dual_tvl1_optical_flow.h"
#include "../opticalflow/dense_optical_flow.h"

void run(char *argv[]);
void split(char *argv[]);

#ifdef __cplusplus
}
#endif

#endif //OPTFLOW_RUN_H

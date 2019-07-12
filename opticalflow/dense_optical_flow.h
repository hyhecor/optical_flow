//
// Created by h on 19. 7. 11.
//

#ifndef _OPTICALFLOW_DENSE_OPTICAL_FLOW_H
#define _OPTICALFLOW_DENSE_OPTICAL_FLOW_H

#ifdef __cplusplus

#include <opencv2/opencv.hpp>
#include <opencv2/optflow.hpp>

#include <opencv2/core.hpp>


#include <iostream>

extern "C" {
#endif

#include "../../../core.h"


#ifdef __cplusplus
typedef cv::Ptr<cv::DenseOpticalFlow>* DenseOpticalFlow;
#else
typedef void* DenseOpticalFlow;
#endif


// flow is Mat same size of i0 and fix type CV_32FC2
void DenseOpticalFlow_calc(DenseOpticalFlow m, Mat i0, Mat i1, Mat flow);

void DenseOpticalFlow_calc_gpu(DenseOpticalFlow m, Mat i0, Mat i1, Mat flow);


#ifdef __cplusplus
}
#endif

#endif //_OPTICALFLOW_DENSE_OPTICAL_FLOW_H

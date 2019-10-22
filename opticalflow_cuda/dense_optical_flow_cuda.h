//
// Created by h on 19. 7. 11.
//

#ifndef _OPTICALFLOW_CUDA_DENSE_OPTICAL_FLOW_H
#define _OPTICALFLOW_CUDA_DENSE_OPTICAL_FLOW_H

#ifdef __cplusplus

#include <opencv2/opencv.hpp>
#include <opencv2/cudaoptflow.hpp>

#include <opencv2/core.hpp>


#include <iostream>

extern "C" {
#endif

#include "../../../core.h"
#include "../../../cuda/cuda.h"


#ifdef __cplusplus
typedef cv::Ptr<cv::cuda::DenseOpticalFlow>* DenseOpticalFlow_cuda;
#else
typedef void* DenseOpticalFlow_cuda;
#endif

// flow is Mat same size of i0 and fix type CV_32FC2
void DenseOpticalFlow_calc_cuda(DenseOpticalFlow_cuda algorithm, Mat i0, Mat i1, Mat flow);

void DenseOpticalFlow_close_cuda(DenseOpticalFlow_cuda algorithm);

#ifdef __cplusplus
}
#endif

#endif //_OPTICALFLOW_CUDA_DENSE_OPTICAL_FLOW_H

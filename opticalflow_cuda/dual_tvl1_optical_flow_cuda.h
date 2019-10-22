#ifndef _OPTICALFLOW_CUDA_DUAL_TVL1_OPTICAL_FLOW_H
#define _OPTICALFLOW_CUDA_DUAL_TVL1_OPTICAL_FLOW_H

#ifdef __cplusplus

#include <opencv2/opencv.hpp>
#include <opencv2/cudaoptflow.hpp>

#include <opencv2/core.hpp>


#include <iostream>

extern "C" {
#endif

#include "../../../core.h"
//#include "../../../cuda/cuda.h"
#include "dense_optical_flow_cuda.h"


#ifdef __cplusplus
typedef cv::Ptr<cv::cuda::OpticalFlowDual_TVL1>* DualTVL1OpticalFlow_cuda;
#else
typedef void* DualTVL1OpticalFlow_cuda;
#endif

#ifdef __cplusplus
DenseOpticalFlow_cuda DualTVL1OpticalFlow_create_cuda(double tau = 0.25,
                                                      double lambda = 0.15,
                                                      double theta = 0.3,
                                                      int nscales = 5,
                                                      int warps = 5,
                                                      double epsilon = 0.01,
                                                      int iterations = 300,
                                                      double scaleStep = 0.8,
                                                      double gamma = 0.0,
                                                      bool useInitialFlow = false);


#else
DenseOpticalFlow_cuda DualTVL1OpticalFlow_create_cuda(double tau /*= 0.25*/,
                                            double lambda /*= 0.15*/,
                                            double theta /*= 0.3*/,
                                            int nscales /*= 5*/,
                                            int warps /*= 5*/,
                                            double epsilon /*= 0.01*/,
                                            int iterations /*= 300*/,
                                            double scaleStep /*= 0.8*/,
                                            double gamma /*= 0.0*/,
                                            bool useInitialFlow /*= false*/);

#endif


#ifdef __cplusplus
}
#endif

#endif //_OPTICALFLOW_CUDA_DUAL_TVL1_OPTICAL_FLOW_H

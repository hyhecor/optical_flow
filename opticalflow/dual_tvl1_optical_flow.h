#ifndef _OPTICALFLOW_DUAL_TVL1_OPTICAL_FLOW_H
#define _OPTICALFLOW_DUAL_TVL1_OPTICAL_FLOW_H

#ifdef __cplusplus

#include <opencv2/opencv.hpp>
#include <opencv2/optflow.hpp>

#include <opencv2/core.hpp>


#include <iostream>

extern "C" {
#endif

#include "../../../core.h"
#include "dense_optical_flow.h"


#ifdef __cplusplus
typedef cv::Ptr<cv::optflow::DualTVL1OpticalFlow>* DualTVL1OpticalFlow;
#else
typedef void* DualTVL1OpticalFlow;
#endif

// TVL1 create
DenseOpticalFlow createOptFlow_DualTVL1();

#ifdef __cplusplus
DenseOpticalFlow DualTVL1OpticalFlow_create(double tau = 0.25,
                                            double lambda = 0.15,
                                            double theta = 0.3,
                                            int nscales = 5,
                                            int warps = 5,
                                            double epsilon = 0.01,
                                            int innnerIterations = 30,
                                            int outerIterations = 10,
                                            double scaleStep = 0.8,
                                            double gamma = 0.0,
                                            int medianFiltering = 5,
                                            bool useInitialFlow = false);
#else
DenseOpticalFlow DualTVL1OpticalFlow_create(double tau /*= 0.25*/,
                                            double lambda /*= 0.15*/,
                                            double theta /*= 0.3*/,
                                            int nscales /*= 5*/,
                                            int warps /*= 5*/,
                                            double epsilon /*= 0.01*/,
                                            int innnerIterations /*= 30*/,
                                            int outerIterations /*= 10*/,
                                            double scaleStep /*= 0.8*/,
                                            double gamma /*= 0.0*/,
                                            int medianFiltering /*= 5*/,
                                            bool useInitialFlow /*= false*/);
#endif


#ifdef __cplusplus
}
#endif

#endif //_OPTICALFLOW_DUAL_TVL1_OPTICAL_FLOW_H

#include "dual_tvl1_optical_flow_cuda.h"

DenseOpticalFlow_cuda DualTVL1OpticalFlow_create_cuda(double tau /*= 0.25*/,
                                                      double lambda /*= 0.15*/,
                                                      double theta /*= 0.3*/,
                                                      int nscales /*= 5*/,
                                                      int warps /*= 5*/,
                                                      double epsilon /*= 0.01*/,
                                                      int iterations /*= 300*/,
                                                      double scaleStep /*= 0.8*/,
                                                      double gamma /*= 0.0*/,
                                                      bool useInitialFlow /*= false*/) {

    auto foo =  cv::cuda::OpticalFlowDual_TVL1::create(
            tau, lambda, theta, nscales, warps,
            epsilon, iterations, scaleStep, gamma, useInitialFlow);

    return new cv::Ptr<cv::cuda::DenseOpticalFlow>(foo);
}


#include "dual_tvl1_optical_flow.h"


DenseOpticalFlow createOptFlow_DualTVL1() {
    return new cv::Ptr<cv::DenseOpticalFlow>(cv::optflow::createOptFlow_DualTVL1());
}

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
                                            bool useInitialFlow /*= false*/) {
    return new cv::Ptr<cv::DenseOpticalFlow>(cv::optflow::DualTVL1OpticalFlow::create(
            tau, lambda, theta, nscales, warps,
            epsilon, innnerIterations, outerIterations, scaleStep, gamma,
            medianFiltering, useInitialFlow));
}

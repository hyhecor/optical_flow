//
// Created by h on 19. 7. 11.
//

#include "dense_optical_flow.h"

void DenseOpticalFlow_calc(DenseOpticalFlow algorithm, Mat i0, Mat i1, Mat flow) {
    (*algorithm)->calc(*i0, *i1, *flow);
    return;
}

void DenseOpticalFlow_calc_gpu(DenseOpticalFlow algorithm, Mat i0, Mat i1, Mat flow) {
    (*algorithm)->calc(*i0, *i1, flow->getUMat(cv::ACCESS_MASK));
    return;
}

void DenseOpticalFlow_close(DenseOpticalFlow algorithm) {
    delete(algorithm);
}

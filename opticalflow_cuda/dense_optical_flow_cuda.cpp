//
// Created by h on 19. 7. 11.
//

#include "dense_optical_flow_cuda.h"


void DenseOpticalFlow_calc_cuda(DenseOpticalFlow_cuda algorithm, Mat i0, Mat i1, Mat flow) {

    cv::cuda::GpuMat* gmat0 = new cv::cuda::GpuMat();
    cv::cuda::GpuMat* gmat1 = new cv::cuda::GpuMat();
    cv::cuda::GpuMat* gmatflow = new cv::cuda::GpuMat();

    gmat0->upload(*i0);
    gmat1->upload(*i1);
    gmatflow->upload(*flow);

    (*algorithm)->calc(*gmat0, *gmat1, *gmatflow);


//    gmat0->download(*i0);
//    gmat1->download(*i1);
    gmatflow->download(*flow);

    gmat0->release();
    gmat1->release();
    gmatflow->release();

    return;
}

void DenseOpticalFlow_close_cuda(DenseOpticalFlow_cuda algorithm) {
    delete(algorithm);
}


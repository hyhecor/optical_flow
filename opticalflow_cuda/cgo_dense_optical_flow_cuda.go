package opticalflow_cuda

/*
#include <stdlib.h>
#include "dense_optical_flow_cuda.h"
#include "dual_tvl1_optical_flow_cuda.h"
*/
import "C"
import (
	"gocv.io/x/gocv"
)

type DenseOpticalFlowCuda struct {
	p C.DenseOpticalFlow_cuda
}

func (algorithm DenseOpticalFlowCuda) Ptr() C.DenseOpticalFlow_cuda {
	return algorithm.p
}

func (algorithm DenseOpticalFlowCuda) Calc(i0 gocv.Mat, i1 gocv.Mat, flow gocv.Mat) {

	C.DenseOpticalFlow_calc_cuda(C.DenseOpticalFlow_cuda(algorithm.Ptr()),
		C.Mat(i0.Ptr()), C.Mat(i1.Ptr()), C.Mat(flow.Ptr()))
	return
}

func (algorithm DenseOpticalFlowCuda) Close() {

	C.DenseOpticalFlow_close_cuda(C.DenseOpticalFlow_cuda(algorithm.Ptr()))
	return
}

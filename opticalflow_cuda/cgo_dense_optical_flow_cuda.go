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

type _DenseOpticalFlowCuda struct {
	p C.DenseOpticalFlow_cuda
}

func (algorithm _DenseOpticalFlowCuda) Ptr() C.DenseOpticalFlow_cuda {
	return algorithm.p
}

func (algorithm _DenseOpticalFlowCuda) Calc(i0 gocv.Mat, i1 gocv.Mat, flow gocv.Mat) {

	C.DenseOpticalFlow_calc_cuda(C.DenseOpticalFlow_cuda(algorithm.Ptr()),
		C.Mat(i0.Ptr()), C.Mat(i1.Ptr()), C.Mat(flow.Ptr()))

	return
}

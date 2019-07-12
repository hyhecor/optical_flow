package opticalflow

/*
#include <stdlib.h>
#include "dense_optical_flow.h"
#include "dual_tvl1_optical_flow.h"
*/
import "C"
import (
	"gocv.io/x/gocv"
)

type _DenseOpticalFlow struct {
	p C.DenseOpticalFlow
}

func (algorithm _DenseOpticalFlow) Ptr() C.DenseOpticalFlow {
	return algorithm.p
}

func (algorithm _DenseOpticalFlow) Calc(i0 gocv.Mat, i1 gocv.Mat, flow gocv.Mat) {
	C.DenseOpticalFlow_calc(C.DenseOpticalFlow(algorithm.Ptr()),
		C.Mat(i0.Ptr()), C.Mat(i1.Ptr()), C.Mat(flow.Ptr()))
	return
}

package opticalflow_cuda

/*
#include <stdlib.h>
#include "dense_optical_flow_cuda.h"
#include "dual_tvl1_optical_flow_cuda.h"
*/
import "C"

//double Tau = 0.25,
//double Lambda = 0.15,
//double Theta = 0.3,
//int Nscales = 5,
//int Warps = 5,
//double Epsilon = 0.01,
//int Iterations = 300,
//double ScaleStep = 0.8,
//double Gamma = 0.0,
//bool UseInitialFlow = false
type _DualTVL1OptionCuda struct {
	Tau            float64 //0.25
	Lambda         float64 //0.15
	Theta          float64 //0.3
	Nscales        int     //5
	Warps          int     //5
	Epsilon        float64 //0.01
	Iterations     int     //300
	ScaleStep      float64 //0.8
	Gamma          float64 //0.0
	UseInitialFlow bool    //false
}

func NewDualTVL1Option() _DualTVL1OptionCuda {
	return _DualTVL1OptionCuda{
		Tau:            0.25,
		Lambda:         0.15,
		Theta:          0.3,
		Nscales:        5,
		Warps:          5,
		Epsilon:        0.01,
		Iterations:     300,
		ScaleStep:      0.8,
		Gamma:          0.0,
		UseInitialFlow: false,
	}
}

func DualTVL1OpticalFlowCreate(ops ..._DualTVL1OptionCuda) _DenseOpticalFlowCuda {

	var op _DualTVL1OptionCuda = NewDualTVL1Option()
	if len(ops) > 0 {
		op = ops[0]
	}

	return _DenseOpticalFlowCuda{
		p: C.DualTVL1OpticalFlow_create_cuda(
			C.double(op.Tau),
			C.double(op.Lambda),
			C.double(op.Theta),
			C.int(op.Nscales),
			C.int(op.Warps),
			C.double(op.Epsilon),
			C.int(op.Iterations),
			C.double(op.ScaleStep),
			C.double(op.Gamma),
			C.bool(op.UseInitialFlow),
		),
	}
}

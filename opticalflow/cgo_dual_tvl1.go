package opticalflow

/*
#include <stdlib.h>
#include "dense_optical_flow.h"
#include "dual_tvl1_optical_flow.h"
*/
import "C"

//double Tau = 0.25,
//double Lambda = 0.15,
//double Theta = 0.3,
//int Nscales = 5,
//int Warps = 5,
//double Epsilon = 0.01,
//int InnnerIterations = 30,
//int OuterIterations = 10,
//double ScaleStep = 0.8,
//double Gamma = 0.0,
//int MedianFiltering = 5,
//bool UseInitialFlow = false
type _DualTVL1Option struct {
	Tau              float64 //0.25
	Lambda           float64 //0.15
	Theta            float64 //0.3
	Nscales          int     //5
	Warps            int     //5
	Epsilon          float64 //0.01
	InnnerIterations int     //30
	OuterIterations  int     //10
	ScaleStep        float64 //0.8
	Gamma            float64 //0.0
	MedianFiltering  int     //5
	UseInitialFlow   bool    //false
}

func NewDualTVL1Option() _DualTVL1Option {
	return _DualTVL1Option{
		Tau:              0.25,
		Lambda:           0.15,
		Theta:            0.3,
		Nscales:          5,
		Warps:            5,
		Epsilon:          0.01,
		InnnerIterations: 30,
		OuterIterations:  10,
		ScaleStep:        0.8,
		Gamma:            0.0,
		MedianFiltering:  5,
		UseInitialFlow:   false,
	}
}

func DualTVL1OpticalFlowCreate(ops ..._DualTVL1Option) _DenseOpticalFlow {

	var op _DualTVL1Option = NewDualTVL1Option()
	if len(ops) == 0 {
		op = ops[0]
	}

	return _DenseOpticalFlow{
		p: C.DualTVL1OpticalFlow_create(
			C.double(op.Tau),
			C.double(op.Lambda),
			C.double(op.Theta),
			C.int(op.Nscales),
			C.int(op.Warps),
			C.double(op.Epsilon),
			C.int(op.InnnerIterations),
			C.int(op.OuterIterations),
			C.double(op.ScaleStep),
			C.double(op.Gamma),
			C.int(op.MedianFiltering),
			C.bool(op.UseInitialFlow),
		),
	}
}

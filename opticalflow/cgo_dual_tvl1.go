package opticalflow

/*
#include <stdlib.h>
#include "dense_optical_flow.h"
#include "dual_tvl1_optical_flow.h"
*/
import "C"

//τ		time step 0.25
//λ		data attachment weight 0.15
//θ		tightness 0.3
//ε		stopping threshold 0.01
//η		zoom factor 0.5
//Nscales	number of scales 5
//Nwarps	number of warps 5
type DualTVL1Option struct {
	//Time step of the numerical scheme.
	Tau float64 //0.25
	//Weight parameter for the data term, attachment parameter.
	//This is the most relevant parameter, which determines the smoothness of the output.
	//The smaller this parameter is, the smoother the solutions we obtain.
	//It depends on the range of motions of the images, so its value should be adapted to each image sequence.
	Lambda float64 //0.15
	//parameter used for motion estimation. It adds a variable allowing for illumination variations
	//Set this parameter to 1. if you have varying illumination.
	//See: Chambolle et al, A First-Order Primal-Dual Algorithm for Convex Problems with Applications to Imaging
	//Journal of Mathematical imaging and vision, may 2011 Vol 40 issue 1, pp 120-145
	Theta float64 //0.3
	//Number of scales used to create the pyramid of images.
	Nscales int //5
	//Number of warpings per scale.
	//Represents the number of times that I1(x+u0) and grad( I1(x+u0) ) are computed per scale.
	//This is a parameter that assures the stability of the method.
	//It also affects the running time, so it is a compromise between speed and accuracy.
	Warps int //5
	//Stopping criterion threshold used in the numerical scheme, which is a trade-off between precision and running time.
	//A small value will yield more accurate solutions at the expense of a slower convergence.
	Epsilon float64 //0.01
	//Stopping criterion iterations number used in the numerical scheme.
	InnnerIterations int     //30
	OuterIterations  int     //10
	ScaleStep        float64 //0.8
	//Weight parameter for (u - v)^2, tightness parameter.
	//It serves as a link between the attachment and the regularization terms.
	//In theory, it should have a small value in order to maintain both parts in correspondence.
	//The method is stable for a large range of values of this parameter.
	Gamma           float64 //0.0
	MedianFiltering int     //5
	UseInitialFlow  bool    //false
}

func NewDualTVL1Option() DualTVL1Option {
	return DualTVL1Option{
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

func DualTVL1OpticalFlowCreate(ops ...DualTVL1Option) DenseOpticalFlow {

	var op DualTVL1Option = NewDualTVL1Option()
	if len(ops) > 0 {
		op = ops[0]
	}

	return DenseOpticalFlow{
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

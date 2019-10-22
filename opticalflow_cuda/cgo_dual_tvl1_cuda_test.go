package opticalflow_cuda_test

import (
	"gocv.io/x/gocv"
	"gocv.io/x/gocv/contrib/optical_flow/opticalflow_cuda"
	"image"
	"testing"
)

/*
τ		time step 0.25
λ		data attachment weight 0.15
θ		tightness 0.3
ε		stopping threshold 0.01
η		zoom factor 0.5
Nscales	number of scales 5
Nwarps	number of warps 5
*/
func BenchmarkDenseOpticalFlow_cuda_Calc(b *testing.B) {


	i0 := gocv.IMRead("../img_00001.jpg", gocv.IMReadUnchanged)
	i1 := gocv.IMRead("../img_00002.jpg", gocv.IMReadUnchanged)

	gocv.Resize(i0, &i0, image.Point{300, 300}, 0, 0, gocv.InterpolationLinear)
	gocv.Resize(i1, &i1, image.Point{300, 300}, 0, 0, gocv.InterpolationLinear)

	gocv.CvtColor(i0, &i0, gocv.ColorBGRToGray)
	gocv.CvtColor(i1, &i1, gocv.ColorBGRToGray)

	flow := gocv.NewMatWithSize(i0.Rows(), i0.Cols(), gocv.MatTypeCV32F+gocv.MatChannels2)

//Tau:            0.25,
//Lambda:         0.15,
//Theta:          0.3,
//Nscales:        5,
//Warps:          5,
//Epsilon:        0.01,
//Iterations:     300,
//ScaleStep:      0.8,
//Gamma:          0.0,
//UseInitialFlow: false,
	op := opticalflow_cuda.NewDualTVL1Option()
	op.Tau = 0.25
	op.Lambda = 0.15
	op.Theta = 0.3/2
	op.Nscales = 5
	op.Warps = 5
	op.Epsilon = 0.01 *5
	op.Iterations = 300
	op.ScaleStep = 0.8
	op.Gamma = 0.0
	//op.UseInitialFlow = true

	optFlow := opticalflow_cuda.DualTVL1OpticalFlowCreate(op)
	defer optFlow.Close()

	for i := 0; i < b.N; i++ {
		optFlow.Calc(i0, i1, flow)
	}

}

func TestCreateDualTVL1OpticalFlow(t *testing.T) {
	optFlow := opticalflow_cuda.DualTVL1OpticalFlowCreate()
	defer optFlow.Close()

	t.Log(optFlow)

	i0 := gocv.IMRead("../img_00001.jpg", gocv.IMReadUnchanged)
	i1 := gocv.IMRead("../img_00002.jpg", gocv.IMReadUnchanged)

	gocv.CvtColor(i0, &i0, gocv.ColorBGRToGray)
	gocv.CvtColor(i1, &i1, gocv.ColorBGRToGray)

	flow := gocv.NewMatWithSize(i0.Rows(), i0.Cols(), gocv.MatTypeCV32F+gocv.MatChannels2)

	t.Log("flow.Type", flow.Type())

	optFlow.Calc(i0, i1, flow)

	//opticalflow.CalcGPU(i0, i1, &flow)
	//t.Log(flow)

	flowSplit := gocv.Split(flow)

	gocv.IMWrite("/tmp/TVL1_split_0.jpg", flowSplit[0])
	gocv.IMWrite("/tmp/TVL1_split_1.jpg", flowSplit[1])

	var (
		magnitude = gocv.NewMat()
		angle     = gocv.NewMat()
		hsv       = gocv.NewMat()
		rgb       = gocv.NewMat()
	)

	gocv.CartToPolar(flowSplit[0], flowSplit[1], &magnitude, &angle, true)
	gocv.Normalize(magnitude, &magnitude, 0, 1, gocv.NormMinMax)

	gocv.Merge([]gocv.Mat{
		angle,
		gocv.NewMatWithSize(angle.Rows(), angle.Cols(), angle.Type()),
		magnitude,
	}, &hsv)

	gocv.CvtColor(hsv, &rgb, gocv.ColorHSVToBGR)

	t.Log("hsv type=", rgb.Type(),
		"channels=", rgb.Channels(),
	)

	gocv.NewWindow("TVL1").IMShow(rgb)
	gocv.IMWrite("/tmp/TVL1_result.jpg", rgb)

	gocv.WaitKey(0)
}

func TestShowResultDualTVL1OpticalFlow(t *testing.T) {

	image := gocv.IMRead("/tmp/TVL1_result.jpg", gocv.IMReadUnchanged)

	t.Log("rgb type=", image.Type(),
		"channels=", image.Channels(),
	)

	gocv.NewWindow("TVL1").IMShow(image)

	gocv.WaitKey(0)
}

//
// Created by h on 19. 6. 18.
//

#include "app.h"


static cv::Mat flowToDisplay(const cv::Mat flow) {
    cv::Mat flow_split[2];
    cv::Mat magnitude, angle;
    cv::Mat hsv_split[3], hsv, rgb;
    cv::split(flow, flow_split);
    cv::cartToPolar(flow_split[0], flow_split[1], magnitude, angle, true);
    cv::normalize(magnitude, magnitude, 0, 1, cv::NORM_MINMAX);
    hsv_split[0] = angle; // already in degrees - no normalization needed
    hsv_split[1] = cv::Mat::ones(angle.size().height, angle.size().width, angle.type());
    hsv_split[2] = magnitude;
    cv::merge(hsv_split, 3, hsv);
    cv::cvtColor(hsv, rgb, cv::COLOR_HSV2BGR);


//    cv::imshow("0", flow_split[0]);
//    cv::imshow("1", flow_split[1]);

    if (cv::waitKey(1) == 'q') {

    }

    return rgb;
}


void split(char *argv[]) {


    Mat pre = Mat_New();
    Mat now = Mat_New();

    *pre = cv::imread(argv[0]);
    *now = cv::imread(argv[1]);


    cv::cvtColor(*pre, *pre, cv::COLOR_BGR2GRAY);
    cv::cvtColor(*now, *now, cv::COLOR_BGR2GRAY);

    Mat flow = Mat_New();
    *flow = cv::Mat::ones((*pre).rows, (*pre).cols, (*pre).type());


    DenseOpticalFlow_cuda optflow = DualTVL1OpticalFlow_create_cuda();

    DenseOpticalFlow_calc_cuda(optflow, pre, now, flow);

    cv::Mat flow_split[2];
    cv::split(*flow, flow_split);

    cv::imwrite("/tmp/TVL1_split_0.jpg", flow_split[0]);
    cv::imwrite("/tmp/TVL1_split_1.jpg", flow_split[1]);

    cv::imshow("TVL1_split_0", flow_split[0]);
    cv::imshow("TVL1_split_1", flow_split[1]);
    cv::waitKey(0);
}


void run(char *argv[]) {

    if (cv::ocl::haveOpenCL()) {
        std::cout << "Use OpenCL" << std::endl;
        cv::ocl::setUseOpenCL(true);
        std::cout << "OpenCLVersion=" << cv::ocl::Device::getDefault().OpenCLVersion() << std::endl;
    }

    DenseOpticalFlow_cuda optflow = DualTVL1OpticalFlow_create_cuda();


    Mat pre = Mat_New();
    Mat now = Mat_New();

    cv::VideoCapture cap(argv[2]);

    if (!cap.isOpened()) {
        return;
    }

    cap >> *pre;

    cv::resize(*pre, *pre, cv::Size(300, 200));
    cv::cvtColor(*pre, *pre, cv::COLOR_BGR2GRAY);

    int count = 0;

    for (;;) {
        count++;
        cap >> *now;

        cv::resize(*now, *now, cv::Size(300, 200));
        cv::cvtColor(*now, *now, cv::COLOR_BGR2GRAY);

        Mat flow = Mat_NewWithSize(Mat_Rows(pre), Mat_Cols(pre), CV_32FC2);


        std::cout << "CV_32FC2=" << CV_32FC2 << std::endl;


        cv::imshow("origin", *now);

            DenseOpticalFlow_calc_cuda(optflow, pre, now, flow);

//        cv::imshow("0", *pre);
//        cv::imshow("1", *now);
//
//        if (cv::waitKey(0) == 'q') {
//            break;
//        }

        cv::Mat flow_image = flowToDisplay(*flow);

        printf("%d \n", count);


        cv::imshow("2", flow_image);

        if (cv::waitKey(1) == 'q') {
            break;
        }

        //Mat_Close(flow_image);
        Mat_Close(flow);


        pre = Mat_Clone(now);

    }


    printf("0x%p\n", optflow);


    Mat_Close(now);
    Mat_Close(pre);

    DenseOpticalFlow_close_cuda(optflow);

}
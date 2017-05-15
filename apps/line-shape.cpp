#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

#include "../stasm/stasm_lib.h"
#include "../stasm/stasm_landmarks.h"
#include "stasm.h"
#include "appmisc.h"

static const stasm::Shape AsShape(const float* landmarks);

static const char* path = "./img.jpg";
cv::VideoCapture cap(0);
int foundface;
float landmarks[2 * stasm_NLANDMARKS];

static const stasm::Shape AsShape( // return a Shape
    const float* landmarks)          // in
{
    stasm::Shape shape(stasm_NLANDMARKS, 2);
    for (int i = 0; i < stasm_NLANDMARKS; i++)
    {
        shape(i, stasm::IX) = landmarks[i*2];
        shape(i, stasm::IY) = landmarks[i*2+1];
    }
    return shape;
}

int main(int argc, char** argv)
{
	cv::Mat_<unsigned char> img, frame;

	if(!cap.isOpened())
	{
		std::cout<<"camera is not opened";
		system("PAUSE");
		return -1;
	}
		while(1)
	{
        cap >> img; // get a new frame from camera
		cv::cvtColor(img, frame, CV_BGR2GRAY);

		if(!frame.data)
		{
			std::cout<<"No image loaded";
			system("PAUSE");
			return -1;
			
		}
		if(!stasm_search_single(&foundface, landmarks, (const char*)frame.data, frame.cols, frame.rows, path, "../data"))
		{
			std::cout<<"stasm_search_single failed"<<std::endl;
			continue;
		}

        if (!foundface)
			continue;

		stasm::CImage cimg;     // color version of image
		cvtColor(frame, cimg, CV_GRAY2BGR);
		stasm::Shape shape(AsShape(landmarks));
		stasm::DrawShape(cimg, shape);

		cv::imshow("camera", cimg);
        if(cv::waitKey(1) >= 0) break;
	}

	return 0;
}
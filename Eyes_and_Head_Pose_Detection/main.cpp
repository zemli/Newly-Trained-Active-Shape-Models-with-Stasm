#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <windows.h>
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include "../stasm/stasm_lib.h"
#include "../stasm/stasm_landmarks.h"
#include <time.h>


float landmarks[2 * stasm_NLANDMARKS]; // x,y coords (note the 2)
float leye[10], reye[10];
float lbrow[10], rbrow[10];
int eyeclosecount = 0;
long count;

void checkEye();
float averageDist(float* arr, int size);
void checkHead();
void welcomeScreen();
void printInstruction();


void checkEye()
{
	if((landmarks[150*2+1] - landmarks[140*2+1]) <= leye[0] * 0.77)
	{
		if((landmarks[130*2+1] - landmarks[120*2+1]) <= reye[0] * 0.77)
		{
			if(eyeclosecount++ % 80 == 0)
			{
				std::cout<<"eyes closed___\n";
				Beep(1500,600);
			}
		}
	}
	else if(eyeclosecount > 1)
	{
		eyeclosecount = 0;
	}
}

void checkHead()
{
	if((landmarks[139*2+1] - landmarks[169*2+1]) <= lbrow[0] * 0.8)
	{
		if((landmarks[119*2+1] - landmarks[189*2+1]) <= rbrow[0] * 0.8)
		{
			std::cout<<"head rotated___\n";
			Beep(600,200);
			Beep(600,400);
		}
	}
}

float averageDist(float* arr, int size)
{
	float sum = 0;
	std::sort(arr, arr + size);
	for(int i = 1;i < size - 1;i++) //ignore max and min
	{
		sum += arr[i];
	}
	return sum/(size - 2);
}

void welcomeScreen()
{
	char choice = ' ';

	std::cout<<"Realtime closed eyes and head pose detection.\n";
	std::cout<<"University of Toronto\nZeming Li\n";
	std::cout<<"Please face to the webcam. The program will record your facial features.\n";
	std::cout<<"press y to continue, n to quit. [y/n]\n";
	while(choice != 'y')
	{
		std::cin>>choice;
		if(choice == 'n')
		{
			std::cout<<"ends\n";
			system("pause");
			exit(0);
		}
	}
}

void printInstruction()
{
	std::cout<<"Please stay in place, and face to the webcam.\n";
	std::cout<<"Try not to blink until you hear a beep.\n";
	system("pause");
}

int main(int argc, char** argv)
{
	welcomeScreen();

	static const char* path = "img.jpg";
	cv::VideoCapture cap(0);
	if(!cap.isOpened())
	{
		std::cout<<"camera is not opened";
		system("pause");
		return -1;
	}
	int foundface;
	
	std::cout<<"stage 1\n";
	printInstruction();
	int loop = 10; //get 10 samples, the arrays lengths are 10
	for(int i=0; i < loop; i++)
	{
		std::cout<<loop - i<<"\n";
		cv::Mat_<unsigned char> img, frame, output;
        cap >> img; // get a new frame from camera
		cv::cvtColor(img, frame, CV_BGR2GRAY);

		if(!frame.data)
		{
			std::cout<<"No image loaded";
			system("pause");
			return -1;
		}
		//cv::imwrite( path, frame );

		if(!stasm_search_single(&foundface, landmarks, (const char*)frame.data, frame.cols, frame.rows, path, "../data"))
		{
			std::cout<<"stasm_search_single failed";
			system("pause");
			return -1;
		}

        if (!foundface)
		{
			std::cout<<"No face found\n";
			i--;
		}
		stasm_force_points_into_image(landmarks,frame.cols, frame.rows);
		for(int l = 0; l < stasm_NLANDMARKS; l++)
			frame(cvRound(landmarks[l*2+1]), cvRound(landmarks[l*2])) = 255;

		leye[i] = landmarks[150*2+1] - landmarks[140*2+1];
		reye[i] = landmarks[130*2+1] - landmarks[120*2+1];
		lbrow[i] = landmarks[139*2+1] - landmarks[169*2+1];
		rbrow[i] = landmarks[119*2+1] - landmarks[189*2+1];
		

		cv::flip(frame, output, 1);//mirror output
		cv::imshow("camera", output);
        if(cv::waitKey(30) >= 0) break;
	}

	Beep(523,500);
	leye[0] = averageDist(leye, loop);
	reye[0] = averageDist(reye, loop);
	lbrow[0] = averageDist(lbrow, loop);
	rbrow[0] = averageDist(rbrow, loop);

	//std::cout<<leye[0]<<"\n";
	//std::cout<<reye[0]<<"\n";
	//std::cout<<lbrow[0]<<"\n";
	//std::cout<<rbrow[0]<<"\n";
	std::cout<<"standard facial features obtained"<<std::endl;

	std::cout<<"stage 2"<<"\n";
	std::cout<<"start detecting"<<"\n";

	cv::Mat_<unsigned char> img, frame, output;
	//time_t start, end;
	//time(&start);
	while(1)
	{
		
        cap >> img; // get a new frame from camera
		cv::cvtColor(img, frame, CV_BGR2GRAY);

		if(!frame.data)
		{
			std::cout<<"No image loaded";
			system("pause");
			return -1;
		}

		if(!stasm_search_single(&foundface, landmarks, (const char*)frame.data, frame.cols, frame.rows, path, "../data"))
		{
			std::cout<<"stasm_search_single failed";
			system("pause");
			return -1;
		}

        if (!foundface)
			std::cout<<"No face found\n";
		stasm_force_points_into_image(landmarks,frame.cols, frame.rows);
		for(int i = 0; i < stasm_NLANDMARKS; i++)
			frame(cvRound(landmarks[i*2+1]), cvRound(landmarks[i*2])) = 255;

		checkEye();
		checkHead();
		count++;
		cv::flip(frame, output, 1);//mirror output
		cv::imshow("camera", output);
        if(cv::waitKey(30) >= 0) break;
	}
	/*
	time(&end);
	double seconds = difftime (end, start);
	double fps = count/seconds;
	std::cout<<"End"<<std::endl;
	std::cout<<"FPS is "<<fps<<std::endl;
	system("pause");
	*/
	return 0;
}

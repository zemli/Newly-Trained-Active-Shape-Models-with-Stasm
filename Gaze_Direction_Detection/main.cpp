
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include "../stasm/stasm_lib.h"
#include "../stasm/stasm_landmarks.h"

float xl[4];
float yl[4];
float xr[4];
float yr[4];
unsigned int count[100];
float normc[100];

static const char* path = "./img.jpg";
cv::VideoCapture cap(0);
int foundface;
float landmarks[2 * stasm_NLANDMARKS];
RECT rect = {0};
cv::Mat_<unsigned char> screen, bg;

float distance(float ax, float ay, float cx, float cy);
float averageVal(float* arr, int size);
void getGazePos();
int getNewCoord(int num);
float getOXL();
float getOYL();
float getOXR();
float getOYR();
float getRatio(char choice);
void countRect(float rx, float ry);
void drawbg(int x, int y);
void normalizeCount();


int capstureScreen(){
	std::cout<<"Realtime reading habits monitor"<<std::endl;
	std::cout<<"Zeming Li"<<std::endl;
	std::cout<<"University of Toronto"<<std::endl;
	std::cout<<"__________________________________"<<std::endl;
	std::cout<<"please make the window on top"<<std::endl;
	system("pause");
	cv::Mat hwnd2mat(HWND hwnd);
	HWND hwndDesktop = GetDesktopWindow();
	cv::Mat screen2 = hwnd2mat(hwndDesktop);
	cv::cvtColor(screen2, screen, CV_BGR2GRAY);
	//cv::imshow("input", screen);
	//cv::waitKey(0);
	std::cout<<"Screen captured"<<std::endl;
	return 0;
}

float distance(float ax, float ay, float cx, float cy)
{
	return sqrt(pow(abs(ax - cx),2) + pow(abs(ay - cy),2));
}

float averageVal(float* arr, int size)
{
	double sum = 0;
	std::sort(arr, arr + size);
	for(int i = 1;i < size - 1;i++) 
	{
		sum += arr[i];
	}
	return (float)sum/(float)(size - 2);
}

cv::Mat hwnd2mat(HWND hwnd){

    HDC hwindowDC,hwindowCompatibleDC;

    int height,width,srcheight,srcwidth;
    HBITMAP hbwindow;
    cv::Mat src;
    BITMAPINFOHEADER  bi;

    hwindowDC=GetDC(hwnd);
    hwindowCompatibleDC=CreateCompatibleDC(hwindowDC);
    SetStretchBltMode(hwindowCompatibleDC,COLORONCOLOR);  

    RECT windowsize;    // get the height and width of the screen
    GetClientRect(hwnd, &windowsize);

    srcheight = windowsize.bottom;
    srcwidth = windowsize.right;
    height = windowsize.bottom/2;  //change this to whatever size you want to resize to
    width = windowsize.right/2;

    src.create(height,width,CV_8UC4);

    // create a bitmap
    hbwindow = CreateCompatibleBitmap( hwindowDC, width, height);
    bi.biSize = sizeof(BITMAPINFOHEADER);   
    bi.biWidth = width;    
    bi.biHeight = -height;  //this is the line that makes it draw upside down or not
    bi.biPlanes = 1;    
    bi.biBitCount = 32;    
    bi.biCompression = BI_RGB;    
    bi.biSizeImage = 0;  
    bi.biXPelsPerMeter = 0;    
    bi.biYPelsPerMeter = 0;    
    bi.biClrUsed = 0;    
    bi.biClrImportant = 0;

    // use the previously created device context with the bitmap
    SelectObject(hwindowCompatibleDC, hbwindow);
    // copy from the window device context to the bitmap device context
    StretchBlt( hwindowCompatibleDC, 0,0, width, height, hwindowDC, 0, 0,srcwidth,srcheight, SRCCOPY); //change SRCCOPY to NOTSRCCOPY for wacky colors !
    GetDIBits(hwindowCompatibleDC,hbwindow,0,height,src.data,(BITMAPINFO *)&bi,DIB_RGB_COLORS);  //copy from hwindowCompatibleDC to hbwindow

    return src;
}


float getOXL()
{
	return ((landmarks[33*2]+landmarks[37*2])/2 + (landmarks[31*2]+landmarks[35*2])/2)/2;
}

float getOXR()
{
	return ((landmarks[41*2]+landmarks[45*2])/2 + (landmarks[43*2]+landmarks[47*2])/2)/2;
}

float getOYL()
{
	return ((landmarks[33*2+1]+landmarks[37*2+1])/2 + (landmarks[31*2+1]+landmarks[35*2+1])/2)/2;
}

float getOYR()
{
	return ((landmarks[41*2+1]+landmarks[45*2+1])/2 + (landmarks[43*2+1]+landmarks[47*2+1])/2)/2;
}

float getRatio(char choice)
{
	switch(choice)
	{
		case 'X':
			return (landmarks[38*2] - getOXL() - xl[0])/(xl[2] - xl[3]) + (landmarks[39*2] - getOXR() - xr[0])/(xr[2] - xr[3]);
			break;
		case 'Y':
			return abs((landmarks[38*2+1] - getOYL() - yl[0])/(yl[2] - yl[1]))*2.6 + abs((landmarks[39*2+1] - getOYR() - yr[0])/(yr[2] - yr[1]))*2.6;
			break;
		default:
			std::cout<<"Invalid choice"<<std::endl;
			return -1;
	}
}

void getGazePos()
{
	int x = 0;
	int y = 0;
	x = GetSystemMetrics(SM_CXSCREEN);
	y = GetSystemMetrics(SM_CYSCREEN);
	std::cout<<"please look at the cursor at top left"<<std::endl;
	SetCursorPos(0,0);
	system("pause");
	if(getNewCoord(0) != 0)
		exit(-1);
	Beep(523,500);
	std::cout<<"please look at the cursor at top right"<<std::endl;
	SetCursorPos((int)(x*0.99),0);
	Sleep(2000);
	if(getNewCoord(1) != 0)
		exit(-1);
	Beep(523,500);
	std::cout<<"please look at the cursor at bottom right"<<std::endl;
	SetCursorPos((int)(x*0.99),(int)(y*0.99));
	Sleep(2000);
	if(getNewCoord(2) != 0)
		exit(-1);
	Beep(523,500);
	std::cout<<"please look at the cursor at bottom left"<<std::endl;
	SetCursorPos(0,(int)(y*0.99));
	Sleep(2000);
	if(getNewCoord(3) != 0)
		exit(-1);
	Beep(523,500);
}

int getNewCoord(int num)
{
	int loop = 10; //get 10 samples, the arrays lengths are 10
	float temxl[10], temyl[10];
	float temxr[10], temyr[10];
	
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

		if(!stasm_search_single(&foundface, landmarks, (const char*)frame.data, frame.cols, frame.rows, path, "../data"))
		{
			std::cout<<"stasm_search_single failed";
			system("pause");
			return -1;
		}

		if(foundface && num == 0)
		{
			temxl[i] = landmarks[38*2] - getOXL();
			temyl[i] = landmarks[38*2+1] - getOYL();
			temxr[i] = landmarks[39*2] - getOXR();
			temyr[i] = landmarks[39*2+1] - getOYR();
		}
		else if(foundface && num != 0)
		{
			temxl[i] = landmarks[38*2];
			temyl[i] = landmarks[38*2+1];
			temxr[i] = landmarks[39*2];
			temyr[i] = landmarks[39*2+1];
		}
		else
		{
			std::cout<<"No face found\n";
			i--;
		}

		stasm_force_points_into_image(landmarks,frame.cols, frame.rows);
		for(int l = 0; l < stasm_NLANDMARKS; l++)
			frame(cvRound(landmarks[l*2+1]), cvRound(landmarks[l*2])) = 255;
		
		cv::flip(frame, output, 1);
		cv::imshow("camera", output);
        if(cv::waitKey(30) >= 0) break;
	}
	temxl[0] =  averageVal(temxl, loop);
	temyl[0] =  averageVal(temyl, loop);
	temxr[0] =  averageVal(temxr, loop);
	temyr[0] =  averageVal(temyr, loop);

	xl[num] = temxl[0];
	yl[num] = temyl[0];
	xr[num] = temxr[0];
	yr[num] = temyr[0];
	return 0;
}

void countRect(float rx, float ry)
{
	int x, y;
	if(rx <= 1.0 && rx >= 0.0 && ry <= 1.0 && ry >= 0.0){
		if(rx < 0.1 && rx >= 0.0) x = 0;
		else if(rx < 0.2 && rx >= 0.1) x = 1;
		else if(rx < 0.3 && rx >= 0.2) x = 2;
		else if(rx < 0.4 && rx >= 0.3) x = 3;
		else if(rx < 0.5 && rx >= 0.4) x = 4;
		else if(rx < 0.6 && rx >= 0.5) x = 5;
		else if(rx < 0.7 && rx >= 0.6) x = 6;
		else if(rx < 0.8 && rx >= 0.7) x = 7;
		else if(rx < 0.9 && rx >= 0.8) x = 8;
		else if(rx <= 1.0 && rx >= 0.9) x = 9;

		if(ry < 0.1 && ry >= 0.0) y = 0;
		else if(ry < 0.2 && ry >= 0.1) y = 1;
		else if(ry < 0.3 && ry >= 0.2) y = 2;
		else if(ry < 0.4 && ry >= 0.3) y = 3;
		else if(ry < 0.5 && ry >= 0.4) y = 4;
		else if(ry < 0.6 && ry >= 0.5) y = 5;
		else if(ry < 0.7 && ry >= 0.6) y = 6;
		else if(ry < 0.8 && ry >= 0.7) y = 7;
		else if(ry < 0.9 && ry >= 0.8) y = 8;
		else if(ry <= 1.0 && ry >= 0.9) y = 9;

		if(count[x + y*10] < 65535)
		count[x + y*10]++;
	}
		//bg(cvRound(rx*bg.rows), cvRound(ry*bg.cols)) = 255;
}

void drawbg(int x, int y)//screen.cols, screen.rows
{
	normalizeCount();
	
	int i, j;
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			cv::rectangle( bg, cv::Point( j*x/10, i*y/10 ), cv::Point( (j+1)*x/10, (i+1)*y/10), cv::Scalar( 255*normc[10*i+j] ), -1, 4 );
		}
	}

}

void normalizeCount()
{
	unsigned int max = 0;
	int i;
	for(i = 0; i < 100; i++){
		if(count[i] > max) max = count[i];
	}
	for(i = 0; i < 100; i++){
		normc[i] = (float)count[i]/(float)max;
	}
}

int main(int argc, char** argv)
{
	int x0 = 0;
	int y0 = 0;
	cv::Mat_<unsigned char> img, frame, output;


	capstureScreen();

	if(!cap.isOpened())
	{
		std::cout<<"camera is not opened";
		return -1;
	}

	getGazePos();

	std::cout<<xl[0]<<std::endl;
	std::cout<<yl[0]<<std::endl;
	std::cout<<std::endl;
	std::cout<<xl[1]<<std::endl;
	std::cout<<yl[1]<<std::endl;
	std::cout<<std::endl;
	std::cout<<xl[2]<<std::endl;
	std::cout<<yl[2]<<std::endl;
	std::cout<<std::endl;
	std::cout<<xl[3]<<std::endl;
	std::cout<<yl[3]<<std::endl;
	std::cout<<std::endl;

	std::cout<<xr[0]<<std::endl;
	std::cout<<yr[0]<<std::endl;
	std::cout<<std::endl;
	std::cout<<xr[1]<<std::endl;
	std::cout<<yr[1]<<std::endl;
	std::cout<<std::endl;
	std::cout<<xr[2]<<std::endl;
	std::cout<<yr[2]<<std::endl;
	std::cout<<std::endl;
	std::cout<<xr[3]<<std::endl;
	std::cout<<yr[3]<<std::endl;
	std::cout<<std::endl;

	system("pause");

	bg = cv::Mat(screen.rows, screen.cols, CV_8UC1);
	std::cout<<"Reading Habits Monitor is working...";
		while(1)
	{
		float rx, ry;
        cap >> img; // get a new frame from camera
		cv::cvtColor(img, frame, CV_BGR2GRAY);

		if(!frame.data)
		{
			std::cout<<"No image loaded";
			return -1;
		}

		if(!stasm_search_single(&foundface, landmarks, (const char*)frame.data, frame.cols, frame.rows, path, "../data"))
		{
			std::cout<<"stasm_search_single failed";
			return -1;
		}

        if (!foundface)
			std::cout<<"No face found"<<std::endl;

		
		x0 = GetSystemMetrics(SM_CXSCREEN);
		y0 = GetSystemMetrics(SM_CYSCREEN);
		rx = getRatio('X');
		ry = getRatio('Y');
		//std::cout<<"ratio x = "<<rx<<std::endl;
		//std::cout<<"ratio y = "<<ry<<std::endl;

		//SetCursorPos(x0*rx,y0*ry);
		countRect(rx, ry);

		cv::flip(frame, output, 1);//mirror output
		cv::imshow("camera", output);
        if(cv::waitKey(30) >= 0) break;
	}

	drawbg(screen.cols, screen.rows);
	cv::imshow("screen", screen);
	cv::imshow("output", bg);
	cv::waitKey(0);

	return 0;
}
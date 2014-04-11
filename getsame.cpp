/*************************************************************************
	> File Name: getsame.cpp
	> Author: sandy
	> Mail: sandy@luo.bo 
	> Created Time: 2014年04月10日 星期四 10时00分07秒
 ************************************************************************/

#include<iostream>
#include "opencv/cv.h"
#include "opencv/highgui.h"
using namespace std;
int main(int argc,char **argv)
{
	string file1(argv[1]);
	string file2(argv[2]);
	IplImage *iplImage1 = cvLoadImage(file1.c_str(),0);
	IplImage *iplImage2 = cvLoadImage(file2.c_str(),0);
	IplImage *result = cvCreateImage(cvGetSize(iplImage1),IPL_DEPTH_8U,1);
	cvSet(result,cvScalar(0));
	cvXor(iplImage1,iplImage2,result,NULL);
	char* data = result->imageData;
	int sum=0;
	for(int i=0; i<result->height; i++)
		for(int j=0; j<result->width; j++)
			if(data[i*result->widthStep+j]==0x00)
				sum++;
	cout<<"sum:\t"<<sum<<endl;
	return 0;
}

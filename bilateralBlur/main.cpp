#include<iostream>
using namespace std;
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
using namespace cv;
//#include"getClosenessWeight.hpp"
#include"bfltGray.hpp"
//#include<opencv2/imgproc.hpp>
//#include<opencv2/ximgproc.hpp>
int main(){
Mat src=imread("../11111.jfif",IMREAD_GRAYSCALE);
if (src.data==nullptr)
    return -1;
imshow("input image",src);
Mat srcI;
src.convertTo (srcI,CV_64FC1,1.0/255,0);

Mat dst=bfltGray (srcI,Size(25,25),19,0.1);
dst.convertTo (dst,CV_8UC1,255,0);
imshow("BilateralBlur",dst);
Mat dstb;
bilateralFilter (src,dstb,0,100,100,BORDER_DEFAULT);
imshow("bilateralFilter",dstb);

waitKey(0);

return 0;
}

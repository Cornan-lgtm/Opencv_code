#include"getClosenessWeight.hpp"

Mat getClosenessWeight (double sigma_g, Size size){
    CV_Assert(size.width%2==1&&size.height%2==1);
    int H = size.height;
    int W= size.width;
    int cH=(H-1)/2;
    int cW=(W-1)/2;
    Mat closenessWeight=Mat::zeros (size,CV_64FC1);
    for (int r=0;r<H;r++){
        for(int c=0;c<W;c++){
            closenessWeight.at<double>(r,c)=exp(-(pow(r-cH,2.0)+pow(c-cW,2.0))/2/pow(sigma_g,2.0));

        }
    }
    return closenessWeight;




}

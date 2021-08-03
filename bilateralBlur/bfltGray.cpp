#include"bfltGray.hpp"
#include"getClosenessWeight.hpp"
Mat bfltGray (const Mat &image, Size winSize, float sigma_g, float sigma_d){

    int winH=winSize.height;
    int winW=winSize.width;
    CV_Assert(winH>0&&winW>0);
    CV_Assert(winH%2==1&&winW%2==1);
    if(winH==1&&winW==1)
        return image;
    int centerH=(winH-1)/2;
    int centerW=(winW-1)/2;
    Mat closenessWeight=getClosenessWeight (sigma_g,winSize);
    int rows=image.rows;
    int cols=image.cols;
    Mat blfImage=Mat::ones (image.size(),CV_64FC1);
    for (int r=0;r<rows;r++){
        for (int c=0;c<cols;c++){
            double pixel=image.at<double>(r,c);
            int rTop= r-centerH<0 ? 0 : r-centerH;
            int rBottom= r+centerH>rows-1 ? rows-1 : r+centerH;
            int cLeft = c-centerW<0 ? 0 : c-centerW;
            int cRight = c+centerW>cols-1 ? cols-1 : c+centerW;
            Mat region=image(Rect(Point(cLeft,rTop),Point(cRight,rBottom))).clone ();
            Mat similarityWeight;
            cv::pow(region-pixel,2.0,similarityWeight);
            cv::exp(-0.5*similarityWeight/pow(sigma_d,2.0),similarityWeight);
            Rect regionRect = Rect(Point(cLeft-c+centerW,rTop-r+centerH),Point(cRight-c+centerW,rBottom-r+centerH));
            Mat closenessWeightTemp = closenessWeight(regionRect).clone ();
            Mat weightTemp = closenessWeightTemp.mul (similarityWeight);
            weightTemp = weightTemp/cv::sum (weightTemp)[0];
            Mat result = weightTemp.mul (region);
            blfImage.at<double>(r,c)=sum(result)[0];


        }
    }

return blfImage;





}

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat dst1;
	cv::Mat dst2;
	cv::Mat adst1;
	cv::Mat adst2;
	VideoCapture cap;
	cap.open(0);
	while (1)
	{
		cv::Mat frame;
		bool rSucess = cap.read(frame);

		Sobel(frame, dst1,CV_16SC1,1,0,3) ;
		Sobel(frame, dst2,CV_16SC1,0,1,3);
		convertScaleAbs(dst1, adst1);
		convertScaleAbs(dst2, adst2);
		cv::imshow("frame ", frame);
		cv::imshow("adst1 ", adst1);
		cv::imshow("adst2 ", adst2);
		waitKey(30);

	}
	return 0;
}

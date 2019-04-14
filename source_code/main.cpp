#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
	cv::Mat img = cv::imread(argv[1]);
	cv::namedWindow("image", cv::WINDOW_NORMAL);
	cv::imshow("image", img);
	cv::waitKey(0);

	return 0;
}
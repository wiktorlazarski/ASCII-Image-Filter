#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
	cv::Mat img = cv::imread(argv[1]);
	cv::Mat gray_img(img.rows, img.cols, CV_8UC1);

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			
			auto p_intensity = img.at<cv::Vec3b>(j, i);

			int blue = p_intensity[0];
			int green = p_intensity[1];
			int red = p_intensity[2];
			
			int luminance = static_cast<int>(0.2126f * red + 0.7152f * green + 0.0722f * blue);

			//convert to grayscale
			gray_img.at<uchar>(j, i) = luminance;
		}
	}

	cv::namedWindow("grayscaled image", cv::WINDOW_NORMAL);
	cv::imshow("grayscaled image", gray_img);
	cv::waitKey(0);

	cv::imwrite(argv[2], gray_img);

	return 0;
}
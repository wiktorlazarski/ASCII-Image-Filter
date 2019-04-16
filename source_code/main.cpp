#include <iostream>
#include <memory>

#include "image_processing/rgb_image.h"
#include "image_processing/grayscale_image.h"
#include "image_processing/rgb_to_grayscale.h"

int main(int argc, char* argv[])
{
	const RGBImage input_img(argv[1]);
	std::unique_ptr<GrayscaleImage> gray_img(RGBToGrayscale::get_instance().convert(input_img));

	cv::Mat raw_img = gray_img->raw_data();
	cv::namedWindow("grayscaled image", cv::WINDOW_NORMAL);
	cv::imshow("grayscaled image", raw_img);
	cv::waitKey(0);

	cv::imwrite(argv[2], raw_img);

	return 0;
}
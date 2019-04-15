#include "image processing/rgb_image.h"
#include "image processing/grayscale_image.h"

int main(int argc, char* argv[])
{
	const RGBImage img(argv[1]);
	GrayscaleImage gray_img(img.rows(), img.cols());

	for (int i = 0; i < img.rows(); i++) {
		for (int j = 0; j < img.cols(); j++) {
			
			auto p_intensity = img.pixel_at(j, i);

			int blue = p_intensity[0];
			int green = p_intensity[1];
			int red = p_intensity[2];
			
			int luminance = static_cast<int>(0.2126f * red + 0.7152f * green + 0.0722f * blue);

			//convert to grayscale
			gray_img.pixel_at(j, i) = luminance;
		}
	}

	// Writing and printing image on window
	//cv::namedWindow("grayscaled image", cv::WINDOW_NORMAL);
	//cv::imshow("grayscaled image", gray_img.m_data);
	//cv::waitKey(0);

	//cv::imwrite(argv[2], gray_img);

	return 0;
}
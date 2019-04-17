#include "image_processing/image_converters/rgb_to_grayscale.h"
#include "image_processing/image_classes/ascii_image.h"
#include "image_processing/image_converters/rgb_to_ascii.h"

int main(int argc, char* argv[])
{
	const RGBImage input_img(argv[1]);
	//std::unique_ptr<GrayscaleImage> gray_img(RGBToGrayscale::get_instance().convert(input_img));
	
	std::unique_ptr<AsciiImage> ascii_img(RGBToAscii::get_instance().convert(input_img));
	ascii_img->display("ASCII image");

	//cv::putText(data, "Hi sdsds", cv::Point(0, 25), cv::FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(0), 1);
	/*cv::namedWindow("sd", cv::WINDOW_NORMAL);
	cv::imshow("sd", data);
	cv::waitKey(0)*/;

	//input_img.display("RGB Image");
	//gray_img->display("Grayscale Image");
	//gray_img->fwrite(argv[2]);

	return 0;
}
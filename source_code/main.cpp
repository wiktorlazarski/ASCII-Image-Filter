#include "image_processing/image_converters/rgb_to_ascii.h"

int main(int argc, char* argv[])
{
	const RGBImage input_img(argv[1]);
	
	std::unique_ptr<AsciiImage> ascii_img(RGBToAscii::get_instance().convert(input_img));
	ascii_img->display("ASCII image");
	
	ascii_img->fwrite(argv[2]);

	return 0;
}
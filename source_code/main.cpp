#include <iostream>
#include <memory>

#include "image_processing/rgb_image.h"
#include "image_processing/grayscale_image.h"
#include "image_processing/rgb_to_grayscale.h"

int main(int argc, char* argv[])
{
	const RGBImage input_img(argv[1]);
	std::unique_ptr<GrayscaleImage> gray_img(RGBToGrayscale::get_instance().convert(input_img));

	input_img.display("RGB Image");
	gray_img->display("Grayscale Image");
	gray_img->fwrite(argv[2]);

	return 0;
}
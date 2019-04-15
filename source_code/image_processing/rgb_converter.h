#pragma once
#include "image_converter.h"
#include "rgb_image.h"
#include "grayscale_image.h"

class RGBConverter final : public IImageConverter<RGBImage, GrayscaleImage>
{
	//constructors
	RGBConverter() = default;
	RGBConverter(const RGBConverter&) = delete;
	RGBConverter(RGBConverter&&) = delete;

	//assign operators
	RGBConverter& operator=(const RGBConverter&) = delete;
	RGBConverter& operator=(RGBConverter&&) = delete;

public:

	static RGBConverter& get_instance() {
		static RGBConverter instance;
		return instance;
	}

	//convert method
	[[nodiscard]] GrayscaleImage* convert(const RGBImage& rgb_img) override {
		GrayscaleImage* retv = new GrayscaleImage(rgb_img.rows(), rgb_img.cols());

		for (int i = 0; i < rgb_img.rows(); i++) {
			for (int j = 0; j < rgb_img.cols(); j++) {

				auto p_intensity = rgb_img.pixel_at(j, i);

				int blue = p_intensity[0];
				int green = p_intensity[1];
				int red = p_intensity[2];

				int luminance = static_cast<int>(0.2126f * red + 0.7152f * green + 0.0722f * blue);

				//convert to grayscale
				retv->pixel_at(j, i) = luminance;
			}
		}

		return retv;
	}

	//destructor
	~RGBConverter() = default;
};
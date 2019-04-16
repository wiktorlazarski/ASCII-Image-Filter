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

	//implementation of pure virtual method
	[[nodiscard]] std::unique_ptr<GrayscaleImage> convert(const RGBImage& rgb_img) override;

	//destructor
	~RGBConverter() = default;
};
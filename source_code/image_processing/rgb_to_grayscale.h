#pragma once
#include <future>
#include <vector>

#include "image_converter.h"
#include "rgb_image.h"
#include "grayscale_image.h"

class RGBToGrayscale final : public IImageConverter<RGBImage, GrayscaleImage>
{
public:
	static RGBToGrayscale& get_instance() {
		static RGBToGrayscale instance;
		return instance;
	}

	//implementation of pure virtual method
	[[nodiscard]] std::unique_ptr<GrayscaleImage> convert(const RGBImage& rgb_img) const override;

	//destructor
	~RGBToGrayscale() = default;

private:
	//constructors
	RGBToGrayscale() = default;
	RGBToGrayscale(const RGBToGrayscale&) = delete;
	RGBToGrayscale(RGBToGrayscale&&) = delete;

	//assign operators
	RGBToGrayscale& operator=(const RGBToGrayscale&) = delete;
	RGBToGrayscale& operator=(RGBToGrayscale&&) = delete;

	//parallel conversion
	void convert_pixels(GrayscaleImage* output, const RGBImage& rgb, int high_row, int low_row) const;
	void p_convert(GrayscaleImage* output, const RGBImage& rgb) const;
};
#pragma once
#include "../image_classes/ascii_image.h"
#include "image_converter.h"
#include "rgb_to_grayscale.h"

class RGBToAscii final : public IImageConverter<RGBImage, AsciiImage>
{
public:
	static RGBToAscii& get_instance() {
		static RGBToAscii instance;
		return instance;
	}

	[[nodiscard]] std::unique_ptr<AsciiImage> convert(const RGBImage& rgb_img) const override {
		std::lock_guard<std::mutex> lock(m_mutex);

		std::unique_ptr<GrayscaleImage> gray_img(RGBToGrayscale::get_instance().convert(rgb_img));
		ascii_img = std::make_unique<AsciiImage>(new AsciiImage(&rgb_img));
		
		print_ascii({ 0, 0 }, { 8, 8 }, rgb_img, *gray_img);

		return std::move(ascii_img);
	}

	//destructor
	~RGBToAscii() = default;

private:

	mutable std::mutex m_mutex;
	mutable std::unique_ptr<AsciiImage> ascii_img;

	//constructors
	RGBToAscii() = default;
	RGBToAscii(const RGBToAscii&) = delete;
	RGBToAscii(RGBToAscii&&) = delete;

	//assign operators
	RGBToAscii& operator=(const RGBToAscii&) = delete;
	RGBToAscii& operator=(RGBToAscii&&) = delete;

	//converter's support methods
	void print_ascii(cv::Point upper_left, cv::Point lower_right, const RGBImage& rgb_img, const GrayscaleImage& gray_img) const;
	std::pair<char, cv::Vec3b> mean_values(int x_cnt, int y_cnt, const RGBImage& rgb_img, const GrayscaleImage& gray_img) const;
	std::string as_string(char c) const;
	double compute_scale(const std::string& ascii, int subspace_width, int subspace_height) const;
};
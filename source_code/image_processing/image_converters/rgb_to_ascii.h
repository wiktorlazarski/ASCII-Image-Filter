#pragma once
#include "../image_classes/ascii_image.h"
#include "rgb_to_grayscale.h"

class RGBToAscii final : public IImageConverter<RGBImage, AsciiImage>
{
	//define width of square subspace in pixels
	static const int SUBSPACE_LENGTH = 5;

public:
	static RGBToAscii& get_instance() {
		static RGBToAscii instance;
		return instance;
	}

	//implementation of pure virtual method
	[[nodiscard]] std::unique_ptr<AsciiImage> convert(const RGBImage& rgb_img) override;

	//destructor
	~RGBToAscii() = default;

private:

	std::mutex m_mutex;
	std::unique_ptr<AsciiImage> ascii_img;

	//constructors
	RGBToAscii() = default;
	RGBToAscii(const RGBToAscii&) = delete;
	RGBToAscii(RGBToAscii&&) = delete;

	//assign operators
	RGBToAscii& operator=(const RGBToAscii&) = delete;
	RGBToAscii& operator=(RGBToAscii&&) = delete;

	//converter's support methods
	void ppaint_image(const RGBImage& rgb_img, const GrayscaleImage& gray_img);
	void paint_fragment(const RGBImage& rgb_img, const GrayscaleImage& gray_img, int low_row, int high_row);
	void print_ascii(cv::Point upper_left, cv::Point lower_right, const RGBImage& rgb_img, const GrayscaleImage& gray_img);
	std::pair<char, cv::Vec3b> mean_values(cv::Point upper_left, cv::Point lower_right, const RGBImage& rgb_img, const GrayscaleImage& gray_img);
	std::string as_string(char c);
	double compute_scale(const std::string& ascii, int subspace_width, int subspace_height);
};
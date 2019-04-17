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
		
		print_ascii({ 20, 20 }, { 40, 40 }, rgb_img, *gray_img);

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
	void print_ascii(cv::Point upper_left, cv::Point lower_right, const RGBImage& rgb_img, const GrayscaleImage& gray_img) const {
		cv::Vec3b mean_col = {0, 0, 0};
		int mean_val = 0;

		int x_cnt = lower_right.x - upper_left.x;
		int y_cnt = lower_right.y - upper_left.y;

		//compute mean values
		for (int i = 0; i < y_cnt; i++) {
			for (int j = 0; j < x_cnt; j++) {
				auto curr_col = rgb_img.pixel_at(i, j);
				mean_col[0] += curr_col[0];
				mean_col[1] += curr_col[1];
				mean_col[2] += curr_col[2];

				auto curr_val = gray_img.pixel_at(i, j);
				mean_val += curr_val;
			}
		}

		mean_col[0] /= (x_cnt + y_cnt);
		mean_val /= (x_cnt + y_cnt);

		char ascii = mean_val % 127 + 33;
		std::stringstream ss;
		ss << ascii;
		double font_size = x_cnt > y_cnt ? y_cnt / x_cnt : x_cnt / y_cnt;
		ascii_img->put_text(ss.str(), cv::Point(upper_left.x, lower_right.y), cv::FONT_HERSHEY_SIMPLEX, font_size, mean_col);
	}

};
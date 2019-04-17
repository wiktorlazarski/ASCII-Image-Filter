#include "rgb_to_ascii.h"

void RGBToAscii::print_ascii(cv::Point upper_left, cv::Point lower_right, const RGBImage& rgb_img, const GrayscaleImage& gray_img) const {

	int subspace_width = lower_right.x - upper_left.x;
	int subspace_height = lower_right.y - upper_left.y;

	auto[mean_ascii, color] = mean_values(subspace_width, subspace_height, rgb_img, gray_img);
	std::string ascii = as_string(mean_ascii);
	double scale = compute_scale(ascii, subspace_width, subspace_height);

	ascii_img->put_text(ascii, cv::Point(upper_left.x, lower_right.y), cv::FONT_HERSHEY_SIMPLEX, scale, color);
}

std::pair<char, cv::Vec3b> RGBToAscii::mean_values(int x_cnt, int y_cnt, const RGBImage& rgb_img, const GrayscaleImage& gray_img) const {
	int mean_red = 0;
	int mean_blue = 0;
	int mean_green = 0;
	int mean_val = 0;

	//compute mean values
	for (int i = 0; i < y_cnt; i++) {
		for (int j = 0; j < x_cnt; j++) {
			//col
			auto curr_col = rgb_img.pixel_at(i, j);
			mean_blue += curr_col[0];
			mean_green += curr_col[1];
			mean_red += curr_col[2];

			//ascii val
			auto curr_val = gray_img.pixel_at(i, j);
			mean_val += curr_val;
		}
	}

	mean_blue /= (x_cnt * y_cnt);
	mean_green /= (x_cnt * y_cnt);
	mean_red /= (x_cnt * y_cnt);
	mean_val /= (x_cnt * y_cnt);

	cv::Vec3b mean_col = { (uchar)mean_blue, (uchar)mean_green, (uchar)mean_red };
	char mean_ascii = mean_val % 127 + 33;

	return std::make_pair<>(mean_ascii, mean_col);
}

std::string RGBToAscii::as_string(char c) const {
	std::stringstream ss;
	ss << c;
	std::string ascii = ss.str();
	return ascii;
}

double RGBToAscii::compute_scale(const std::string& ascii, int subspace_width, int subspace_height) const {

	auto size = cv::getTextSize(ascii, cv::FONT_HERSHEY_SIMPLEX, 1, 1, 0);

	double retv = size.width > size.height ?
		static_cast<double>(subspace_width) / size.width : static_cast<double>(subspace_height) / size.height;

	return retv;
}
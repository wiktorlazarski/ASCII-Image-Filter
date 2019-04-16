#include "rgb_to_grayscale.h"

[[nodiscard]] std::unique_ptr<GrayscaleImage> RGBToGrayscale::convert(const RGBImage& rgb_img) const {
	std::unique_ptr<GrayscaleImage> retv(new GrayscaleImage(rgb_img.rows(), rgb_img.cols()));

	p_convert(retv.get(), rgb_img);

	return std::move(retv);
}

void RGBToGrayscale::convert_pixels(GrayscaleImage* output, const RGBImage& rgb, int low_row, int high_row) const {
	for (int i = low_row; i < high_row; i++) {
		for (int j = 0; j < output->cols(); j++) {

			auto p_intensity = rgb.pixel_at(j, i);

			int blue = p_intensity[0];
			int green = p_intensity[1];
			int red = p_intensity[2];

			int luminance = static_cast<int>(0.2126f * red + 0.7152f * green + 0.0722f * blue);

			//convert to grayscale
			output->pixel_at(j, i) = luminance;
		}
	}

}

void RGBToGrayscale::p_convert(GrayscaleImage* output, const RGBImage& rgb) const {
	static constexpr int GRAIN = 600;

	std::vector<std::future<void>> pool;

	for (int i = 0; i < output->rows(); i += GRAIN) {
		if (i + GRAIN <= output->rows()) {
			pool.push_back(std::async(std::launch::async, &RGBToGrayscale::convert_pixels, this, std::ref(output), std::ref(rgb), i, i + GRAIN));
		}
		else {
			pool.push_back(std::async(std::launch::async, &RGBToGrayscale::convert_pixels, this, std::ref(output), std::ref(rgb), i, output->rows()));
		}
	}

	for (uint i = 0; i < pool.size(); i++) {
		pool[i].get();
	}

}
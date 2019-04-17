#include <future>
#include "ascii_image.h"

const char* AsciiImage::WATERMARK = "Created by ASCII filter";

AsciiImage::AsciiImage(int rows, int cols) : Image(rows + WATERMARK_SIZE, cols, CV_8UC3), font_size(0.33)
{
	ppaint_background();
	put_text(WATERMARK, cv::Point(0, this->rows() - 5), cv::FONT_HERSHEY_COMPLEX, font_size, cv::Scalar(0, 0, 0));
}

void AsciiImage::paint_background(int low_row, int high_row) {
	for (int i = low_row; i < high_row; i++) {
		for (int j = 0; j < this->cols(); j++) {
			//set white background 
			pixel_at(i, j) = { 255, 255, 255 };
		}
	}
}

void AsciiImage::ppaint_background() {
	static constexpr int GRAIN = 500;

	std::vector<std::future<void>> pool;

	for (int i = 0; i <= rows(); i += GRAIN) {
		if (i + GRAIN < rows()) {
			pool.push_back(std::async(std::launch::async, &AsciiImage::paint_background, this, i, i + GRAIN));
		}
		else {
			pool.push_back(std::async(std::launch::async, &AsciiImage::paint_background, this, i, rows()));
		}
	}

	//waits untill all threads finish
	for (uint i = 0; i < pool.size(); i++) {
		pool[i].get();
	}
}

#pragma once
#include "image.h"

class AsciiImage : public Image
{
	static const int WATERMARK = 200;

public:
	using pixel_type = cv::Vec3b;

	//constructors
	explicit AsciiImage(int rows, int cols) : Image(rows + WATERMARK, cols, CV_8UC3)
	{
		for (int i = 0; i < this->rows(); i++) {
			for (int j = 0; j < this->cols(); j++) {
				pixel_at(i, j) = { 255, 255, 255 };
			}
		}
	}
	AsciiImage(const AsciiImage& img) = default;
	AsciiImage(AsciiImage&& img) = default;

	//assign operators
	AsciiImage& operator=(const AsciiImage&) = default;
	AsciiImage& operator=(AsciiImage&&) = default;

	//element access
	pixel_type& pixel_at(const int& x, const int& y) {
		return Image::pixel_at<pixel_type>(x, y);
	}
	const pixel_type& pixel_at(const int& x, const int& y) const {
		return Image::pixel_at<pixel_type>(x, y);
	}

	//destructor
	virtual ~AsciiImage() = default;
};
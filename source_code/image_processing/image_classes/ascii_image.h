#pragma once
#include <future>
#include "image.h"

class AsciiImage : public Image
{
	static const int WATERMARK_SIZE = 200;
	static const char* WATERMARK;

public:
	using pixel_type = cv::Vec3b;

	//constructors
	explicit AsciiImage(int rows, int cols);
	explicit AsciiImage(const Image& img) : AsciiImage(img.rows(), img.cols()) 
	{}
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

private:
	double font_size;

	void paint_background(int low_row, int high_row);
	void ppaint_background();
};
#pragma once
#include "image.h"

class GrayscaleImage : public Image
{
public:
	using pixel_type = uchar;

	//constructors
	explicit GrayscaleImage(const std::string& path) : Image(path)
	{}
	explicit GrayscaleImage(int rows, int cols) : Image(rows, cols, CV_8UC1)
	{}
	GrayscaleImage(const GrayscaleImage& img) = default;
	GrayscaleImage(GrayscaleImage&& img) = default;

	//assign operators
	GrayscaleImage& operator=(const GrayscaleImage&) = default;
	GrayscaleImage& operator=(GrayscaleImage&&) = default;

	//element access
	pixel_type& pixel_at(int x, int y) {
		return Image::pixel_at<pixel_type>(x, y);
	}
	const pixel_type& pixel_at(int x, int y) const {
		return Image::pixel_at<pixel_type>(x, y);
	}

	//destructor
	virtual ~GrayscaleImage() = default;
};
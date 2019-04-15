#pragma once
#include "image.h"

class GrayscaleImage : public Image
{
public:
	using pixel_type = uchar;

	//constructors
	explicit GrayscaleImage(const std::string& path) : Image(path)
	{}
	explicit GrayscaleImage(const int& rows, const int& cols) : Image(rows, cols, CV_8UC1)
	{}
	GrayscaleImage(const GrayscaleImage& img) = default;
	GrayscaleImage(GrayscaleImage&& img) = default;

	//element access
	pixel_type& pixel_at(const int& x, const int& y) {
		return Image::pixel_at<pixel_type>(x, y);
	}
	const pixel_type& pixel_at(const int& x, const int& y) const {
		return Image::pixel_at<pixel_type>(x, y);
	}

	//destructor
	virtual ~GrayscaleImage() = default;
};
#pragma once
#include "image.h"

class RGBImage : public Image
{
public:
	using pixel_type = cv::Vec3b;

	//constructors
	explicit RGBImage(const std::string& path) : Image(path)
	{}
	explicit RGBImage(const int& rows, const int& cols, const int& type) : Image(rows, cols, type)
	{}
	RGBImage(const RGBImage& img) = default;
	RGBImage(RGBImage&& img) = default;

	//assign operators
	RGBImage& operator=(const RGBImage&) = default;
	RGBImage& operator=(RGBImage&&) = default;

	//element access
	pixel_type& pixel_at(const int& x, const int& y) {
		return Image::pixel_at<pixel_type>(x, y);
	}
	const pixel_type& pixel_at(const int& x, const int& y) const {
		return Image::pixel_at<pixel_type>(x, y);
	}

	//destructor
	virtual ~RGBImage() = default;
};
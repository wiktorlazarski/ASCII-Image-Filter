#pragma once
#include "image.h"

class RGBImage : public Image
{
	using pixel_type = cv::Vec3b;

public:
	explicit RGBImage(const std::string& path) : Image(path)
	{}
	RGBImage(const RGBImage& img) = default;
	RGBImage(RGBImage&& img) = default;

	//element access
	pixel_type& pixel_at(const int& x, const int& y) {
		return Image::pixel_at<pixel_type>(x, y);
	}
	const pixel_type& pixel_at(const int& x, const int& y) const {
		return Image::pixel_at<pixel_type>(x, y);
	}

	virtual ~RGBImage() = default;
};
#pragma once
#include "image.h"

class AsciiImage : public Image
{
	static const int WATERMARK_SIZE = 200;
	static const char* WATERMARK;

public:
	using pixel_type = cv::Vec3b;

	//constructors
	explicit AsciiImage(int rows, int cols) : Image(rows + WATERMARK_SIZE, cols, CV_8UC3)
	{
		for (int i = 0; i < this->rows(); i++) {
			for (int j = 0; j < this->cols(); j++) {
				//set white background 
				pixel_at(i, j) = { 255, 255, 255 };
			}
		}

		double font_size = rows > cols ? rows / cols : cols / rows;	
		font_size /= 7;
		put_text(WATERMARK, cv::Point(0, this->rows() - 5), cv::FONT_HERSHEY_COMPLEX, font_size, cv::Scalar(0, 0, 0));
	}
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
};

const char* AsciiImage::WATERMARK = "Created by ASCII filter";
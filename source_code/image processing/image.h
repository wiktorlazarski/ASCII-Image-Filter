#pragma once
#include <opencv2/opencv.hpp>

class Image
{
	cv::Mat m_data;

public:
	//constructors
	Image(const std::string& path) {
		m_data = cv::imread(path);
	}
	Image(const Image& img) {
		*this = img;
	}
	Image(Image&& img) {
		*this = img;
	}

	//assign operators
	Image& operator=(const Image& rhs) {
		m_data = rhs.m_data.clone();
		return *this;
	}
	Image& operator=(Image&& rhs) {
		m_data = std::move(rhs.m_data);
		return *this;
	}

};
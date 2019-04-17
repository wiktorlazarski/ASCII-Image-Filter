#include "image.h"

Image& Image::operator=(const Image& rhs) {
	m_data = rhs.m_data.clone();
	return *this;
}

Image& Image::operator=(Image&& rhs) {
	m_data = std::move(rhs.m_data);
	return *this;
}

void Image::display(const std::string& wnd_name, int cv_flag) const {
	cv::namedWindow(wnd_name, cv::WINDOW_NORMAL);
	cv::imshow(wnd_name, m_data);
	cv::waitKey(0);
}
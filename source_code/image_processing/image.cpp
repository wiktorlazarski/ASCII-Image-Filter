#include "image.h"

Image& Image::operator=(const Image& rhs) {
	m_data = rhs.m_data.clone();
	return *this;
}

Image& Image::operator=(Image&& rhs) {
	m_data = std::move(rhs.m_data);
	return *this;
}
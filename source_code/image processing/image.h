#pragma once
#include <opencv2/opencv.hpp>

class Image
{
	cv::Mat m_data;

public:
	//constructors
	explicit Image(const std::string& path) { m_data = cv::imread(path); }
	explicit Image(const int& rows, const int& cols, const int& type) : m_data(rows, cols, type)
	{}
	Image(const Image& img) { *this = img; }
	Image(Image&& img) { *this = img; }

	//assign operators
	Image& operator=(const Image& rhs) {
		m_data = rhs.m_data.clone();
		return *this;
	}
	Image& operator=(Image&& rhs) {
		m_data = std::move(rhs.m_data);
		return *this;
	}

	//raw data
	inline cv::Mat raw_data() const { 
		return m_data.clone();
	}

	//image parameters
	int rows() const noexcept { return m_data.rows; }
	int cols() const noexcept { return m_data.cols; }
	int channels() const noexcept { return m_data.channels(); }

	//destructor
	virtual ~Image() = default;

protected:
	//pixel data access for subclasses
	template<typename RetType>
	RetType& pixel_at(const int& x, const int& j) { return m_data.at<RetType>(x, j); }
	
	template<typename RetType>
	const RetType& pixel_at(const int& x, const int& j) const { return m_data.at<RetType>(x, j); }

};
#pragma once
#include <fstream>
#include <opencv2/opencv.hpp>

class Image
{
	cv::Mat m_data;

public:
	//constructors
	explicit Image(const std::string& fpath) { m_data = cv::imread(fpath); }
	explicit Image(int rows, int cols, int type) : m_data(rows, cols, type)
	{}
	Image(const Image& img) { *this = img; }
	Image(Image&& img) { *this = img; }

	//assign operators
	Image& operator=(const Image& rhs);
	Image& operator=(Image&& rhs);

	//modifiers
	void put_text(const std::string& text, const cv::Point& left_bottom, cv::HersheyFonts font, double font_size, const cv::Scalar& col) {
		cv::putText(m_data, text, left_bottom, font, font_size, col);
	}

	//output
	void fwrite(const std::string& fpath) const { cv::imwrite(fpath, m_data); }
	void display(const std::string& wnd_name, int cv_flag = cv::WINDOW_NORMAL) const;

	//raw data
	inline cv::Mat raw_data() const { return m_data.clone(); }

	//image parameters
	int rows() const noexcept { return m_data.rows; }
	int cols() const noexcept { return m_data.cols; }
	int channels() const noexcept { return m_data.channels(); }

	//destructor
	virtual ~Image() = default;

protected:
	//pixel data access for subclasses
	template<typename RetType>
	RetType& pixel_at(int x, int j) { return m_data.at<RetType>(x, j); }
	
	template<typename RetType>
	const RetType& pixel_at(int x, int j) const { return m_data.at<RetType>(x, j); }
};
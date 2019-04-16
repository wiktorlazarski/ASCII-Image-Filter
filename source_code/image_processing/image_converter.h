#pragma once
#include "image.h"

template<typename InputImage, typename OutputImage>
class IImageConverter
{
public:
	//constructors
	IImageConverter() = default;
	IImageConverter(const IImageConverter&) = default;
	IImageConverter(IImageConverter&&) = default;

	//assign operators
	IImageConverter& operator=(const IImageConverter&) = default;
	IImageConverter& operator=(IImageConverter&&) = default;

	//convert method
	virtual std::unique_ptr<OutputImage> convert(const InputImage&) = 0;

	//destructor
	virtual ~IImageConverter() = default;
};
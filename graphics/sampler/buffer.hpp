/*
 * PixelBuffer
 *
 *  Created on: 21.10.2014
 *      Author: akin
 */

#ifndef CORE_BUFFERSAMPLER_HPP_
#define CORE_BUFFERSAMPLER_HPP_

#include <types.hpp>
#include <graphics/colortools.hpp>
#include "sampler.hpp"

namespace core {
namespace graphics {

template <class CType>
class BufferSampler : public Sampler
{
private:
	uint width;
	uint height;
	size_t size;
	
	size_t used;
	
	CType *data;
public:
	BufferSampler()
	: data(nullptr)
	, width(0)
	, height(0)
	, size(0)
	, used(0)
	{
	}

	virtual ~BufferSampler()
	{
		delete[] data;
		data = nullptr;
	}

	template <class TType>
	void init( const BufferSampler<TType>& other )
	{
		init( other.getWidth() , other.getHeight() );
	}

	void init( uint width , uint height )
	{
		this->width = width;
		this->height = height;

		this->size = this->width * this->height;
		this->used = this->size;

		this->data = new CType[this->size];
	}

	uint getWidth() const
	{
		return width;
	}
	
	uint getHeight() const
	{
		return height;
	}
	
	size_t getUsed() const
	{
		return used;
	}
	
	void setUsed( size_t used )
	{
		this->used = used;
	}
	
	virtual void at( const float& at , Color& color ) const
	{
		size_t index = ((uint)at) % this->width;
		
		if( index >= this->size )
		{
			throw "NOOO";
		}
		convert( color , data[index] );
	}
	
	virtual void at( const glm::vec2& at , Color& color ) const
	{
		uint x = ((uint)at.x) % this->width;
		uint y = ((uint)at.y) % this->height;
		
		size_t index = ((y*this->width)+x);
		
		if( index >= this->size )
		{
			throw "NOOO";
		}
		convert( color , data[index] );
	}
	
	virtual void at( const glm::vec3& at , Color& color ) const
	{
		uint x = ((uint)at.x) % this->width;
		uint y = ((uint)at.y) % this->height;
		
		size_t index = ((y*this->width)+x);
		
		if( index >= this->size )
		{
			throw "NOOO";
		}
		convert( color , data[index] );
	}

	size_t getSize() const
	{
		return size;
	}

	CType *getBuffer() const
	{
		return data;
	}

	void set( uint width , uint height , const CType& pixel )
	{
		width %= this->width;
		height %= this->height;
		size_t index = ((height*this->width)+width);
		
		if( index >= this->size )
		{
			throw "NOOO";
		}

		data[index] = pixel;
	}
};

} // graphicsns
} // corens

#endif // CORE_BUFFERSAMPLER_HPP_
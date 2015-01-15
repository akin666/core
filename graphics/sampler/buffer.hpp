/*
 * PixelBuffer
 *
 *  Created on: 21.10.2014
 *      Author: akin
 */

#ifndef CORE_BUFFERSAMPLER_HPP_
#define CORE_BUFFERSAMPLER_HPP_

#include <types.hpp>
#include <graphics/buffer2d.hpp>
#include <graphics/pixelformat.hpp>
#include "sampler.hpp"
#include <exceptions/outofbounds.hpp>

namespace core {
namespace graphics {

template <class CType>
class Buffer2DSampler : public Sampler
{
private:
    typename Buffer2D<CType>::Shared buffer;
public:
	Buffer2DSampler( typename Buffer2D<CType>::Shared buffer )
	: buffer(buffer)
	{
	}

	virtual ~Buffer2DSampler()
	{
	}

	virtual void at( const float& at , Color& color ) const
	{
        auto *ptr = buffer->get();
        size_t width = buffer->getWidth();
		size_t index = ((uint)at) % width;
		
		convert( color , ptr[index] );
	}
	
	virtual void at( const glm::vec2& at , Color& color ) const
    {
        size_t width = buffer->getWidth();
        size_t height = buffer->getHeight();
        
		uint x = ((uint)at.x) % width;
		uint y = ((uint)at.y) % height;
        
        size_t index = ((y*width)+x);
        
        auto *ptr = buffer->get();
        
		if( index >= (width*height) )
		{
            throw OutOfBounds("Buffer2DSampler out of bounds.");
		}
		convert( color , ptr[index] );
	}
	
	virtual void at( const glm::vec3& at , Color& color ) const
    {
        size_t width = buffer->getWidth();
        size_t height = buffer->getHeight();
        
        uint x = ((uint)at.x) % width;
        uint y = ((uint)at.y) % height;
        
        size_t index = ((y*width)+x);
        
        auto *ptr = buffer->get();
        
        if( index >= (width*height) )
        {
            throw OutOfBounds("Buffer2DSampler out of bounds.");
        }
        convert( color , ptr[index] );
	}
};

} // graphicsns
} // corens

#endif // CORE_BUFFERSAMPLER_HPP_

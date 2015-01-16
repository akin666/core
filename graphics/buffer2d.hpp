/*
 * BUFFER_2D
 *
 *  Created on: 15.1.2015
 *      Author: akin
 *
 *      defines common gfx types.
 */

#ifndef BUFFER_2D_H_123_
#define BUFFER_2D_H_123_

#include "graphics.hpp"
#include <memory.hpp>
#include <exceptions/outofbounds.hpp>

namespace core {
namespace graphics {
    // Buffer2D
    
    // TODO:
    // Buffer1D
    // Buffer3D
    // BufferArray
    // BufferCube
    // BufferSphere
    
    template <class PixelFormat>
    class Buffer2D
    {
    public:
        using Shared = std::shared_ptr<Buffer2D>;
    private:
        size_t w;
        size_t h;
		core::Memory::Shared memory;
        PixelFormat *pixels;
    public:
        Buffer2D()
        : w(0)
		, h(0)
		, pixels(nullptr)
		{
			memory = std::make_shared<core::Memory>();
        }
        
        void init( size_t width , size_t height )
        {
			w = width;
			h = height;
            memory->init<PixelFormat>(w * h);
            pixels = memory->get<PixelFormat>();
        }
        
        inline size_t width() const
        {
            return w;
		}
		
		inline size_t height() const
		{
			return h;
		}
		
		inline size_t size() const
		{
			return memory->size<PixelFormat>();
		}
		
        PixelFormat at( size_t x , size_t y ) const
        {
            size_t idx = y * w + x;
            if( idx > memory->size<PixelFormat>() )
            {
                throw OutOfBounds("Buffer2D out of bounds.");
            }
            return pixels[idx];
        }
        
        PixelFormat *get() const
        {
            return pixels;
        }
    };
    
} // graphicsns
} // corens

#endif // BUFFER_H_123_

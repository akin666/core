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
        using Shared = std::shared_ptr<Memory>;
    private:
        size_t width;
        size_t height;
        core::Memory memory;
        PixelFormat *pixels;
    public:
        Buffer2D()
        : pixels(nullptr)
        {
        }
        
        void init( size_t width , size_t height )
        {
            memory.init<PixelFormat>(width * height);
            pixels = memory.get<PixelFormat>();
        }
        
        inline size_t getWidth() const
        {
            return width;
        }
        
        inline size_t getHeight() const
        {
            return height;
        }
        
        PixelFormat at( size_t x , size_t y ) const
        {
            size_t idx = y * width + x;
            if( idx > memory.size<PixelFormat>() )
            {
                throw "Overflow!";
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

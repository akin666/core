/*
 * BUFFER
 *
 *  Created on: 1.7.2012
 *      Author: akin
 *
 *      defines common gfx types.
 */

#ifndef BUFFER_H_123_
#define BUFFER_H_123_

#include "graphics.hpp"
#include <buffer.hpp>

namespace core {
namespace graphics {
    // Buffer1D
    // Buffer2D
    // Buffer3D
    // BufferCube
    // BufferSphere
    // BufferArray
    
    class Buffer
    {
    private:
        size_t width;
        size_t height;
        size_t depth;
        core::Buffer::Shared buffer;
    public:
        Buffer( size_t width , size_t height, size_t depth , core::Buffer::Shared buffer );
    };
        
} // graphicsns
} // corens

#endif // BUFFER_H_123_

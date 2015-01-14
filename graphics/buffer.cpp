/*
 * buffer
 *
 */

#include "buffer.hpp"

namespace core {
namespace graphics {
    
    Buffer::Buffer( size_t width , size_t height , size_t depth , core::Buffer::Shared buffer )
    : width(width)
    , height(height)
    , depth(depth)
    , buffer(buffer)
    {
    }
    
} // graphicsns
} // corens

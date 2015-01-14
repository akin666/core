/*
 * buffer
 *
 */

#include "buffer.hpp"

namespace core {
    
    Buffer::Buffer( size_t size )
    : data( new Byte[size] )
    , totalSize(size)
    {
    }
    
    Buffer::~Buffer()
    {
        delete[] data;
        data = nullptr;
    }
    
    size_t Buffer::size() const
    {
        return totalSize;
    }
    
    Byte *Buffer::get() const
    {
        return data;
    }
} // corens

/*
 * BUFFER
 *
 *  Created on: 1.7.2012
 *      Author: akin
 *
 *      defines common gfx types.
 */

#ifndef CCCBUFFER_H_123_
#define CCCBUFFER_H_123_

#include <types.hpp>

namespace core {
    class Buffer
    {
    public:
        using Shared = std::shared_ptr<Buffer>;
    private:
        Byte *data;
        size_t totalSize;
    public:
        Buffer( size_t size );
        virtual ~Buffer();
        
        size_t size() const;
        Byte *get() const;
    };
} // corens

#endif // CCCBUFFER_H_123_

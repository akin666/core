/*
 * Memory
 *
 *  Created on: 1.7.2012
 *      Author: akin
 *
 *      defines common gfx types.
 */

#ifndef CCCMEMORY_H_123_
#define CCCMEMORY_H_123_

#include <types.hpp>

namespace core {
    class Memory
    {
    public:
        using Shared = std::shared_ptr<Memory>;
    protected:
        Byte *ptr;
        Byte *data;
        size_t totalSize;
    public:
        Memory();
        ~Memory();
        
        void init( size_t size , size_t alignment );
        Byte *get() const;
        size_t size() const;
        bool ok() const;
        
        template <class CType> void init( size_t count , size_t alignment = std::alignment_of<CType>::value )
        {
            init( count * sizeof(CType) , alignment );
        }
        
        template <class CType> size_t size() const
        {
            return totalSize / sizeof(CType);
        }
        
        template <class CType> CType *get() const
        {
            return (CType*)data;
        }
    };
} // corens

#endif // CCCMEMORY_H_123_

/*
 * Memory
 *
 */

#include "memory.hpp"
#include <exceptions/cannot.hpp>

namespace core {
    
    Memory::Memory()
    : ptr( nullptr )
    , data( nullptr )
    , totalSize( 0 )
    {
    }
    
    Memory::~Memory()
    {
        delete[] ptr;
        ptr = nullptr;
        data = nullptr;
    }
    
    void Memory::init( size_t size , size_t alignment )
    {
        if( ptr != nullptr )
        {
            throw Cannot("Memory Already allocated.");
        }
        
        totalSize = size;
        ptr = new Byte[size + alignment];
        data = (Byte*)((alignment - ((long)ptr % (long)alignment)) + ptr);
    }
    
    size_t Memory::size() const
    {
        return totalSize;
    }
    
    Byte *Memory::get() const
    {
        return data;
    }
    
    bool Memory::ok() const
    {
        return data != nullptr;
    }
} // corens

/* 
 * File:   OutOfBoundsException
 * Author: akin
 *
 * Created on 15.1.2015
 */

#include "outofbounds.hpp"

namespace core  {
    OutOfBounds::OutOfBounds( std::string msg )
    : msg("Out of bounds Exception: " + msg)
    {
        
    }
    
    OutOfBounds::~OutOfBounds()
    {
    }
    
    const char* OutOfBounds::what() const throw()
    {
    	return msg.c_str();
    }
} // corens


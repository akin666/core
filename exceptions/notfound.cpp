/* 
 * File:   NotFoundException
 * Author: akin
 *
 * Created on 15.1.2015
 */

#include "notfound.hpp"

namespace core  {
    NotFound::NotFound( std::string msg )
    : msg("NotFoundException: " + msg)
    {
    }
    
    NotFound::~NotFound()
    {
    }
    
    const char* NotFound::what() const throw()
    {
    	return msg.c_str();
    }
} // corens


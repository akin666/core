/* 
 * File:   Error
 * Author: akin
 *
 * Created on 16.1.2015
 */

#include "error.hpp"

namespace core  {
    Error::Error( std::string msg )
    : msg("Error Exception: " + msg)
    {
    }
    
    Error::~Error()
    {
    }
    
    const char* Error::what() const throw()
    {
    	return msg.c_str();
    }
} // corens


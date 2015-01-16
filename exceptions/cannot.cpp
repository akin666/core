/* 
 * File:   Cannot
 * Author: akin
 *
 * Created on 16.1.2015
 */

#include "cannot.hpp"

namespace core  {
    Cannot::Cannot( std::string msg )
    : msg(msg)
    {
    }
    
    Cannot::~Cannot()
    {
    }
    
    const char* Cannot::what() const throw()
    {
    	return msg.c_str();
    }
} // corens


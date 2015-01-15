/* 
 * File:   NotImplemented
 * Author: akin
 *
 * Created on 15.1.2015
 */

#include "notimplemented.HPP"

namespace core  {
    NotImplemented::NotImplemented( std::string msg )
    : msg(msg)
    {
    }
    
    NotImplemented::~NotImplemented()
    {
    }
    
    const char* NotImplemented::what() const throw()
    {
    	return msg.c_str();
    }
} // corens


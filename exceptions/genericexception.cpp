/* 
 * File:   genericexception.hpp
 * Author: akin
 *
 * Created on 15.1.2015
 */

#include "genericexception.hpp"

namespace core  {
    GenericException::GenericException( std::string msg )
    : msg(msg)
    {
    }
    
    GenericException::~GenericException()
    {
    }
    
    const char* GenericException::what() const throw()
    {
    	return msg.c_str();
    }
} // corens


/* 
 * File:   genericexception.hpp
 * Author: akin
 *
 * Created on 20. lokakuuta 2014, 21:10
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


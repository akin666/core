/* 
 * File:   exception
 * Author: akin
 *
 * Created on 15.1.2015
 */

#include "exception.hpp"

namespace core  {
    Exception::~Exception()
    {
    }
    
    const char* Exception::what() const throw()
    {
    	return "Unknown exception.";
    }
} // corens


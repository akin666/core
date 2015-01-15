/* 
 * File:   exception
 * Author: akin
 *
 * Created on 20. lokakuuta 2014, 21:10
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


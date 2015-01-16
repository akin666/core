/* 
 * File:   InvalidType
 * Author: akin
 *
 * Created on 15.1.2015
 */

#include "invalidtype.hpp"

namespace core  {
    InvalidType::InvalidType( std::string msg )
    : msg("Invalid type Exception: " + msg)
    {
    }
    
    InvalidType::~InvalidType()
    {
    }
    
    const char* InvalidType::what() const throw()
    {
    	return msg.c_str();
    }
} // corens


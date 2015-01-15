/* 
 * File:   exception
 * Author: akin
 *
 * Created on 15.1.2015, 21:10
 *
 * Wraps standard exception, and
 * is the base class for all core::Exceptions
 */

#ifndef CCCEXCEPTION_HPP
#define	CCCEXCEPTION_HPP

#include <exception>
#include <stdexcept>

namespace core  {

    class Exception : public std::exception
    {
    public:
        virtual ~Exception();
    
        virtual const char* what() const throw();
    };

} // corens

#endif	// CCCEXCEPTION_HPP

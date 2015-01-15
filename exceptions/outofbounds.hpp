/* 
 * File:   OutOfBoundsException
 * Author: akin
 *
 * Created on 15.1.2015
 *
 */

#ifndef CCC_OUTOFBOUNDS_EXCEPTION_HPP
#define	CCC_OUTOFBOUNDS_EXCEPTION_HPP

#include "exception.hpp"
#include <string>

namespace core  {

    class OutOfBounds : public std::exception
    {
    private:
        std::string msg;
    public:
        OutOfBounds( std::string msg );
        virtual ~OutOfBounds();
    
        virtual const char* what() const throw();
    };

} // corens

#endif	// CCC_OUTOFBOUNDS_EXCEPTION_HPP

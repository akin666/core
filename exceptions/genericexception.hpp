/* 
 * File:   genericexception
 * Author: akin
 *
 * Created on 15.1.2015
 *
 * Generic exception that should be specialized.
 */

#ifndef CCC_GENERIC_EXCEPTION_HPP
#define	CCC_GENERIC_EXCEPTION_HPP

#include "exception.hpp"
#include <string>

namespace core  {

    class GenericException : public Exception
    {
    private:
        std::string msg;
    public:
        GenericException( std::string msg );
        virtual ~GenericException();
    
        virtual const char* what() const throw();
    };

} // corens

#endif	// CCC_GENERIC_EXCEPTION_HPP

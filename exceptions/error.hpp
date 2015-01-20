/* 
 * File:   Error
 * Author: akin
 *
 * Created on 16.1.2015
 *
 */

#ifndef CCC_ERROR_EXCEPTION_HPP
#define	CCC_ERROR_EXCEPTION_HPP

#include "exception.hpp"
#include <string>

namespace core  {

    class Error : public Exception
    {
    private:
        std::string msg;
    public:
        Error( std::string msg );
        virtual ~Error();
    
        virtual const char* what() const throw();
    };

} // corens

#endif	// CCC_ERROR_EXCEPTION_HPP

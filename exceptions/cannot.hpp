/* 
 * File:   Cannot
 * Author: akin
 *
 * Created on 16.1.2015
 *
 */

#ifndef CCC_CANNOT_EXCEPTION_HPP
#define	CCC_CANNOT_EXCEPTION_HPP

#include "exception.hpp"
#include <string>

namespace core  {

    class Cannot : public Exception
    {
    private:
        std::string msg;
    public:
        Cannot( std::string msg );
        virtual ~Cannot();
    
        virtual const char* what() const throw();
    };

} // corens

#endif	// CCC_CANNOT_EXCEPTION_HPP

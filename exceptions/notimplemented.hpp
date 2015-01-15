/* 
 * File:   NotImplemented
 * Author: akin
 *
 * Created on 15.1.2015
 *
 */

#ifndef CCC_NOTIMPLEMENTED_EXCEPTION_HPP
#define	CCC_NOTIMPLEMENTED_EXCEPTION_HPP

#include "exception.hpp"
#include <string>

namespace core  {

    class NotImplemented : public Exception
    {
    private:
        std::string msg;
    public:
        NotImplemented( std::string msg );
        virtual ~NotImplemented();
    
        virtual const char* what() const throw();
    };

} // corens

#endif	// CCC_NOTIMPLEMENTED_EXCEPTION_HPP

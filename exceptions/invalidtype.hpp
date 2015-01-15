/* 
 * File:   InvalidType
 * Author: akin
 *
 * Created on 15.1.2015
 *
 */

#ifndef CCC_INVALIDTYPE_EXCEPTION_HPP
#define	CCC_INVALIDTYPE_EXCEPTION_HPP

#include "exception.hpp"
#include <string>

namespace core  {

    class InvalidType : public Exception
    {
    private:
        std::string msg;
    public:
        InvalidType( std::string msg );
        virtual ~InvalidType();
    
        virtual const char* what() const throw();
    };

} // corens

#endif	// CCC_INVALIDTYPE_EXCEPTION_HPP

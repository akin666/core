/* 
 * File:   NotFound
 * Author: akin
 *
 * Created on 15.1.2015
 *
 */

#ifndef CCC_NOTFOUND_EXCEPTION_HPP
#define	CCC_NOTFOUND_EXCEPTION_HPP

#include "exception.hpp"
#include <string>

namespace core  {

    class NotFound : public Exception
    {
    private:
        std::string msg;
    public:
        NotFound( std::string msg );
        virtual ~NotFound();
    
        virtual const char* what() const throw();
    };

} // corens

#endif	// CCC_NOTFOUND_EXCEPTION_HPP

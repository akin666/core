/*
 * cci18n
 *
 *  Created on: 16.1.2015
 *      Author: akin
 */

#include "cci18n.hpp"
#include <exceptions/notimplemented.hpp>

namespace core {
namespace cci18n {
    
    void load( std::string path )
    {
        throw NotImplemented( "cci18n load" );
    }
    
    void save( std::string path )
	{
		throw NotImplemented( "cci18n save" );
    }
    
    void clear()
	{
		throw NotImplemented( "cci18n clear" );
    }
	
	void alias( std::string value , std::string key )
	{
		throw NotImplemented( "cci18n alias" );
	}

} // cci18nns
} // corens
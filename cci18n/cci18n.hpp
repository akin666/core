/*
 * CCI18N
 *
 *  Created on: 16.1.2015
 *      Author: akin
 */

#ifndef CC_I18N_HPP_
#define CC_I18N_HPP_

#include <string>

namespace core {
namespace cci18n {
    
	void load( std::string key , std::string path );
    void save( std::string path );
    void clear();
	
	void setDefault( const std::string& lang );
	
	void alias( std::string value , std::string key );
	
} // cci18nns
} // corens

#endif // CC_I18N_HPP_

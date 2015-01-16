/*
 * CCI18N_TRANSLATE
 *
 *  Created on: 16.1.2015
 *      Author: akin
 */

#ifndef CC_I18N_TRANSLATE_HPP_
#define CC_I18N_TRANSLATE_HPP_

#include <string>

namespace core {
namespace cci18n {
	
	class Translate
	{
	public:
		Translate();
		Translate( std::string lang );
		
		~Translate();
		
		std::string instant( const std::string& key ) const;
		void instant( const std::string& key , std::string& value ) const;
		
		void set( const std::string&key , const std::string& value );
	};
	
} // cci18nns
} // corens

#endif // CC_I18N_TRANSLATE_HPP_

/*
 * CCI18N_TRANSLATE
 *
 *  Created on: 16.1.2015
 *      Author: akin
 */

#ifndef CC_I18N_TRANSLATE_HPP_
#define CC_I18N_TRANSLATE_HPP_

#include "internal.hpp"

namespace core {
namespace cci18n {
	
	class Translate
	{
	private:
		SharedLanguage shared;
		std::string current;
	public:
		Translate();
		explicit Translate( const std::string& lang );
		
		~Translate();
		
		void init( const std::string& lang );
		
		std::string instant( const std::string& key ) const;
		void instant( const std::string& key , std::string& value ) const;
		
		void set( const std::string&key , const std::string& value );
		
		bool ok() const;
		std::string language() const;
	};
	
} // cci18nns
} // corens

#endif // CC_I18N_TRANSLATE_HPP_

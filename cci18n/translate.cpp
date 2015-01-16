/*
 * cci18n
 *
 *  Created on: 16.1.2015
 *      Author: akin
 */

#include "translate.hpp"
#include <exceptions/notimplemented.hpp>

namespace core {
namespace cci18n {
	
	Translate::Translate()
	{
		throw NotImplemented( "cci18n Translate ctor" );
	}
	
	Translate::Translate( std::string lang )
	{
		throw NotImplemented( "cci18n Translate ctor str" );
	}
	
	Translate::~Translate()
	{
	}
	
	std::string Translate::instant( const std::string& key ) const
	{
		throw NotImplemented( "cci18n Translate instant" );
	}
	
	void Translate::instant( const std::string& key , std::string& value ) const
	{
		throw NotImplemented( "cci18n Translate instant ref" );
	}
	
	void Translate::set( const std::string&key , const std::string& value )
	{
		throw NotImplemented( "cci18n Translate set" );
	}

} // cci18nns
} // corens
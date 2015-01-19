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
	
	extern void get( const std::string& key , SharedLanguage& shared );
	extern void getDefaultLanguage( SharedLanguage& shared );
	
	Translate::Translate()
	{
	}
	
	Translate::Translate( const std::string& lang )
	{
		init(lang);
	}
	
	Translate::~Translate()
	{
	}
	
	void Translate::init( const std::string& lang )
	{
		get( lang , shared );
		current = lang;
	}
	
	std::string Translate::instant( const std::string& key ) const
	{
		std::string val;
		instant( key , val );
		return val;
	}
	
	void Translate::instant( const std::string& key , std::string& value ) const
	{
		// try local language
		if( shared )
		{
			try
			{
				auto iter = shared->find( key );
				if( iter != shared->end() )
				{
					value = iter->second;
					return;
				}
			}
			catch (...)
			{
			}
		}
		
		// try default language
		SharedLanguage deflang;
		getDefaultLanguage( deflang );
		try
		{
			auto iter = deflang->find( key );
			if( iter != deflang->end() )
			{
				value = iter->second;
				return;
			}
		}
		catch (...)
		{
		}
		value = "";
	}
	
	void Translate::set( const std::string& key , const std::string& value )
	{
		auto lang = *shared;
		lang[key] = value;
	}
	
	bool Translate::ok() const
	{
		if( shared )
		{
			return true;
		}
		return false;
	}
	
	std::string Translate::language() const
	{
		return current;
	}

} // cci18nns
} // corens
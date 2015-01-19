/*
 * cci18n
 *
 *  Created on: 16.1.2015
 *      Author: akin
 */

#include "cci18n.hpp"
#include <exceptions/notimplemented.hpp>
#include "internal.hpp"

namespace core {
namespace cci18n {
	
	using LanguageMap = std::unordered_map<std::string , SharedLanguage>;
	
	LanguageMap languages;
	std::unordered_map<std::string, std::string> aliases;
	
	std::string defaultLanguageStr = "EN_gb";
	SharedLanguage defaultLanguage;
	
	void get( const std::string& key , SharedLanguage& shared )
	{
		auto iter = languages.find( key );
		if( iter != languages.end() )
		{
			// found..
			shared = iter->second;
			return;
		}
		
		auto aliasiter = aliases.find( key );
		if( aliasiter != aliases.end() )
		{
			auto iter = languages.find( aliasiter->second );
			if( iter != languages.end() )
			{
				// found..
				shared = iter->second;
				return;
			}
		}
		
		// not found..
		shared.reset();
	}
	
	void getDefaultLanguage( SharedLanguage& shared )
	{
		shared = defaultLanguage;
	}
	
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
	
	void setDefault( const std::string& lang )
	{
		defaultLanguageStr = lang;
		
		try
		{
			get( defaultLanguageStr , defaultLanguage );
		}
		catch( ... )
		{
			defaultLanguage.reset();
		}
	}
	
	void alias( std::string value , std::string key )
	{
		aliases[key] = value;
	}

} // cci18nns
} // corens
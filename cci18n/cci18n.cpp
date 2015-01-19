/*
 * cci18n
 *
 *  Created on: 16.1.2015
 *      Author: akin
 */

#include "cci18n.hpp"
#include <exceptions/notimplemented.hpp>
#include <exceptions/notfound.hpp>
#include <exceptions/error.hpp>
#include "internal.hpp"

#include <json/json.h>
#include <fstream>

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
	
	void handle( std::string path , const Json::Value& value , Language& language )
	{
		if( value.isObject() )
		{
			auto childs = value.getMemberNames();
			
			for( auto key : childs )
			{
				handle( path + "." + key , value[key] , language );
			}
			return;
		}
		else if( value.isString() )
		{
			language[path] = value.asString();
		}
		else
		{
			throw NotImplemented("Json parsing does not implement this.");
		}
	}
	
	void handleRoot( const Json::Value& value , Language& language )
	{
		if( value.isObject() )
		{
			auto childs = value.getMemberNames();
			for( auto key : childs )
			{
				handle( key , value[key] , language );
			}
		}
	}
	
    void load( std::string key , std::string path )
    {
		Json::Value root;
		Json::Reader reader;
		
		std::ifstream in(path);
		
		if( !in.is_open() )
		{
			throw NotFound(path);
		}
		
		if( !reader.parse( in , root , false ) )
		{
			throw Error(reader.getFormatedErrorMessages());
		}
		
		SharedLanguage slanguage;
		
		get( key , slanguage );
		
		if( !slanguage )
		{
			slanguage = std::make_shared<Language>();
			languages[key] = slanguage;
		}
		
		handleRoot( root , *slanguage );
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
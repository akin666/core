/*
 * config
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#ifndef CONFIG_ABC_HPP_
#define CONFIG_ABC_HPP_

#include <types.hpp>

namespace core {
namespace config {
    
    void load( std::string path );
    void save( std::string path );
    void clear();
    
    template <class TClass> TClass get( const std::string& path , TClass def )
    {
        try
        {
            return get<TClass>(path);
        }
        catch( ... )
        {
        }
        return def;
    }
    template <class TClass> TClass get( const std::string& path ) { throw ""; }
    template <class TClass> void set( const std::string& path , TClass value ) {}
    
    // specializations
    /// get
    template <> int get<int>( const std::string& path );
    template <> float get<float>( const std::string& path );
    template <> std::string get<std::string>( const std::string& path );
    template <> bool get<bool>( const std::string& path );
    
    /// set
    template <> void set<int>( const std::string& path , int value );
    template <> void set<float>( const std::string& path , float value );
    template <> void set<std::string>( const std::string& path , std::string value );
    template <> void set<bool>( const std::string& path , bool value );
    
} // configns
} // corens

#endif // CONFIG_ABC_HPP_

/*
 * config
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#include <config.hpp>
#include <unordered_map>
#include <vector>
#include <exceptions/notfound.hpp>
#include <exceptions/invalidtype.hpp>
#include <exceptions/outofbounds.hpp>
#include <exceptions/genericexception.hpp>

namespace core {
namespace config {
    
    enum Type
    {
        INTEGER,
        FLOAT,
        BOOL,
        STRING
    };
    
    class Entry
    {
    public:
        Type type;
        size_t index;
    };
    
    std::unordered_map<std::string, Entry> data;
    std::vector<int> integers;
    std::vector<float> floats;
    std::vector<bool> bools;
    std::vector<std::string> strings;
    
    void load( std::string path )
    {
		// Go through config,
		// save things with '.' notation.. like
		// Settings.Screen.Height
		// Settings.Screen.Width
        throw GenericException( "Config Failed to load " + path );
    }
    
    void save( std::string path )
    {
        throw GenericException( "Config Failed to save to " + path );
    }
    
    void clear()
    {
        data.clear();
        integers.clear();
        floats.clear();
        bools.clear();
        strings.clear();
    }
    
    // specializations
    /// get
    template <> int get<int>( const std::string& path )
    {
        auto iter = data.find(path);
        
        if( iter == data.end() )
        {
            throw NotFound("Config index Not found: " + path );
        }
        const auto& entry = iter->second;
        
        if( entry.type != INTEGER )
        {
            throw InvalidType("Config invalid type requested: " + path );
        }
        
        auto& vec = integers;
        if( vec.size() > entry.index )
        {
            throw OutOfBounds("Config invalid type index requested: " + path );
        }
        
        return vec[entry.index];
    }
    
    template <> float get<float>( const std::string& path )
    {
        auto iter = data.find(path);
        
        if( iter == data.end() )
        {
            throw NotFound("Config index Not found: " + path );
        }
        const auto& entry = iter->second;
        
        if( entry.type != FLOAT )
        {
            throw InvalidType("Config invalid type requested: " + path );
        }
        
        auto& vec = floats;
        if( vec.size() > entry.index )
        {
            throw OutOfBounds("Config invalid type index requested: " + path );
        }
        
        return vec[entry.index];
    }
    
    template <> std::string get<std::string>( const std::string& path )
    {
        auto iter = data.find(path);
        
        if( iter == data.end() )
        {
            throw NotFound("Config index Not found: " + path );
        }
        const auto& entry = iter->second;
        
        if( entry.type != STRING )
        {
            throw InvalidType("Config invalid type requested: " + path );
        }
        
        auto& vec = strings;
        if( vec.size() > entry.index )
        {
            throw OutOfBounds("Config invalid type index requested: " + path );
        }
        
        return vec[entry.index];
    }
    
    template <> bool get<bool>( const std::string& path )
    {
        auto iter = data.find(path);
        
        if( iter == data.end() )
        {
            throw NotFound("Config index Not found: " + path );
        }
        const auto& entry = iter->second;
        
        if( entry.type != BOOL )
        {
            throw InvalidType("Config invalid type requested: " + path );
        }
        
        auto& vec = bools;
        if( vec.size() > entry.index )
        {
            throw OutOfBounds("Config invalid type index requested: " + path );
        }
        
        return vec[entry.index];
    }
    
    /// set
    template <> void set<int>( const std::string& path , int value )
    {
        Type type = INTEGER;
        auto& vec = integers;
        auto iter = data.find(path);
        if( iter == data.end() )
        {
            // new..
            size_t idx = vec.size();
            vec.push_back(value);
            
            data[path] = Entry {
                type,
                idx
            };
            return;
        }
        auto& entry = iter->second;
        if( entry.type != type )
        {
            entry.index = vec.size();
            entry.type = type;
            vec.push_back(value);
            return;
        }
        vec[entry.index] = value;
    }
    
    template <> void set<float>( const std::string& path , float value )
    {
        Type type = FLOAT;
        auto& vec = floats;
        auto iter = data.find(path);
        if( iter == data.end() )
        {
            // new..
            size_t idx = vec.size();
            vec.push_back(value);
            
            data[path] = Entry {
                type,
                idx
            };
            return;
        }
        auto& entry = iter->second;
        if( entry.type != type )
        {
            entry.index = vec.size();
            entry.type = type;
            vec.push_back(value);
            return;
        }
        vec[entry.index] = value;
    }
    
    template <> void set<std::string>( const std::string& path , std::string value )
    {
        Type type = STRING;
        auto& vec = strings;
        auto iter = data.find(path);
        if( iter == data.end() )
        {
            // new..
            size_t idx = vec.size();
            vec.push_back(value);
            
            data[path] = Entry {
                type,
                idx
            };
            return;
        }
        auto& entry = iter->second;
        if( entry.type != type )
        {
            entry.index = vec.size();
            entry.type = type;
            vec.push_back(value);
            return;
        }
        vec[entry.index] = value;
    }
    
    template <> void set<bool>( const std::string& path , bool value )
    {
        Type type = BOOL;
        auto& vec = bools;
        auto iter = data.find(path);
        if( iter == data.end() )
        {
            // new..
            size_t idx = vec.size();
            vec.push_back(value);
            
            data[path] = Entry {
                type,
                idx
            };
            return;
        }
        auto& entry = iter->second;
        if( entry.type != type )
        {
            entry.index = vec.size();
            entry.type = type;
            vec.push_back(value);
            return;
        }
        vec[entry.index] = value;
    }

} // configns
} // corens
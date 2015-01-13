/*
 * config
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#include "config"
#include <unordered_map>
#include <vector>

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
        throw "";
    }
    
    void save( std::string path )
    {
        throw "";
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
            throw "not found";
        }
        const auto& entry = iter->second;
        
        if( entry.type != INTEGER )
        {
            throw "invalid type";
        }
        
        auto& vec = integers;
        if( vec.size() > entry.index )
        {
            throw "invalid index";
        }
        
        return vec[entry.index];
    }
    
    template <> float get<float>( const std::string& path )
    {
        auto iter = data.find(path);
        
        if( iter == data.end() )
        {
            throw "not found";
        }
        const auto& entry = iter->second;
        
        if( entry.type != FLOAT )
        {
            throw "invalid type";
        }
        
        auto& vec = floats;
        if( vec.size() > entry.index )
        {
            throw "invalid index";
        }
        
        return vec[entry.index];
    }
    
    template <> std::string get<std::string>( const std::string& path )
    {
        auto iter = data.find(path);
        
        if( iter == data.end() )
        {
            throw "not found";
        }
        const auto& entry = iter->second;
        
        if( entry.type != STRING )
        {
            throw "invalid type";
        }
        
        auto& vec = strings;
        if( vec.size() > entry.index )
        {
            throw "invalid index";
        }
        
        return vec[entry.index];
    }
    
    template <> bool get<bool>( const std::string& path )
    {
        auto iter = data.find(path);
        
        if( iter == data.end() )
        {
            throw "not found";
        }
        const auto& entry = iter->second;
        
        if( entry.type != BOOL )
        {
            throw "invalid type";
        }
        
        auto& vec = bools;
        if( vec.size() > entry.index )
        {
            throw "invalid index";
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
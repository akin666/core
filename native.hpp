/*
 * native
 *
 *  Created on: 16.6.2012
 *      Author: akin
 *      
 *   Native platform functions.
 *      
 */

#ifndef COMMONNATIVE_H_
#define COMMONNATIVE_H_

#include <types.hpp>
#include <graphics/buffer2d.hpp>
#include <graphics/graphics.hpp>

#ifndef OS_NOT_DETECTED
# define USE_COMMON_NATIVELIB
#endif

namespace core {
namespace native  {
    
	void log( const std::string& hint , std::string message );
	
	std::string getPath( std::string location );
	
	bool load( std::string path , std::string& content );
	//bool save( std::string path , std::string& content );
	
	template <class PixelType> bool load( std::string path , graphics::Buffer2D<PixelType>& buffer ) { return false; }
    template <> bool load( std::string path , graphics::Buffer2D<graphics::RGBALow>& buffer );
	
	template <class PixelType> bool save( std::string path , graphics::Buffer2D<PixelType>& buffer ) { return false; }
	template <> bool save( std::string path , graphics::Buffer2D<graphics::RGBALow>& buffer );
} // nativens
} // corens

#endif // COMMONNATIVE_H_

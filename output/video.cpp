//
//  outputvideo.cpp
//  Tracker
//
//  Created by mikael korpela on 03/11/14.
//  Copyright (c) 2014 mikael korpela. All rights reserved.
//

#include "video.hpp"
#include <native.hpp>
#include <cstdlib>

namespace core {
namespace output {
	
bool Video::init( std::string name, std::string path , size_t width , size_t height , graphics::Format inputformat , int dpi , int framerate )
{
	if( out.is_open() )
	{
		return false;
	}
	
	this->name = name;
	
	const char* pixelformat = graphics::getName(inputformat);
	
	if( pixelformat == nullptr )
	{
		return false;
	}
	
	this->width = width;
	this->height = height;
	
	// filename to contain
	// [NAME]_ENC_[WIDTH]x[HEIGHT]_[DPI]_[PIXELFORMAT]_fr[FRAMERATE].yuv
	const int maxbuffer = 512;
	char buffer[ maxbuffer ];
	snprintf( buffer, (maxbuffer - 1), "%s_ENC_%zux%zu_%d_%s_fr%d" , path.c_str() , width , height , dpi , pixelformat , framerate );
	
	filename = buffer;
	
	out.open( filename + ".yuv" , std::ios::out | std::ios::binary );
	
	return true;
}
	
void Video::append( const void *pixels , size_t count )
{
	out.write( (const char*)pixels, count );
}

void Video::close()
{
	// ffmpeg -s 384x216 -i test.yuv -vcodec libx264 test.h264
	
	std::string infile = filename + ".yuv";
	std::string outfile = filename + ".h264";
	
	const int maxbuffer = 1024;
	char buffer[ maxbuffer ];
	snprintf( buffer, (maxbuffer - 1), "ffmpeg -s %zux%zu %s -vcodec libx264 %s" , width , height , infile.c_str() , outfile.c_str() );
	
	std::system( buffer );
	
	out.close();
}

std::string Video::getName() const
{
	return name;
}
	
} // outputns
} // corens

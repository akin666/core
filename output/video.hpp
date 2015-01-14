//
//  outputvideo
//
//  Created by mikael korpela on 03/11/14.
//  Copyright (c) 2014 mikael korpela. All rights reserved.
//

#ifndef CORE_outputvideo_hpp
#define CORE_outputvideo_hpp

#include <fstream>
#include <iostream>
#include <graphics/pixelformat.hpp>
#include <types.hpp>

namespace core {
namespace output {

class Video
{
private:
	std::ofstream out;
	std::string name;
public:
	bool init(std::string name, std::string path , int width , int height , graphics::Format inputformat , int dpi , int framerate );
	void append( const void *pixels , size_t count );
	void close();

	std::string getName() const;
};
    
} // outputns
} // corens

#endif

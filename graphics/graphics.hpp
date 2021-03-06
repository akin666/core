/*
 * GRAPHICS_H
 *
 *  Created on: 1.7.2012
 *      Author: akin
 *
 *      defines common gfx types.
 */

#ifndef GRAPHICS_H_123_
#define GRAPHICS_H_123_

#include <glm/glm.hpp>

#include <types.hpp>
#include "tcolor.hpp"

namespace core {

// well, I think core should have "Color"
using Color = glm::vec3;
	
namespace graphics {

//using Color = TColor3<float32>;

using RGBAHigh = TColor4<float32>;
using RGBALow = TColor4<uint8>;

using YUVHigh = TColor3<float32>;
using YUVLow = TColor3<uint8>;
    
} // graphicsns
} // corens
    
#endif // GRAPHICS_H_123_

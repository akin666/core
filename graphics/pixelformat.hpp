/*
 * PIXELFORMAT_H_123_
 *
 *  Created on: 1.7.2012
 *      Author: akin
 *
 *      defines standard color types.
 */

#ifndef PIXELFORMAT_H_123_
#define PIXELFORMAT_H_123_

#include <iostream>

namespace core {
namespace graphics {

enum Channels
{
	NONE = 		0x000000,
	RED = 		0x000001,
	GREEN = 	0x000002,
	BLUE = 		0x000004,
	ALPHA = 	0x000008,
	LUMINANCE = 0x000010,
	INTENSITY = 0x000020,
	STENCIL = 	0x000040,
	DEPTH = 	0x000080,
	
	CHANNEL_MAX = DEPTH,

	RGB = RED | GREEN | BLUE,
	RGBD = RGB | DEPTH,
	RGBS = RGB | STENCIL,
	RGBDS = RGBD | STENCIL,

	RGBA = RGB | ALPHA,
	RGBAD = RGBA | DEPTH,
	RGBAS = RGBA | STENCIL,
	RGBADS = RGBAD | STENCIL,
};

enum Format
{
	ALPHA8 = 	1,
	ALPHA16 = 	2,
	ALPHA32 = 	3,
	ALPHA64 = 	4,
	
	LUMINANCE8 = 32,
	LUMINANCE16 = 33,
	LUMINANCE32 = 34,
	
	INTENSITY8 = 64,
	INTENSITY16 = 65,
	INTENSITY32 = 66,
	
	RGB8 = 		96,
	RGBA8 = 	97,
	ARGB8 = 	98,
	RGBA12 = 	99,
	RGBA16 = 	100,
	RGBA32 = 	101,
	RGBA32F = 	102,
	RGBA64F = 	103,
	RGB565 = 	104,
	RGBA4 = 	105,
	RGBA5551 = 	106,
	
	DEPTH8 = 	128,
	DEPTH16 = 	129,
	DEPTH24 = 	130,
	DEPTH32 = 	131,
	
	STENCIL8 = 	160,
	STENCIL16 =	161,
	STENCIL24 =	162,
	STENCIL32 =	163,
};

size_t getElementSize( Channels channels );
size_t getByteSize( Format format );
const char *getName( Format format );

} // graphicsns
} // corens

#endif // PIXELFORMAT_H_123_

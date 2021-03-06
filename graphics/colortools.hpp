/*
 * COLORTOOLS
 *
 *  Created on: 1.7.2012
 *      Author: akin
 *
 *      defines common gfx types.
 */

#ifndef COLORTOOLS_H_123_
#define COLORTOOLS_H_123_

#include "graphics.hpp"
#include <glm/gtx/extented_min_max.hpp>

namespace core {
namespace graphics {
    
// HSB
void rgb2hsb( const Color& from , Color& to );
void hsb2rgb( const Color& from , Color& to );

Color rgb2hsb( Color from );
Color hsb2rgb( Color from );

void hsbAdd( const Color& a , const Color& b , Color& out );
void hsbMultiply( const Color& a , float multi , Color& out );

// HSP
void rgb2hsp( const Color& from , Color& to );
void hsp2rgb( const Color& from , Color& to );

Color rgb2hsp( Color from );
Color hsp2rgb( Color from );

// YUV
void rgb2yuv( const Color& from , Color& to );
void yuv2rgb( const Color& from , Color& to );

Color rgb2yuv( Color from );
Color yuv2rgb( Color from );

// YCbCr
void rgb2YCbCr( const Color& from , Color& to );
void YCbCr2rgb( const Color& from , Color& to );

Color rgb2YCbCr( Color from );
Color YCbCr2rgb( Color from );

// Low <=> conversions..
inline void convert( RGBALow& to , const Color& from )
{
	to.r = glm::clamp( from.r , 0.0f ,  1.0f ) * 255.0f;
	to.g = glm::clamp( from.g , 0.0f ,  1.0f ) * 255.0f;
	to.b = glm::clamp( from.b , 0.0f ,  1.0f ) * 255.0f;
	to.a = 0xFF;
}
inline void convert( Color& to , const RGBALow& from )
{
	to.r = from.r / 255.0f;
	to.g = from.g / 255.0f;
	to.b = from.b / 255.0f;
}
inline void convert( Color& to , const YUVLow& from )
{
	Color tmp( (float)from.r / 255.f , (float)from.g / 255.f , (float)from.b / 255.f );
	yuv2rgb( tmp , to );
}
inline void convert( YUVLow& to , const Color& from )
{
	Color tmp;
	rgb2yuv(from, tmp);
	
	to.r = glm::clamp( tmp.r , 0.0f ,  1.0f ) * 255.0f;
	to.g = glm::clamp( tmp.g , 0.0f ,  1.0f ) * 255.0f;
	to.b = glm::clamp( tmp.b , 0.0f ,  1.0f ) * 255.0f;
}
template <class TC> void convert( TC& to , const TC& from )
{
	to = from;
}

inline void lightAttenuation( float distance , Color& intensity )
{
	// distance in real world can be 0.0f, but by adding extremely small number,
	// by introducing some distortion, eliminate this pesky oddity, known as 0.0f
	intensity /= ((distance * distance) + std::numeric_limits<float>::epsilon() );
}

inline float lightMaxDistance( const Color& intensity )
{
	if( intensity.r == 0.0f && intensity.g == 0.0f &&  intensity.b == 0.0f )
	{
		return 0.0f;
	}
	
	return 10.0f;
	auto distance = glm::sqrt((intensity / -std::numeric_limits<float>::epsilon()) / intensity );
	
	return glm::max( distance.r , distance.g , distance.b );
}
    
} // graphicsns
} // corens

#endif // COLORTOOLS_H_123_

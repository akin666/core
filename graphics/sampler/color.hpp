/*
 * ColorSampler
 *
 *  Created on: 21.10.2014
 *      Author: akin
 */

#ifndef CORE_COLORSAMPLER_HPP_
#define CORE_COLORSAMPLER_HPP_

#include "sampler.hpp"

namespace core {
namespace graphics {

class ColorSampler : public Sampler
{
private:
	Color color;
public:
	ColorSampler( Color color )
	: color(color)
	{
	}
	
	virtual ~ColorSampler()
	{
	}
	
	virtual void at( const float& at , Color& color ) const
	{
		color = this->color;
	}
	
	virtual void at( const glm::vec2& at , Color& color ) const
	{
		color = this->color;
	}
	
	virtual void at( const glm::vec3& at , Color& color ) const
	{
		color = this->color;
	}
};
    
} // graphicsns
} // corens
    
#endif // CORE_COLORSAMPLER_HPP_

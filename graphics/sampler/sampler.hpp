/*
 * Sampler
 *
 *  Created on: 21.10.2014
 *      Author: akin
 */

#ifndef CORE_SAMPLER_HPP_
#define CORE_SAMPLER_HPP_

#include <types.hpp>
#include <graphics/graphics.hpp>

namespace core {

class Sampler
{
public:
	using Shared = std::shared_ptr<Sampler>;
public:
	virtual ~Sampler()
	{
	}
	
	virtual void at( const float& at , Color& color ) const {}
	virtual void at( const glm::vec2& at , Color& color ) const {}
	virtual void at( const glm::vec3& at , Color& color ) const {}
};
    
} // corens

#endif // CORE_SAMPLER_HPP_

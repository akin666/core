/*
 * ray.hpp
 *
 *  Created on: 24.10.2014
 *      Author: akin
 */

#ifndef CORE_RAY_HPP_
#define CORE_RAY_HPP_

#include <core.hpp>

namespace core {
	class Ray
	{
	public:
		Ray()
		: position( 0.0f , 0.0f , 0.0f )
		, direction( 0.0f , 0.0f , 1.0f )
		{}

		Ray( const glm::vec3& position , const glm::vec3& direction )
		: position(position)
		, direction(direction)
		{}

		glm::vec3 position;
		glm::vec3 direction;
	};
} // corens

#endif // APP_RAY_HPP_

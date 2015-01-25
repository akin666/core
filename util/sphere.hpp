/*
 * sphere
 *
 *  Created on: 24.10.2014
 *      Author: akin
 */

#ifndef CORE_SPHERE_HPP_
#define CORE_SPHERE_HPP_

#include <glm/glm.hpp>

namespace core {
	class Sphere
	{
	public:
		Sphere()
		: position( 0.0f , 0.0f , 0.0f )
		, r( 1.0f )
		{}

		Sphere( const glm::vec3& position , float r )
		: position(position)
		, r( r )
		{}

		glm::vec3 position;
		float r;
	};
} // corens

#endif // CORE_SPHERE_HPP_

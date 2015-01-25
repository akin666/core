/*
 * collision
 *
 *  Created on: 24.10.2014
 *      Author: akin
 */

#ifndef CORE_COLLISION_HPP_
#define CORE_COLLISION_HPP_

#include <glm/glm.hpp>

namespace core {
	class Collision
	{
	public:
		Collision()
		: position( 0.0f , 0.0f , 0.0f )
		, normal( 0.0f , 0.0f , 1.0f )
		{}

		Collision( const glm::vec3& position , const glm::vec3& normal )
		: position(position)
		, normal(normal)
		{}

		glm::vec3 position;
		glm::vec3 normal;
	};
} // corens

#endif // CORE_COLLISION_HPP_

/*
 * box
 *
 *  Created on: 24.10.2014
 *      Author: akin
 */

#ifndef CORE_BOX_HPP_
#define CORE_BOX_HPP_

#include <glm/glm.hpp>

namespace core {
	class Box
	{
	public:
		Box()
		: position( 0.0f , 0.0f , 0.0f )
		, direction( 0.0f , 0.0f , 1.0f )
		{}

		Box( const glm::vec3& position , const glm::vec3& direction )
		: position(position)
		, direction(direction)
		{}

		glm::vec3 position;
		glm::vec3 direction;
	};
} // corens

#endif // CORE_BOX_HPP_

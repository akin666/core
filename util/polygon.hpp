/*
 * polygon
 *
 *  Created on: 24.10.2014
 *      Author: akin
 */

#ifndef CORE_POLYGON_HPP_
#define CORE_POLYGON_HPP_

#include <glm/glm.hpp>

namespace core {
	class Polygon
	{
	public:
		Polygon()
		: position( 0.0f , 0.0f , 0.0f )
		{}

		Polygon( const glm::vec3& position )
		: position(position)
		{}

		glm::vec3 position;
	};
} // corens

#endif // CORE_POLYGON_HPP_

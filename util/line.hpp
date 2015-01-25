/*
 * line
 *
 *  Created on: 24.10.2014
 *      Author: akin
 */

#ifndef CORE_LINE_HPP_
#define CORE_LINE_HPP_

#include <glm/glm.hpp>

namespace core {
	class Line
	{
	public:
		Line()
		: position( 0.0f , 0.0f , 0.0f )
		, position2( 0.0f , 0.0f , 1.0f )
		{}

		Line( const glm::vec3& position , const glm::vec3& position2 )
		: position(position)
		, position2(position2)
		{}

		glm::vec3 position;
		glm::vec3 position2;
	};
} // corens

#endif // CORE_LINE_HPP_

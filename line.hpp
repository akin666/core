/*
 * line
 *
 *  Created on: 24.10.2014
 *      Author: akin
 */

#ifndef APP_LINE_HPP_
#define APP_LINE_HPP_

#include <core.hpp>

namespace core {
	class Line
	{
	public:
		Line()
		: p1( 0.0f , 0.0f , 0.0f )
		, p2( 0.0f , 0.0f , 1.0f )
		{}

		Line( const glm::vec3& position , const glm::vec3& position2 )
		: p1(position)
		, p2(position2)
		{}

		glm::vec3 p1;
		glm::vec3 p2;
	};
} // corens

#endif // APP_LINE_HPP_

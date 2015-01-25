/*
 * resolve
 *
 *  Created on: 24.10.2014
 *      Author: akin
 */

#ifndef CORE_RESOLVE_HPP_
#define CORE_RESOLVE_HPP_

#include <glm/glm.hpp>
#include "ray.hpp"
#include "collision.hpp"

namespace core {
    
    template <class tfloat = float>
    bool resolveRaySphere( const Ray& ray , const glm::vec3& position , float radius , Collision& resolution )
    {
        const glm::vec3 relation = ray.position - position;
        tfloat s = glm::dot(relation , ray.direction);
        tfloat l2 = glm::dot(relation , relation);
        
        tfloat s2 = s * s;
        tfloat r2 = radius * radius;
        tfloat m2 = l2 - s2;
        
        if( (s < 0.0f && l2 > r2) || (m2 > r2) )
        {
            return false;
        }
        
        tfloat q = glm::sqrt( r2 - m2 );
        tfloat t = (l2 > r2) ? (s - q) : (s + q);
        
        resolution.position = ray.position + (ray.direction * t);
        
        return true;
    }
    
    template <class tfloat = float>
    bool resolveRayBox( const Ray& ray , Collision& resolution )
    {
        return false;
    }
} // corens

#endif // CORE_RESOLVE_HPP_

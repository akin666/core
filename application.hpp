/* 
 * File:   application.hpp
 * Author: akin
 *
 * Created on 20. lokakuuta 2014, 21:10
 */

#ifndef APPLICATION_HPP
#define	APPLICATION_HPP

#include <types.hpp>

namespace core  {
	class Application
	{
	public:
		using Shared = std::shared_ptr<Application>;
	public:
		virtual ~Application()
		{
		}
    
		virtual bool init()
		{
			return true;
		}
    
		virtual void run()
		{
		}
    
		virtual bool complete()
		{
			return true;
		}
    
		virtual std::string getName() const
		{
			return "unknown";
		}
	};
} // corens

#endif	// APPLICATION_HPP 

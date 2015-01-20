
#ifndef ACTION_INTERFACE_HPP
#define ACTION_INTERFACE_HPP

namespace core {

	class Action
	{
	public:
		virtual ~Action(){}
		virtual void execute(){}
	};
	
} // corens

#endif

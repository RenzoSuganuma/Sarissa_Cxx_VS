#ifndef _ACTION_H_
#define _ACTION_H_

#include "functional"
#include "list"

class SarissaAction
{
private:
	std::list< std::function< void() > > actions_;

public:
	SarissaAction() {}
	~SarissaAction() {}

	std::list< std::function< void() > >&
		const GetAction()
	{
		return actions_;
	}

	void const ClearActions()
	{
		actions_.clear();
	}

	std::list< std::function< void() > >::iterator
		const Begin() 
	{
		return actions_.begin();
	}

	std::list< std::function< void() > >::iterator
		const End()
	{
		return actions_.end();
	}

	std::list< std::function< void() > >::iterator
		const AddAction(const std::function< void() >& action)
	{
		actions_.emplace_back(action);
		auto it = actions_.end();
		it--;
		return it;
	}

	void const RemoveAction(const std::list< std::function< void() > >::iterator& iterator)
	{
		actions_.erase(iterator);
	}

	void const Invoke()
	{
		auto it = actions_.begin();

		while (it != actions_.end())
		{
			(*it)();
			++it;
		}
	}
};

#endif // !_ACTION_H_

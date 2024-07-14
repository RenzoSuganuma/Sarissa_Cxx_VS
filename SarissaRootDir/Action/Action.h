#pragma once

#include "functional"
#include "list"

namespace Sarissa
{
	namespace Action
	{
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

			auto const Begin()
			{
				return actions_.begin();
			}

			auto const End()
			{
				return actions_.end();
			}

			auto const AddAction(const std::function< void() >& action)
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
	}
}

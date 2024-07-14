#pragma once

#include "ISarissaSMState.h"

namespace Sarissa
{
	namespace StateMachine
	{
		struct StateMachineTransition
		{
		private:
			Sarissa::StateMachine::IStateMachineState& from_;
			Sarissa::StateMachine::IStateMachineState& to_;
			int id_;

		public:
			StateMachineTransition(Sarissa::StateMachine::IStateMachineState& from
				, Sarissa::StateMachine::IStateMachineState& to, int id) : from_(from), to_(to), id_(id) { }

			~StateMachineTransition() {}

			const Sarissa::StateMachine::IStateMachineState& const GetStateFrom() const
			{
				return from_;
			}

			const Sarissa::StateMachine::IStateMachineState& const GetStateTo() const
			{
				return from_;
			}

			const int GetId() const
			{
				return id_;
			}
		};
	}
}

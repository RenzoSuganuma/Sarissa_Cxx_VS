#pragma once

namespace Sarissa
{
	namespace StateMachine
	{
		class IStateMachineState
		{
		public:
			virtual void StartState();

			virtual void UpdateState();

			virtual void EndState();
		};
	}
}

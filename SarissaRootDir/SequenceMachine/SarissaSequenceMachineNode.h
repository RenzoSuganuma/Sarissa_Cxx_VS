#pragma once

#include "functional"
#include "list"

namespace Sarissa
{
	namespace SequenceMachine 
	{
		class SarissaSequenceMachineNode
		{
		protected:
			std::list< std::function< void() > > OnNextNodeChanged;
			SarissaSequenceMachineNode* next_;
			int id_;

		public:
			void SetNextNode(SarissaSequenceMachineNode* node)
			{
				next_ = node;
			};

			const SarissaSequenceMachineNode* GetNextNode() const
			{
				return next_;
			}

			void SetId(int id)
			{
				id_ = id;
			}

			int GetId() const 
			{
				return id_;
			}

			virtual void StartNode() = 0;

			virtual void UpdateNode() = 0;

			virtual void EndNode() = 0;
		};
	}
}

#ifndef _SARISSA_BT_NODE_H_
#define _SARISSA_BT_NODE_H_

#include "functional"
#include "list"

namespace Sarissa
{
	namespace MinimalSM 
	{
		class SarissaBTNode
		{
		protected:
			std::list< std::function< void() > > OnNextNodeChanged;
			SarissaBTNode* next_;
			int id_;

		public:
			void SetNextNode(SarissaBTNode* node)
			{
				next_ = node;
			};

			const SarissaBTNode* GetNextNode() const
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

#endif // !_SARISSA_BT_NODE_H_

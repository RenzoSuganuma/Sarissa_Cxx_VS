#ifndef _SARISSA_BT_NODE_
#define _SARISSA_BT_NODE_

#include "functional"
#include "list"

namespace Sarissa {
	namespace MinimalSM {
		class SarissaBTNode {
		protected:
			std::list< std::function< void() > > OnNextNodeChanged;
			SarissaBTNode* next_;
			int id_;


		public:
			void SetNextNode(SarissaBTNode* node);

			const SarissaBTNode* GetNextNode() const;

			void SetId(int id);

			const int GetId() const;

			virtual void StartNode() = 0;

			virtual void UpdateNode() = 0;

			virtual void EndNode() = 0;
		};
	}
}

#endif // !_SARISSA_BT_NODE_

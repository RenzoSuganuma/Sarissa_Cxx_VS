#ifndef _SARISSA_MINI_SM_
#define _SARISSA_MINI_SM_

#include "SarissaBTNode.h"
#include "unordered_map"
#include "iostream"

namespace Sarissa
{
	namespace MinimalSM
	{
		class SarissaMinimalSM final
		{
		private:
			std::unordered_map< int, SarissaBTNode* > nodes_;
			std::unordered_map< int, bool > transitions_;
			int currentNodeId_;
			bool isRunning_;

		public:
			template < typename T >
			void ResistNode(T* node)
			{
				int id = nodes_.size();
				SarissaBTNode* casted = static_cast<SarissaBTNode*> (node);
				if (casted != nullptr) {
					casted->SetId(id);
					nodes_.insert(std::make_pair(casted->GetId(), casted));
				}
			}

			template < typename T1, typename T2 >
			void ApplyTransition(T1* node1, T2* node2)
			{
				SarissaBTNode* casted_node1 = static_cast<SarissaBTNode*> (node1);
				SarissaBTNode* casted_node2 = static_cast<SarissaBTNode*> (node2);

				if (casted_node1 != nullptr && casted_node2 != nullptr) {
					casted_node1->SetNextNode(casted_node2);
					casted_node2->SetNextNode(nullptr);

					transitions_.insert(std::make_pair(casted_node1->GetId(), false));
				}
			}

			void UpdateTransition(int id, bool condition)
			{
				transitions_[id] = condition;
			}

			void SetCurrentNodeAs(int id)
			{
				currentNodeId_ = id;
			}

			template < typename T >
			void SetCurrentNodeAs(T* node1) 
			{
				SarissaBTNode* casted_node = static_cast<SarissaBTNode*>(node1);
				if (casted_node != nullptr) {
					currentNodeId_ = casted_node->GetId();
				}
			}

			void StartMachine() 
			{
				isRunning_ = true;
				currentNodeId_ = 0;
				nodes_[currentNodeId_]->StartNode();
			}

			void UpdateMachine() 
			{
				if (!isRunning_) return;

				nodes_[currentNodeId_]->UpdateNode();

				for (int i = 0; i < nodes_.size(); ++i) {
					if (
						(transitions_.find(i) != transitions_.end())
						&&
						(nodes_[currentNodeId_]->GetNextNode() != nullptr
							&& nodes_[i]->GetNextNode() != nullptr)
						&&
						(nodes_[currentNodeId_]->GetNextNode()->GetId()
							== nodes_[i]->GetNextNode()->GetId())
						) {
						nodes_[currentNodeId_]->EndNode();

						currentNodeId_ = nodes_[currentNodeId_]->GetNextNode()->GetId();

						nodes_[currentNodeId_]->StartNode();
					}
				}
			}

			void EndMachine()
			{
				isRunning_ = false;

				nodes_[currentNodeId_]->EndNode();
			}
		};
	}
}
#endif /* !_SARISSAMINI_SM_ */

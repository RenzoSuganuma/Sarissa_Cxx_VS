#include "SarissaMinimalSM.h"
#include "SarissaBTNode.h"

//using Sarissa::MinimalSM::SarissaMinimalSM;

template < typename T >
void Sarissa::MinimalSM::SarissaMinimalSM::ResistNode(T* node) {
	int id = nodes_.size();
	SarissaBTNode* casted = static_cast<SarissaBTNode*> (node);
	if (casted != nullptr) {
		casted->SetId(id);
		nodes_.insert(std::make_pair(casted->GetId(), casted));
	}
}

template < typename T1, typename T2 >
void Sarissa::MinimalSM::SarissaMinimalSM::ApplyTransition(T1* node1, T2* node2) {
	SarissaBTNode* casted_node1 = static_cast<SarissaBTNode*> (node1);
	SarissaBTNode* casted_node2 = static_cast<SarissaBTNode*> (node2);

	if (casted_node1 != nullptr && casted_node2 != nullptr) {
		casted_node1->SetNextNode(casted_node2);
		casted_node2->SetNextNode(nullptr);

		transitions_.insert(std::make_pair(casted_node1->GetId(), false));
	}
}

void Sarissa::MinimalSM::SarissaMinimalSM::UpdateTransition(int id, bool condition) {
	transitions_[id] = condition;
}

void Sarissa::MinimalSM::SarissaMinimalSM::SetCurrentNodeAs(int id) {
	currentNodeId_ = id;
}

template < typename T >
void Sarissa::MinimalSM::SarissaMinimalSM::SetCurrentNodeAs(T* node1) {
	SarissaBTNode* casted_node = static_cast<SarissaBTNode*>(node1);
	if (casted_node != nullptr) {
		currentNodeId_ = casted_node->GetId();
	}
}

void Sarissa::MinimalSM::SarissaMinimalSM::StartMachine() {
	isRunning_ = true;
	currentNodeId_ = 0;
	nodes_[currentNodeId_]->StartNode();
}

void Sarissa::MinimalSM::SarissaMinimalSM::UpdateMachine() {
	if (!isRunning_) return;

	nodes_[currentNodeId_]->UpdateNode();

	for (int i = 0; i < nodes_.size(); ++i) {
		auto transition_is_contained = transitions_.find(i) != transitions_.end();
		auto nodes_is_not_null = nodes_[currentNodeId_]->GetNextNode() != nullptr
			&& nodes_[i]->GetNextNode() != nullptr;
		auto nodes_is_same = nodes_[currentNodeId_]->GetNextNode()->GetId()
			== nodes_[i]->GetNextNode()->GetId();

		if (transition_is_contained && nodes_is_not_null && nodes_is_same) {
			nodes_[currentNodeId_]->EndNode();

			currentNodeId_ = nodes_[currentNodeId_]->GetNextNode()->GetId();

			nodes_[currentNodeId_]->StartNode();
		}
	}
}

void Sarissa::MinimalSM::SarissaMinimalSM::EndMachine() {
	isRunning_ = false;

	nodes_[currentNodeId_]->EndNode();
}


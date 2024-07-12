#include "SarissaBTNode.h"

//using Sarissa::MinimalSM::SarissaBTNode;

void Sarissa::MinimalSM::SarissaBTNode::SetNextNode(SarissaBTNode* node) {
	next_ = node;
};

const Sarissa::MinimalSM::SarissaBTNode* Sarissa::MinimalSM::SarissaBTNode::GetNextNode() const {
	return next_;
}

void Sarissa::MinimalSM::SarissaBTNode::SetId(int id) {
	id_ = id;
}

const int Sarissa::MinimalSM::SarissaBTNode::GetId() const {
	return id_;
}

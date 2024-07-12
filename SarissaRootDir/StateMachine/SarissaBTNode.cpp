#include "SarissaBTNode.h"

using Sarissa::MinimalSM::SarissaBTNode;

void SarissaBTNode::SetNextNode(SarissaBTNode* node) {
	next_ = node;
};

const SarissaBTNode* SarissaBTNode::GetNextNode() const {
	return next_;
}

void SarissaBTNode::SetId(int id) {
	id_ = id;
}

const int SarissaBTNode::GetId() const {
	return id_;
}

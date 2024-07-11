#ifndef _SARISSA_BT_NODE_
#define _SARISSA_BT_NODE_

#include "functional"
#include "list"

// ëOï˚êÈåæ
class SarissaBTNode;

class SarissaBTNode {
protected:
	std::list< std::function< void() > > OnNextNodeChanged;
	const SarissaBTNode* next_;
	const int id_;

public:
	const SarissaBTNode* GetThisNode() const {
		return this;
	}

	void SetNextNode(const SarissaBTNode* node) {
		next_ = node;
	};

	const SarissaBTNode* GetNextNode() const {
		return next_;
	}
};

#endif // !_SARISSA_BT_NODE_

#ifndef _SARISSA_BT_NODE_
#define _SARISSA_BT_NODE_

#include "functional"
#include "list"

// ëOï˚êÈåæ
class SarissaBTNode;

class SarissaBTNode {
protected:
	std::list< std::function< void() > > OnNextNodeChanged;
	SarissaBTNode* next_;
	int id_;

public:
	void SetNextNode(SarissaBTNode* node) {
		next_ = node;
	};

	SarissaBTNode* GetNextNode() const {
		return next_;
	}
};

#endif // !_SARISSA_BT_NODE_

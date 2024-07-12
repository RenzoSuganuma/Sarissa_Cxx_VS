#pragma once

#define OUT std::wcout

#include "../SarissaBTNode.h"
#include "iostream"

using Sarissa::MinimalSM::SarissaBTNode;

class Sample_Node2 : public SarissaBTNode {
	void StartNode() override {
		OUT << " Sample_Node2:Start\n ";
	}

	void UpdateNode() override {
		OUT << " Sample_Node2:Update\n ";
	}

	void EndNode() override {
		OUT << " Sample_Node2:End\n ";
	}
};

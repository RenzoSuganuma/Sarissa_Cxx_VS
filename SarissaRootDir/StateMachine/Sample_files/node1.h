#pragma once

#define OUT std::cout

#include "../SarissaBTNode.h"
#include "iostream"

using Sarissa::MinimalSM::SarissaBTNode;

class Sample_Node1 : public SarissaBTNode {
	void StartNode() override {
		OUT << " Sample_Node1:Start\n ";
	}

	void UpdateNode() override {
		OUT << " Sample_Node1:Update\n ";
	}

	void EndNode() override {
		OUT << " Sample_Node1:End\n ";
	}
};
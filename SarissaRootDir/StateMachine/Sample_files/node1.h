#pragma once

#include "../SarissaBTNode.h"
#include "iostream"

using Sarissa::MinimalSM::SarissaBTNode;

class Sample_Node1 : public SarissaBTNode {
	void StartNode() override {
		std::cout << "\r\n";
		std::cout << " Sample_Node1:Start\n ";
	}

	void UpdateNode() override {
		std::cout << "\r\n";
		std::cout << " Sample_Node1:Update\n ";
	}

	void EndNode() override {
		std::cout << "\r\n";
		std::cout << " Sample_Node1:End\n ";
	}
};
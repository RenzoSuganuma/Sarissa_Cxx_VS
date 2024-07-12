#pragma once

#include "../SarissaBTNode.h"
#include "iostream"

using Sarissa::MinimalSM::SarissaBTNode;

class Sample_Node2 : public SarissaBTNode {
	void StartNode() override {
		std::cout << "\r\n";
		std::cout << " Sample_Node2:Start\n ";
	}

	void UpdateNode() override {
		std::cout << "\r\n";
		std::cout << " Sample_Node2:Update\n ";
	}

	void EndNode() override {
		std::cout << "\r\n";
		std::cout << " Sample_Node2:End\n ";
	}
};

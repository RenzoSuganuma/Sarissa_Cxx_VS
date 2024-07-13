#pragma once

#define OUT std::cout

#include "../SarissaSequenceMachineNode.h"
#include "iostream"

using Sarissa::SequenceMachine::SarissaSequenceMachineNode;

class Sample_Node2 : public SarissaSequenceMachineNode
{
	void StartNode() override 
	{
		OUT << " Sample_Node2:Start\n ";
	}

	void UpdateNode() override
	{
		OUT << " Sample_Node2:Update\n ";
	}

	void EndNode() override
	{
		OUT << " Sample_Node2:End\n ";
	}
};

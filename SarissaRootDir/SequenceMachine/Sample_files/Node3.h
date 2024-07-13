#pragma once

#define OUT std::cout

#include "../SarissaSequenceMachineNode.h"
#include "iostream"

using Sarissa::SequenceMachine::SarissaSequenceMachineNode;

class Sample_Node3 : public SarissaSequenceMachineNode
{
	void StartNode() override 
	{
		OUT << " Sample_Node3:Start\n ";
	}

	void UpdateNode() override
	{
		OUT << " Sample_Node3:Update\n ";
	}

	void EndNode() override
	{
		OUT << " Sample_Node3:End\n ";
	}
};

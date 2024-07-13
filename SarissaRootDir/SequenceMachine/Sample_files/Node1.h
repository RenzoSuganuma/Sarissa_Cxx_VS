#pragma once

#define OUT std::cout

#include "../SarissaSequenceMachineNode.h"
#include "iostream"

using Sarissa::SequenceMachine::SarissaSequenceMachineNode;

class Sample_Node1 : public SarissaSequenceMachineNode
{
	void StartNode() override 
	{
		OUT << " Sample_Node1:Start\n ";
	}

	void UpdateNode() override 
	{
		OUT << " Sample_Node1:Update\n ";
	}

	void EndNode() override 
	{
		OUT << " Sample_Node1:End\n ";
	}
};
#include "SarissaRootDir/SequenceMachine/Sample_files/Node1.h"
#include "SarissaRootDir/SequenceMachine/Sample_files/Node2.h"
#include "SarissaRootDir/SequenceMachine/Sample_files/Node3.h"
#include "SarissaRootDir/SequenceMachine/SarissaSequenceMachine.h"
#include "SarissaRootDir/SequenceMachine/SarissaSequenceMachineNode.h"
#include "iostream"

void setup();
void mainloop();
void end();

int main()
{
	setup();
	mainloop();
	end();

	return 0;
}

void setup()
{
	Sarissa::SequenceMachine::SarissaSequenceMachine* sm = new Sarissa::SequenceMachine::SarissaSequenceMachine;
	Sample_Node1* n1 = new Sample_Node1;
	Sample_Node2* n2 = new Sample_Node2;
	Sample_Node3* n3 = new Sample_Node3;

	sm->ResistNode(n1);
	sm->ResistNode(n2);
	sm->ResistNode(n3);

	sm->ApplyTransition(n1, n2);
	sm->ApplyTransition(n1, n3);

	sm->StartMachine();
	sm->UpdateMachine();
	sm->UpdateTransition(1, true);
	sm->UpdateMachine();
	sm->EndMachine();
}

void mainloop()
{
}

void end()
{
}

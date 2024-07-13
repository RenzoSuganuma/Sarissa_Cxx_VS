#include "SarissaRootDir/StateMachine/Sample_files/node1.h"
#include "SarissaRootDir/StateMachine/Sample_files/node2.h"
#include "SarissaRootDir/StateMachine/SarissaMinimalSM.h"
#include "SarissaRootDir/StateMachine/SarissaBTNode.h"
#include "iostream"

void setup();
void mainloop();
void end();

class SarissaMinimalSM;

Sarissa::MinimalSM::SarissaMinimalSM* sm;
Sample_Node1* node1;
Sample_Node2* node2;

int main()
{
	setup();
	mainloop();
	end();

	return 0;
}

void setup() {
	sm = new Sarissa::MinimalSM::SarissaMinimalSM;
	node1 = new Sample_Node1;
	node2 = new Sample_Node2;

	sm->ResistNode(node1);
	sm->ResistNode(node2);

	sm->ApplyTransition(node1, node2);

	sm->StartMachine();
	sm->UpdateMachine();
	sm->UpdateTransition(0, true);
	sm->UpdateMachine();
	sm->EndMachine();
}

void mainloop() {

}

void end() {

}

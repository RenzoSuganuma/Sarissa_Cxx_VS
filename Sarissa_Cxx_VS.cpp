#include <iostream>
#include "SarissaRootDir/StateMachine/Sample_files/node1.h"
#include "SarissaRootDir/StateMachine/Sample_files/node2.h"
#include "SarissaRootDir/StateMachine/SarissaMinimalSM.h"
#include "SarissaRootDir/StateMachine/SarissaBTNode.h"

void setup();
void mainloop();
void end();

using Sarissa::MinimalSM::SarissaMinimalSM;
using Sarissa::MinimalSM::SarissaBTNode;

SarissaMinimalSM* sm;
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
	sm = new SarissaMinimalSM;
	node1 = new Sample_Node1;
	node2 = new Sample_Node2;


}

void mainloop() {

}

void end() {

}

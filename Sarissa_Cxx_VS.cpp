#include "SarissaRootDir/Action/Action.h"
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
	SarissaAction* act = new SarissaAction;

	act->AddAction([]() { std::cout << "1\n"; });
	act->AddAction([]() { std::cout << "2\n"; });
	act->AddAction([]() { std::cout << "3\n"; });
	act->AddAction([]() { std::cout << "4\n"; });
	act->AddAction([]() { std::cout << "5\n"; });

	auto b = act->Begin();
	auto e = act->End();
	e--;

	act->RemoveAction(b);
	act->RemoveAction(e);

	act->Invoke();
}

void mainloop()
{
}

void end()
{
}

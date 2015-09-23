#include "CowSleepingState.h"
#include "CowChaseRabbitState.h"

CowSleepingState::CowSleepingState()
{
	turn = 0;
	counter = 0;
}


CowSleepingState::~CowSleepingState()
{
}

void CowSleepingState::Enter(Cow* cow)
{
	turn = 0;
	counter = 0;

}

void CowSleepingState::Execute(Cow* cow)
{
	if (counter == 1)
	{
		turn++;
		counter = 0;
	}
	counter++;

	if (turn == 5)
	{
		cow->GetFSM()->ChangeState(CowChaseRabbitState::Instance());
	}
}

void CowSleepingState::Exit(Cow* cow)
{
}

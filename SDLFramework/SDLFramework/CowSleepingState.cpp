#include "CowSleepingState.h"
#include "CowChaseRabbitState.h"
#include "Dashboard.h"
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
}

// Make the cow 'sleep' on a node for 5 'turns'
void CowSleepingState::Execute(Cow* cow)
{
	if (counter == 50)
	{
		turn++;
		Dashboard::Instance()->SetCowSleepingTurns(turn);

		counter = 0;
	}
	counter++;

	if (turn > 5)
	{
		cow->GetFSM()->ChangeState(CowChaseRabbitState::Instance());
		//turn = 0;
		Dashboard::Instance()->SetCowSleepingTurns(turn);
		turn = 0;
		counter = 0;
	}
}

// Reset the turn back to 0
void CowSleepingState::Exit(Cow* cow)
{
	turn = 0;
	Dashboard::Instance()->SetCowSleepingTurns(turn);
}
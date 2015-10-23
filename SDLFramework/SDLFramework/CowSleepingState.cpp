#include "CowSleepingState.h"
#include "CowChaseRabbitState.h"
#include "Dashboard.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor.
/// 			
/// 			Set the amount of turns to 0.
/// 			Set the counter to 0.
/// 			  </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowSleepingState::CowSleepingState()
{
	turn = 0;
	counter = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowSleepingState::~CowSleepingState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action just after entering the state. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowSleepingState::Enter(Cow* cow)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Make the cow 'sleep' on a node for 5 'turns'. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

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
#include "RabbitWanderingState.h"
#include "Graph.h"
#include "RabbitSearchForWeaponState.h"
#include "ProbabilityDistribution.h"
#include "RabbitSearchForPillState.h"
#include "RabbitFleeingState.h"
#include "CowSleepingState.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor.
/// 			Set counter to 0. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

RabbitWanderingState::RabbitWanderingState()
{
	counter = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

RabbitWanderingState::~RabbitWanderingState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right after entering the state. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitWanderingState::Enter(Rabbit* rabbit)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Execute the code corresponding to the Wandering state for the rabbit.
/// 			1) Use either the pill or weapon.
/// 			2) Check whether the cow is sleeping on the same node as the rabbit. If so, flee.
/// 			3) If the cow is chasing the rabbit and the cow catches the rabbit,
/// 			   the rabbit will pick a strategy (search for a pill, a weapon or simply flee)
/// 			   determined by how the chances (in percentages) per strategy are distributed.
/// 			</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitWanderingState::Execute(Rabbit* rabbit)
{
	UsePill(rabbit);
	UseWeapon(rabbit);

	// if cow sleeping on the same node as the rabbit
	if (Graph::cow->GetCurrentState() == "Sleeping" && Graph::cow->getCurrentNode()->id == rabbit->getCurrentNode()->id) // then flee from cow while it is asleep
		rabbit->GetFSM()->ChangeState(RabbitFleeingState::Instance());

	// If the cow is chasing the rabbit and the cow is on the same spot as the rabbit
	if (Graph::cow->GetCurrentState() == "Chase Rabbit" &&
		Graph::cow->getCurrentNode()->id == rabbit->getCurrentNode()->id)
	{
		switch (ProbabilityDistribution::Instance()->GenerateRandomChoice())
		{
		case 1:
			rabbit->GetFSM()->ChangeState(RabbitSearchForWeaponState::Instance());
			ProbabilityDistribution::Instance()->IncreaseChoice1Probability();
			break;
		case 2:
			rabbit->GetFSM()->ChangeState(RabbitSearchForPillState::Instance());
			ProbabilityDistribution::Instance()->IncreaseChoice2Probability();
			break;
		case 3:
			rabbit->GetFSM()->ChangeState(RabbitFleeingState::Instance());
			ProbabilityDistribution::Instance()->IncreaseChoice3Probability();
			break;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right before exiting a state. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitWanderingState::Exit(Rabbit* rabbit)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Use pill.
/// 			If the rabbit is on the same node as the pill and has picked up the pill,
/// 			rabbit will go into a Sleeping state.
/// 			Set pickedUpPill flag to false.
/// 			  </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitWanderingState::UsePill(Rabbit* rabbit)
{
	if (rabbit->pickedUpPill == true && Graph::cow->getCurrentNode()->id == rabbit->getCurrentNode()->id)
	{
		Graph::cow->GetFSM()->ChangeState(CowSleepingState::Instance());
		rabbit->pickedUpPill = false;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Use pill.
/// 			If the rabbit is on the same node as the weapon and has picked up the weapon,
/// 			Check whether the cow is within neighborhood, if so, blast the cow to a random
/// 			location.
/// 			Set pickedUpWeapon flag to false.
/// 			  </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitWanderingState::UseWeapon(Rabbit* rabbit)
{
	if (rabbit->pickedUpWeapon == true)
	{
		for each(Edge* edge in Graph::rabbit->getCurrentNode()->GetEdges())
		{
			if (edge->child->id == Graph::cow->getCurrentNode()->id)
			{
				Graph::cow->PutOnRandomLocation();
				rabbit->pickedUpWeapon = false;
			}
		}
	}
}
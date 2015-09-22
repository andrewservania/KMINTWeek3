#include "RabbitWanderingState.h"
#include "Graph.h"
#include "RabbitSearchForWeaponState.h"

RabbitWanderingState::RabbitWanderingState()
{
}


RabbitWanderingState::~RabbitWanderingState()
{
}


void RabbitWanderingState::Enter(Rabbit* rabbit)
{
}

// Execute the code corresponding to the Wandering state for the rabbit
void RabbitWanderingState::Execute(Rabbit* rabbit)
{
	// If the cow is chasing the rabbit and the cow is on the same spot as the rabbit
	if (Graph::cow->GetCurrentState() == "Chase Rabbit" &&
		Graph::cow->getCurrentNode()->id == rabbit->getCurrentNode()->id)

		// Chance distributation and selection of options states comes here...

		rabbit->GetFSM()->ChangeState(RabbitSearchForWeaponState::Instance());
	
}

void RabbitWanderingState::Exit(Rabbit* rabbit)
{
}
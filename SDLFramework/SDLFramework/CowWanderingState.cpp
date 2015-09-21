#include "CowWanderingState.h"
#include "Graph.h"
#include "CowSearchForPillState.h"
#include "Dashboard.h"

CowWanderingState::CowWanderingState()
{
	counter = 0;
	boredom = 0;
}

// Do the necessary preparations to enter the Cow Wandering State
void CowWanderingState::Enter(Cow* cow)
{
	boredom = 0;
}

// Execute the code correspesonding to the Cow Wandering state
void CowWanderingState::Execute(Cow* cow)
{
	if (counter == 100){
		counter = 0;

		// Cow will go to a neighboring node from the current node in which it is standing
		int amountOfneighbors = cow->getCurrentNode()->GetEdges().size();
		Node* nodeToWanderTo = cow->getCurrentNode()->GetEdges().at(rand() % amountOfneighbors)->child;
		cow->setCurrentNode(nodeToWanderTo);
		boredom++;
		Dashboard::Instance()->CowBoredomLevel(boredom);
	}
	counter++;

	if (boredom == 10){
		cow->GetFSM()->ChangeState(CowSearchForPillState::Instance());
		
		Dashboard::Instance()->CowBoredomLevel(boredom);
	}

}

// Do the necessary cleanups and close ups before leaving the Cow Wandering State
void CowWanderingState::Exit(Cow* cow)
{
}


CowWanderingState::~CowWanderingState()
{
}

#include "RabbitWanderingState.h"
#include "Graph.h"
#include "RabbitSearchForWeaponState.h"
#include "ProbabilityDistribution.h"
#include "RabbitSearchForPillState.h"
#include "RabbitFleeingState.h"

RabbitWanderingState::RabbitWanderingState()
{
	counter = 0;
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



	//if (counter == 50){
	//	counter = 0;

		// Cow will go to a neighboring node from the current node in which it is standing
		int amountOfneighbors = rabbit->getCurrentNode()->GetEdges().size();
		Node* nodeToWanderTo = rabbit->getCurrentNode()->GetEdges().at(rand() % amountOfneighbors)->child;
		rabbit->setCurrentNode(nodeToWanderTo);
		
	//}
	//counter++;


	// If the cow is chasing the rabbit and the cow is on the same spot as the rabbit
	//if (Graph::cow->GetCurrentState() == "Chase Rabbit" &&
	//	Graph::cow->getCurrentNode()->id == rabbit->getCurrentNode()->id)
	//{
	//	

	//	switch (ProbabilityDistribution::Instance()->GenerateRandomChoice())
	//	{
	//		case 1: 
	//			rabbit->GetFSM()->ChangeState(RabbitSearchForWeaponState::Instance());
	//			ProbabilityDistribution::Instance()->IncreaseChoice1Probability();
	//			break;
	//		case 2: 
	//			rabbit->GetFSM()->ChangeState(RabbitSearchForPillState::Instance());
	//			ProbabilityDistribution::Instance()->IncreaseChoice2Probability();
	//			break;
	//		case 3: 
	//			rabbit->GetFSM()->ChangeState(RabbitFleeingState::Instance());
	//			ProbabilityDistribution::Instance()->IncreaseChoice3Probability();
	//			break;
	//	}
	//}



	
}

void RabbitWanderingState::Exit(Rabbit* rabbit)
{
}
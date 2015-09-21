#include "CowChaseRabbitState.h"
#include "Graph.h"
#include "CowWanderingState.h"
#include "AStar.h"
#include "Graph.h"
#include "CowWanderingState.h"
#include "RabbitFleeingState.h"
#include <memory>
#include "Dashboard.h"
using namespace std;

CowChaseRabbitState::CowChaseRabbitState()
{
}


CowChaseRabbitState::~CowChaseRabbitState()
{
}

void CowChaseRabbitState::Enter(Cow* cow)
{
	stepTimer = 0;
	shared_ptr<AStar> astar = make_shared<AStar>();
	shortestPath = astar->GetShortestPath(cow->getCurrentNode(), Graph::rabbit->getCurrentNode());

	UpdateShortestPathLabel(cow, Graph::rabbit);
}

void CowChaseRabbitState::Execute(Cow* cow)
{
	if (stepTimer == 50)
	{
		if (!shortestPath.empty())					// If shortest path is empty, then go to the goal node step by step
		{
			cow->setCurrentNode(shortestPath.top()); // Cow will walk to the top next node
			shortestPath.pop();						 // Now remove the top next node
			stepTimer = 0;
		}
		else{
			cow->GetFSM()->ChangeState(CowWanderingState::Instance());
		}
	}

	stepTimer++;
}

void CowChaseRabbitState::Exit(Cow* cow)
{
}

void CowChaseRabbitState::UpdateShortestPathLabel(Cow* cow, Rabbit* rabbit)
{
	shared_ptr<AStar> aStar = make_shared<AStar>();
	auto shortPath = aStar->GetShortestPath(cow->getCurrentNode(), rabbit->getCurrentNode());
	string shortestPathLabel = "Shortest path from cow to rabbit: ";
	while (!shortPath.empty())
	{
		Node* step = shortPath.top();

		shortestPathLabel += to_string(step->id).c_str();

		shortPath.pop();
		if (!shortPath.empty())
			shortestPathLabel += " -> ";
	}
	Dashboard::Instance()->ShortestPathLabel(shortestPathLabel);
}
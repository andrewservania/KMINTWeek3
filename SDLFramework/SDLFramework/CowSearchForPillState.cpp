#include "CowSearchForPillState.h"
#include "AStar.h"
#include "Graph.h"
#include "CowChaseRabbitState.h"
#include <memory>
#include "Dashboard.h"
#include "Node.h"
using namespace std;

CowSearchForPillState::CowSearchForPillState()
{
}


CowSearchForPillState::~CowSearchForPillState()
{
}

void CowSearchForPillState::Enter(Cow* cow)
{
	
	stepTimer = 0;
	shared_ptr<AStar> astar = make_shared<AStar>();
	shortestPath = astar->GetShortestPath(cow->getCurrentNode(), Graph::pill->GetCurrentNode());

	UpdateShortestPathLabel(cow, Graph::pill);
}

void CowSearchForPillState::Execute(Cow* cow)
{
	if (stepTimer == 50)
	{
		if (!shortestPath.empty())					 // If shortest path is empty, then go to the goal node step by step
		{
			cow->setCurrentNode(shortestPath.top()); // Cow will walk to the top next node
			shortestPath.pop();						 // Now remove the top next node
			stepTimer = 0;
		}
	}

	stepTimer++;
}

void CowSearchForPillState::Exit(Cow* cow)
{
}

void CowSearchForPillState::UpdateShortestPathLabel(Cow* cow, Pill* pill)
{
	shared_ptr<AStar> aStar = make_shared<AStar>();
	auto shortPath = aStar->GetShortestPath(cow->getCurrentNode(), pill->GetCurrentNode());
	string shortestPathLabel = "Shortest path from cow to pill: ";
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
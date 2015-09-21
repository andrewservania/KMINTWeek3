#include "RabbitSearchForPillState.h"
#include "AStar.h"
#include "Graph.h"
#include "Dashboard.h"
#include <memory>

using namespace std;

RabbitSearchForPillState::RabbitSearchForPillState()
{
}


RabbitSearchForPillState::~RabbitSearchForPillState()
{
}

void RabbitSearchForPillState::Enter(Rabbit* rabbit)
{

	stepTimer = 0;
	shared_ptr<AStar> astar = make_shared<AStar>();
	shortestPath = astar->GetShortestPath(rabbit->getCurrentNode(), Graph::pill->GetCurrentNode());

	UpdateShortestPathLabel(rabbit, Graph::pill);
}

void RabbitSearchForPillState::Execute(Rabbit* rabbit)
{
	if (stepTimer == 50)
	{
		if (!shortestPath.empty())					 // If shortest path is empty, then go to the goal node step by step
		{
			rabbit->setCurrentNode(shortestPath.top()); // Cow will walk to the top next node
			shortestPath.pop();						 // Now remove the top next node
			stepTimer = 0;
		}
	}

	stepTimer++;
}

void RabbitSearchForPillState::Exit(Rabbit* rabbit)
{
}



void RabbitSearchForPillState::UpdateShortestPathLabel(Rabbit* rabbit, Pill* pill)
{
	shared_ptr<AStar> aStar = make_shared<AStar>();
	auto shortPath = aStar->GetShortestPath(rabbit->getCurrentNode(), pill->GetCurrentNode());
	string shortestPathLabel = "Shortest path from rabbit to pill: ";
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
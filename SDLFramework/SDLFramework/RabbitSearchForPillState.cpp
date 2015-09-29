#include "RabbitSearchForPillState.h"
#include "AStar.h"
#include "Graph.h"
#include "Dashboard.h"
#include <memory>

using namespace std;

RabbitSearchForPillState::RabbitSearchForPillState()
{
	rabbitStartedSearching = false;
}

RabbitSearchForPillState::~RabbitSearchForPillState()
{
}

void RabbitSearchForPillState::StartSearchingForPill(Rabbit* rabbit)
{
	if (!rabbitStartedSearching)
	{
		stepTimer = 0;
		shared_ptr<AStar> astar = make_shared<AStar>();
		shortestPath = astar->GetShortestPath(rabbit->getCurrentNode(), Graph::pill->GetCurrentNode());
		rabbitStartedSearching = true;
	}
}

void RabbitSearchForPillState::Enter(Rabbit* rabbit)
{
	stepTimer = 0;
	shared_ptr<AStar> astar = make_shared<AStar>();
	shortestPath = astar->GetShortestPath(rabbit->getCurrentNode(), Graph::pill->GetCurrentNode());

	//	UpdateShortestPathLabel(shortestPath);
}

void RabbitSearchForPillState::Execute(Rabbit* rabbit)
{
	StartSearchingForPill(rabbit);
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

void RabbitSearchForPillState::UpdateShortestPathLabel(stack<Node*> _shortestPath)
{
	//shared_ptr<AStar> aStar = make_shared<AStar>();
	//auto shortPath = aStar->GetShortestPath(rabbit->getCurrentNode(), pill->GetCurrentNode());
	string shortestPathLabel = "Shortest path from rabbit to pill: ";
	while (!_shortestPath.empty())
	{
		Node* step = _shortestPath.top();

		shortestPathLabel += to_string(step->id).c_str();

		_shortestPath.pop();
		if (!_shortestPath.empty())
			shortestPathLabel += " -> ";
	}
	Dashboard::Instance()->ShortestPathLabel(shortestPathLabel);
}
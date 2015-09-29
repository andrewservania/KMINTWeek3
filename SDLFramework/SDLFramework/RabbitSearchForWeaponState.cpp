#include "RabbitSearchForWeaponState.h"
#include "Weapon.h"
#include "Dashboard.h"
#include "AStar.h"
#include "Graph.h"
#include <memory>

using namespace std;

RabbitSearchForWeaponState::RabbitSearchForWeaponState()
{
	rabbitStartedSearching = false;
}

RabbitSearchForWeaponState::~RabbitSearchForWeaponState()
{
}

void RabbitSearchForWeaponState::StartSearchingForWeapon(Rabbit* rabbit)
{
	if (!rabbitStartedSearching)
	{
		stepTimer = 0;
		shared_ptr<AStar> astar = make_shared<AStar>();
		shortestPath = astar->GetShortestPath(rabbit->getCurrentNode(), Graph::weapon->GetCurrentNode());
		rabbitStartedSearching = true;
	}
}

void RabbitSearchForWeaponState::Enter(Rabbit* rabbit)
{
	stepTimer = 0;
	shared_ptr<AStar> astar = make_shared<AStar>();

	shortestPath = astar->GetShortestPath(rabbit->getCurrentNode(), Graph::weapon->GetCurrentNode());
	//	UpdateShortestPathLabel(shortestPath);
}

void RabbitSearchForWeaponState::Execute(Rabbit* rabbit)
{
	StartSearchingForWeapon(rabbit);
		if (stepTimer == 50)
		{
			if (!shortestPath.empty())					    // If shortest path is empty, then go to the goal node step by step
			{
				rabbit->setCurrentNode(shortestPath.top()); // Cow will walk to the top next node
				shortestPath.pop();						    // Now remove the top next node
				stepTimer = 0;
			}
			else{
				Graph::weapon->PutOnRandomLocation();
			}
		}
		stepTimer++;
}

void RabbitSearchForWeaponState::Exit(Rabbit* rabbit)
{
}

void RabbitSearchForWeaponState::UpdateShortestPathLabel(stack<Node*> _shortestPath)
{
	//shared_ptr<AStar> aStar = make_shared<AStar>();
	//auto shortPath = aStar->GetShortestPath(rabbit->getCurrentNode(), weapon->GetCurrentNode());
	string shortestPathLabel = "Shortest path from cow to rabbit: ";
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
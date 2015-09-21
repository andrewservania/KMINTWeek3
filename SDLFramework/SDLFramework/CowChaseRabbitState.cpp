#include "CowChaseRabbitState.h"
#include "Graph.h"
#include "AStar.h"
#include "Graph.h"
#include "RabbitFleeingState.h"
#include <memory>
#include "Dashboard.h"
using namespace std;

CowChaseRabbitState::CowChaseRabbitState()
{
	pathIsCalculated = false;

}


CowChaseRabbitState::~CowChaseRabbitState()
{
}

void CowChaseRabbitState::Enter(Cow* cow)
{

}

void CowChaseRabbitState::Execute(Cow* cow)
{
	CalculateNewPath();

	if (stepTimer == 30)
	{
		if (!shortestPath.empty())					// If shortest path is empty, then go to the goal node step by step
		{
			cow->setCurrentNode(shortestPath.top()); // Cow will walk to the top next node
			shortestPath.pop();						 // Now remove the top next node
			stepTimer = 0;
			
		}
		else {
				pathIsCalculated = false;
		}
	}

	stepTimer++;
}

void CowChaseRabbitState::CalculateNewPath()
{
	// If path has already been calculated, do not calculate again in order to save on processor overhead
	// Also, do not calculate shortestpath if the cow has moved towards the rabbit and is already standing on the same node as
	// the rabbit. (Give the rabbit some time to move to a different location THEN calculate the shortestpath from cow to rabbit again.
	if (!pathIsCalculated && Graph::cow->getCurrentNode()->id != Graph::rabbit->getCurrentNode()->id)
	{
		stepTimer = 0;
		shared_ptr<AStar> astar = make_shared<AStar>();
		shortestPath = astar->GetShortestPath(Graph::cow->getCurrentNode(), Graph::rabbit->getCurrentNode());

		UpdateShortestPathLabel(Graph::cow, Graph::rabbit);
		pathIsCalculated = true;
	}

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
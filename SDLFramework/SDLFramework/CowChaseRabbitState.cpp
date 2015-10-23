#include "CowChaseRabbitState.h"
#include "Graph.h"
#include "AStar.h"
#include "Graph.h"
#include "RabbitFleeingState.h"
#include <memory>
#include "Dashboard.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. 
/// 			Set pathIsCalculated flag to false
/// 			Set counter to zero.
/// 			</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowChaseRabbitState::CowChaseRabbitState()
{
	pathIsCalculated = false;
	counter = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowChaseRabbitState::~CowChaseRabbitState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right after entering the state,
/// 			Calculate the shortest path between the rabbit and the cow and show it on screen.
/// 			 </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowChaseRabbitState::Enter(Cow* cow)
{
	stepTimer = 0;
	shared_ptr<AStar> astar = make_shared<AStar>();
	shortestPath = astar->GetShortestPath(Graph::cow->getCurrentNode(), Graph::rabbit->getCurrentNode());

	UpdateShortestPathLabel(shortestPath);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Cow walks towards the node on which the rabbit is standing on. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowChaseRabbitState::Execute(Cow* cow)
{
	CalculateNewPath();

	if (stepTimer == 25)
	{
		if (!shortestPath.empty())					 // If shortest path is empty, then go to the goal node step by step
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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// Calculate the shortest path between the rabbit and the cow as the rabbit moves around.
/// </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowChaseRabbitState::CalculateNewPath()
{
	// If the shortest path has already been calculated, do not calculate again in order to save on processor load
	// Also, do not calculate shortest path if the cow has moved towards the rabbit and is already standing on the same node as
	// the rabbit. (Give the rabbit some time to move to a different location THEN calculate the shortestpath from cow to rabbit again.
	if (!pathIsCalculated && Graph::cow->getCurrentNode()->id != Graph::rabbit->getCurrentNode()->id)
	{
		stepTimer = 0;
		shared_ptr<AStar> astar = make_shared<AStar>();
		shortestPath = astar->GetShortestPath(Graph::cow->getCurrentNode(), Graph::rabbit->getCurrentNode());

		UpdateShortestPathLabel(shortestPath);
		pathIsCalculated = true;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action just before exiting the state </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowChaseRabbitState::Exit(Cow* cow)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the shortest path label described by _shortestPath. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="_shortestPath">	[in,out] If non-null, full pathname of the shortest file. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowChaseRabbitState::UpdateShortestPathLabel(stack<Node*> _shortestPath)
{
	//shared_ptr<AStar> aStar = make_shared<AStar>();
	//auto shortPath = aStar->GetShortestPath(cow->getCurrentNode(), rabbit->getCurrentNode());
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
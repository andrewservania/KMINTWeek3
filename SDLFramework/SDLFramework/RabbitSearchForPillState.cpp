#include "RabbitSearchForPillState.h"
#include "AStar.h"
#include "Graph.h"
#include "Dashboard.h"
#include <memory>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor.
/// 			Set rabbitStartSearching flag to false. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

RabbitSearchForPillState::RabbitSearchForPillState()
{
	rabbitStartedSearching = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

RabbitSearchForPillState::~RabbitSearchForPillState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Starts searching for the pill.
/// 			If the rabbit hasn't start searching for a pill yet, the rabbit
/// 			will start searching by calculating the shortest path to the pill. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right after entering the state.
/// 			Calculate the shortest path to the pill.
/// 			Set the step timer to 0. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitSearchForPillState::Enter(Rabbit* rabbit)
{
	stepTimer = 0;
	shared_ptr<AStar> astar = make_shared<AStar>();
	shortestPath = astar->GetShortestPath(rabbit->getCurrentNode(), Graph::pill->GetCurrentNode());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	The rabbit calculate the shortest path to the pill and walk step by step
/// 			towards the pill. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right before exiting the state. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitSearchForPillState::Exit(Rabbit* rabbit)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the shortest path label with the shortest path. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="_shortestPath">	[in,out] If non-null, full pathname of the shortest file. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitSearchForPillState::UpdateShortestPathLabel(stack<Node*> _shortestPath)
{
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
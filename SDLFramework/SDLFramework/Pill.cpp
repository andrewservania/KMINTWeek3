#include "Pill.h"
#include "Graph.h"
#include "RabbitWanderingState.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
/// Create a pill by
/// 1) Loading a picture of the pill  
/// 2) Set the pill on node at random as long its not onthe same node as the rabbit, the cow, and  
///    weapon
/// 3) Add the pill to items that must be displayed on screen
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Pill::Pill()
{
	mTexture = mApplication->LoadTexture("pill.png");

	// Put the pill at a random location
	SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));

	while (Graph::rabbit->getCurrentNode()->id == currentNode->id)
		SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));

	mApplication->AddRenderable(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Pill::~Pill()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// If the rabbit is standing on the same node as the pill and the rabbit has been searching for a 
/// pill, consume it go into a Wandering state.
/// </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Pill::Update(float deltaTime)
{
	if (Graph::rabbit->getCurrentNode()->id == currentNode->id)
	{
		if (Graph::rabbit->GetCurrentState() == "Search For Pill")
		{
			Graph::rabbit->GetFSM()->ChangeState(RabbitWanderingState::Instance());
			Graph::rabbit->pickedUpPill = true;
			PutOnRandomLocation();
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draw a picture of the pill on screen.</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Pill::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 50, 50);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Put the pill at a new location. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="newNode">	[in,out] If non-null, the new node. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Pill::SetCurrentNode(Node* newNode)
{
	currentNode = newNode;
	mX = currentNode->GetBoundingBox().x;
	mY = currentNode->GetBoundingBox().y;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// Respawn the pill somewhere else, aslong its not at the same place as the cow, the rabbit or
/// the weapon.
/// </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Pill::PutOnRandomLocation()
{
	SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));

	while (Graph::cow->getCurrentNode()->id == currentNode->id ||
		Graph::rabbit->getCurrentNode()->id == currentNode->id ||
		Graph::weapon->GetCurrentNode()->id == currentNode->id)
		SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));
}
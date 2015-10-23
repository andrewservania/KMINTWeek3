#include "Weapon.h"
#include "Graph.h"
#include "RabbitWanderingState.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor.  			
/// 			Create a weapon by providing an id, a location on the arena.
///
/// 			1) A picture of a weapon is loaded to screen.
/// 			2) The color of the weapon is set to "nothing"
/// 			3) The weapon is added to items that must be shown on screen.  
/// 			4) Set the location of the weapon on a node at random as long as its  
/// 			   not on the same location as the rabbit, the cow and the pill.
/// 			
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Weapon::Weapon()
{
	mTexture = mApplication->LoadTexture("gun-metal.png");

	// Put the weapon at a random location as long as its not at the same location
	// as the cow or rabbit
	SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));

	while (Graph::rabbit->getCurrentNode()->id == currentNode->id ||
		Graph::pill->GetCurrentNode()->id == currentNode->id)
		SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));

	mApplication->AddRenderable(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Weapon::~Weapon()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Update the weapon.
/// 			If the rabbit is standing on the same location as the weapon
/// 			and the rabbit has been searching for a weapon, consume the pill and go into a
/// 			Wandering state.	
/// 			/summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Weapon::Update(float deltaTime)
{
	if (Graph::rabbit->getCurrentNode()->id == currentNode->id)
	{
		if (Graph::rabbit->GetCurrentState() == "Search For Weapon")
		{
			Graph::rabbit->GetFSM()->ChangeState(RabbitWanderingState::Instance());
			Graph::rabbit->pickedUpWeapon = true;
			PutOnRandomLocation();
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draws a picture of the rabbit on screen. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Weapon::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 50, 50);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Set the node and coordinates of the pill.</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="newNode">	[in,out] If non-null, the new node. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Weapon::SetCurrentNode(Node* newNode)
{
	currentNode = newNode;
	mX = currentNode->GetBoundingBox().x;
	mY = currentNode->GetBoundingBox().y;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Puts the weapon on a random location as long as its not the same location as
/// 			the cow, the rabbit and the pill.</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Weapon::PutOnRandomLocation()
{
	while (Graph::cow->getCurrentNode()->id == currentNode->id ||
		Graph::rabbit->getCurrentNode()->id == currentNode->id ||
		Graph::pill->GetCurrentNode()->id == currentNode->id)
		SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));
}
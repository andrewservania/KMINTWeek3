#include "Rabbit.h"
#include "Graph.h"
#include "RabbitWanderingState.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor.
/// 			Create a rabbit by providing it an id.
/// 			1) Load a picture of the rabbit.  
/// 			2) Put the rabbit on a random node as long as its not on the same location as the  
/// 			   cow, the pill and the weapon.
/// 			3) Set pickedUpPill and pickedUpWeapon flags to false.  
/// 			4) Instantiate the state machine of the rabbit.  
/// 			5) Set the state of the rabbit to Wandering
/// 			
/// 			  </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="id">	The identifier. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Rabbit::Rabbit(int id) : BaseGameEntity(id)
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");
	setCurrentNode(Graph::graphNodes.at(rand() % 8));					// Put the rabbit on a random node on the screen
	pickedUpPill = false;
	pickedUpWeapon = false;
	mApplication->AddRenderable(this);

	stateMachine = new StateMachine<Rabbit>(this);
	stateMachine->SetCurrentState(RabbitWanderingState::Instance());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Rabbit::~Rabbit()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the rabbit and the state machine of the rabbit. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::Update(float deltaTime)
{
	stateMachine->Update();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draw a picture of the rabbit on screen. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 100, 100);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Execute code if rabbit has been left-clicked upon. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::OnLeftClick()
{
	printf("Left-clicked on rabbit!\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Execute code if rabbit has been right-clicked upon. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::OnRightClick()
{
	printf("Right-clicked on rabbit!\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Set the current node and coordinates of the rabbit. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="node">	[in,out] If non-null, the node. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::setCurrentNode(Node* node)
{
	currentNode = node;
	mX = node->GetBoundingBox().x;
	mY = node->GetBoundingBox().y;
}
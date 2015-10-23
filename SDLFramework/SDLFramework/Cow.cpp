#include "Cow.h"
#include "Graph.h"
#include "AStar.h"
#include <string>
#include <memory>
#include <assert.h>
#include "CowChaseRabbitState.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
/// Create a cow by
/// 1) Load a picture of the cow.
/// 2) add the cow to items that have to be displayed on screen.  
/// 3) Set the current node of the cow at random as long as its not at the same location as the  
///    rabbit, pill and weapon.
/// 4) instantiate the state machine of the cow.  
/// 5) Set the cow's state to CowChaseRabbit State  
/// 6) 
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="id">	The identifier. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Cow::Cow(int id) : BaseGameEntity(id)
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
	mX = 100;
	mY = 100;

	setCurrentNode(Graph::graphNodes.at(rand() % 8));

	// Put the cow on a random location as long as its not the same location as the rabbit,
	// pill and weapon.
	while (currentNode->id == Graph::rabbit->getCurrentNode()->id ||
		currentNode->id == Graph::pill->GetCurrentNode()->id ||
		currentNode->id == Graph::weapon->GetCurrentNode()->id)	   
		setCurrentNode(Graph::graphNodes.at(rand() % 8));		   

	// Set up the state machine
	stateMachine = new StateMachine<Cow>(this);
	stateMachine->SetCurrentState(CowChaseRabbitState::Instance());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the cow and the state machine of the cow </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::Update(float deltaTime)
{
	stateMachine->Update();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor.
/// 			delete the state machine of cow.
/// 			  </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Cow::~Cow()
{
	delete stateMachine;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets current node and the coordinates of the cow on screen. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="node">	[in,out] If non-null, the node. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::setCurrentNode(Node* node)
{
	currentNode = node;
	mX = node->GetBoundingBox().x;
	mY = node->GetBoundingBox().y;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draw a picture of the cow on screen. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 100, 100);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Handle all clicks registered on the cow.</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="event">	[in,out] The event. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::OnClick(SDL_Event& event)
{
	// Handle clicks that are made within the range in which the cow is situated on
	if (event.motion.x >= static_cast<Sint32>(mX - 90) &&
		event.motion.x <= static_cast<Sint32>(mX + 90) &&
		event.motion.y >= static_cast<Sint32>(mY - 90) &&
		event.motion.y <= static_cast<Sint32>(mY + 90))
	{
		if (event.button.button == SDL_BUTTON_LEFT)
			OnLeftClick(event);
		if (event.button.button == SDL_BUTTON_RIGHT)
			OnRightClick(event);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Execute code when rabbit has been left clicked upon. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="event">	[in,out] The event. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::OnLeftClick(SDL_Event &event)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Execute code when rabbit has been right clicked upon. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="event">	[in,out] The event. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::OnRightClick(SDL_Event &event)
{
	printf("Right-clicked on cow!\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// Put the cow at a random node that is not the same as the rabbit, weapon and pill.
/// </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::PutOnRandomLocation()
{
	setCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));
	while (Graph::weapon->GetCurrentNode()->id == currentNode->id ||
		Graph::rabbit->getCurrentNode()->id == currentNode->id ||
		Graph::pill->GetCurrentNode()->id == currentNode->id)
		setCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));
}
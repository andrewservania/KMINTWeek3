#include "Pill.h"
#include "Graph.h"
#include "CowChaseRabbitState.h"

Pill::Pill()
{
	mTexture = mApplication->LoadTexture("pill.png");

	// Put the pill at a random location
	SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));

	while (Graph::rabbit->getCurrentNode()->id == currentNode->id)
		SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));

	mApplication->AddRenderable(this);
}

Pill::~Pill()
{
}

// Check whether the cow has searching for the pill, if so make it chase the rabbit
void Pill::Update(float deltaTime)
{
	if (Graph::cow->getCurrentNode()->id == currentNode->id)
	{
		if (Graph::cow->GetCurrentState() == "Search For Pill")
		{
			Graph::cow->GetFSM()->ChangeState(CowChaseRabbitState::Instance());
			PutOnRandomLocation();
		}
	}
}

// Draw the pill on screen
void Pill::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 50, 50);
};

// Put the pill at a new location
void Pill::SetCurrentNode(Node* newNode)
{
	currentNode = newNode;
	mX = currentNode->GetBoundingBox().x;
	mY = currentNode->GetBoundingBox().y;
}

// Respawn the pill somewhere else, aslong its not at the same place as the cow, the rabbit or the weapon
void Pill::PutOnRandomLocation()
{
	SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));

	while (Graph::cow->getCurrentNode()->id == currentNode->id ||
		Graph::rabbit->getCurrentNode()->id == currentNode->id ||
		Graph::weapon->GetCurrentNode()->id == currentNode->id)
		SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));

}
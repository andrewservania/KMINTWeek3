#include "Weapon.h"
#include "Graph.h"
#include "RabbitWanderingState.h"

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

Weapon::~Weapon()
{
}

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

void Weapon::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 50, 50);
};

// Put the weapon at a new location
void Weapon::SetCurrentNode(Node* newNode)
{
	currentNode = newNode;
	mX = currentNode->GetBoundingBox().x;
	mY = currentNode->GetBoundingBox().y;
}

void Weapon::PutOnRandomLocation()
{
	while (Graph::cow->getCurrentNode()->id == currentNode->id ||
		Graph::rabbit->getCurrentNode()->id == currentNode->id ||
		Graph::pill->GetCurrentNode()->id == currentNode->id)
		SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));
}
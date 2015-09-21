#include "Weapon.h"
#include "Graph.h"

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
	// If the rabbit or the cow is on the same spot as the weapon,
	// respawn the weapon somewhere else.
	//if (Graph::cow->currentNode->id == currentNode->id || Graph::rabbit->currentNode->id == currentNode->id)
	//	SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));
}

void Weapon::Draw()
{
	mApplication->DrawTexture(mTexture, mX,mY, 50, 50);
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
	SetCurrentNode(Graph::graphNodes.at(rand() % Graph::graphNodes.size()));
}
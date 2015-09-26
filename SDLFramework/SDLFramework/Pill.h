#pragma once
#include "IGameObject.h"
#include "Node.h"
class Pill :
	public IGameObject
{
public:

	Node* currentNode;
	bool isPickedUp;

	Pill();
	~Pill();
	void Update(float deltaTime) override;
	void Draw() override;
	void SetCurrentNode(Node* newNode);
	Node* GetCurrentNode() { return currentNode; }
	void PutOnRandomLocation();
};

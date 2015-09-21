#pragma once
#include "BaseGameEntity.h"
#include "Node.h"
#include "StateMachine.h"

class Rabbit :
	public BaseGameEntity
{
public:
	Node* currentNode;
	StateMachine<Rabbit>* stateMachine;

	Rabbit(int id);
	~Rabbit();
	virtual void Update(float deltaTime) override;
	virtual void Draw()override;
	void OnLeftClick();
	void OnRightClick();
	void setCurrentNode(Node* node);
	Node* getCurrentNode() { return currentNode; }
	std::string GetCurrentState() { return stateMachine->CurrentState()->GetStateName(); }
	StateMachine<Rabbit>* GetFSM() { return stateMachine;}
};


#pragma once
#include <SDL_events.h> // Note: You need to use <SDL_events.h> and NOT <SDL.H>
#include "BaseGameEntity.h"
#include "Node.h"
#include "StateMachine.h"

class Cow :
	public BaseGameEntity
{
public:
	Node* currentNode;
	StateMachine<Cow>* stateMachine;

	Cow(int id);
	~Cow();
	virtual void Update(float deltaTime) override;
	virtual void Draw()override;
	void OnClick(SDL_Event &event);
	void OnLeftClick(SDL_Event &event);
	void OnRightClick(SDL_Event &event);
	void setCurrentNode(Node* node);
	Node* getCurrentNode() { return currentNode; };
	StateMachine<Cow>* GetFSM() const { return stateMachine; }
	std::string GetCurrentState() { return stateMachine->CurrentState()->GetStateName(); }
};


#pragma once
#include "State.h"
#include "Cow.h"
#include <stack>
#include "Node.h"
#include "Cow.h"
#include "Rabbit.h"

class CowChaseRabbitState :
	public State<Cow>
{
private:
	int stepTimer;
	int counter;
	std::stack<Node*> shortestPath;
	bool pathIsCalculated;
	void UpdateShortestPathLabel(std::stack<Node*> _shortestPath);
public:
	CowChaseRabbitState();
	~CowChaseRabbitState();
	void CalculateNewPath();

	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "Chase Rabbit"; }
	static CowChaseRabbitState* Instance()
	{
		static CowChaseRabbitState instance;
		return &instance;
	}
};

#pragma once
#include "State.h"
#include "Rabbit.h"
#include "Pill.h"
#include <stack>

class RabbitSearchForPillState :
	public State<Rabbit>
{
public:
	int stepTimer = 0;
	std::stack<Node*> shortestPath;

	RabbitSearchForPillState();
	~RabbitSearchForPillState();
	void UpdateShortestPathLabel(Rabbit* rabbit, Pill* pill);
	void Enter(Rabbit* rabbit) override;
	void Execute(Rabbit* rabbit) override;
	void Exit(Rabbit* rabbit) override;
	std::string GetStateName() override { return "Search For Pill"; }
	static RabbitSearchForPillState* Instance()
	{
		static RabbitSearchForPillState instance;
		return &instance;
	}
};


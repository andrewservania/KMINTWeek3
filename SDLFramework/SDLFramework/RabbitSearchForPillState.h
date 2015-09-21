#pragma once
#include "State.h"
#include "Rabbit.h"

class RabbitSearchForPillState :
	public State<Rabbit>
{
public:
	RabbitSearchForPillState();
	~RabbitSearchForPillState();

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


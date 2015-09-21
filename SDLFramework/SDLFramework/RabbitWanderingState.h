#pragma once
#include "State.h"
#include "Rabbit.h"

class RabbitWanderingState :
	public State<Rabbit>
{
public:
	RabbitWanderingState();
	~RabbitWanderingState();

	void Enter(Rabbit* cow) override;
	void Execute(Rabbit* cow) override;
	void Exit(Rabbit* cow) override;
	std::string GetStateName() override { return "Wandering"; }
	static RabbitWanderingState* Instance()
	{
		static RabbitWanderingState instance;
		return &instance;
	}
};


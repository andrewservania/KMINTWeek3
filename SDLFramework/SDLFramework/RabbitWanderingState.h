#pragma once
#include "State.h"
#include "Rabbit.h"

class RabbitWanderingState :
	public State<Rabbit>
{
private:
	int counter;
public:
	RabbitWanderingState();
	~RabbitWanderingState();
	void UsePill(Rabbit* rabbit);
	void UseWeapon(Rabbit* rabbit);
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

#pragma once
#include "State.h"
#include "Rabbit.h"
class RabbitSearchForWeaponState :
	public State<Rabbit>
{
public:
	RabbitSearchForWeaponState();
	~RabbitSearchForWeaponState();

	void Enter(Rabbit* rabbit) override;
	void Execute(Rabbit* rabbit) override;
	void Exit(Rabbit* rabbit) override;
	std::string GetStateName() override { return "Search For Weapon"; }
	static RabbitSearchForWeaponState* Instance()
	{
		static RabbitSearchForWeaponState instance;
		return &instance;
	}

};


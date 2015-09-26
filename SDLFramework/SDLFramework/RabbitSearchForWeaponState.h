#pragma once
#include "State.h"
#include "Rabbit.h"
#include "Weapon.h"
#include "Node.h"
#include <stack>

class RabbitSearchForWeaponState :
	public State<Rabbit>
{
public:
	int stepTimer = 0;
	std::stack<Node*> shortestPath;
	bool rabbitStartedSearching;

	RabbitSearchForWeaponState();
	~RabbitSearchForWeaponState();
	void UpdateShortestPathLabel(std::stack<Node*> _shortestPath);
	void StartSearchingForWeapon(Rabbit* rabbit);
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

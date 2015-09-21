#pragma once
#include "State.h"
#include "Cow.h"
#include <stack>
#include "Node.h"
#include "Cow.h"
#include "Weapon.h"

class CowSearchForWeaponState :
	public State<Cow>
{
private:
	std::stack<Node*> shortestPath;
	int stepTimer;
	void UpdateShortestPathLabel(Cow* cow, Weapon* weapon);

public:
	
	CowSearchForWeaponState();
	~CowSearchForWeaponState();
	
	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "Search For Weapon"; }
	static CowSearchForWeaponState* Instance()
	{
		static CowSearchForWeaponState instance;
		return &instance;
	}
};


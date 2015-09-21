#pragma once
#include "State.h"
#include "Cow.h"


class CowWanderingState :
	public State<Cow>
{
private:
	int counter;
	int boredom;

public:
	CowWanderingState();
	~CowWanderingState();
	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "Wandering"; }
	static CowWanderingState* Instance()
	{
		static CowWanderingState instance;
		return &instance;
	}
};


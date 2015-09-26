#pragma once
#include "State.h"
#include "Cow.h"

class CowSleepingState :
	public State<Cow>
{
public:
	int turn;
	int counter;
	CowSleepingState();
	~CowSleepingState();

	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "Sleeping"; }
	static CowSleepingState* Instance()
	{
		static CowSleepingState instance;
		return &instance;
	}
};

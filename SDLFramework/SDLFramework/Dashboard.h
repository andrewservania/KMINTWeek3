#pragma once
#include <string>

class Dashboard
{
private:
	static std::string applicationInformation;
	static std::string shortestPathLabel;
	static std::string cowStateLabel;
	static std::string rabbitStateLabel;
	static std::string comment1;
	static std::string comment2;
	static std::string comment3;
	static std::string comment4;
	static std::string comment5;
	static std::string comment6;
	static std::string comment7;
	static std::string comment8;
	static std::string comment9;
	static std::string comment10;
	static std::string comment11;
	static std::string comment12;
	static std::string comment13;


	static std::string choice1Probability;
	static std::string choice2Probability;
	static std::string choice3Probability;
	static std::string cowSleepingTurns;

public:

	Dashboard();
	~Dashboard();
	void Update();

	// Accessors
	std::string ApplicationInformation() const { return applicationInformation; }
	std::string ShortestPathLabel() const { return shortestPathLabel; }
	std::string CowStateLabel() const { return cowStateLabel; }
	std::string RabbitStateLabel() const { return rabbitStateLabel; }

	void ApplicationInformation(std::string val) { applicationInformation = val; }
	void ShortestPathLabel(std::string val) { shortestPathLabel = val; }
	void CowStateLabel(std::string val) { cowStateLabel = "Cow State: " + val; }
	void RabbitStateLabel(std::string val) { rabbitStateLabel = "Rabbit state: " + val; }
	void SetChoice1Probablity(int val) { choice1Probability = "Choice 1 - Search For Weapon - Chance: " + std::to_string(val) + "%"; }
	void SetChoice2Probablity(int val) { choice2Probability = "Choice 2 - Search For Pill -  Chance: " + std::to_string(val) + "%"; }
	void SetChoice3Probablity(int val) { choice3Probability = "Choice 3 - Flee From Cow -  Chance: " + std::to_string(val) + "%"; }
	void SetCowSleepingTurns(int val) { cowSleepingTurns = "Cow Sleeping Turns: " + std::to_string(val); }

	static Dashboard* Instance()
	{
		static Dashboard instance;
		return &instance;
	}
};

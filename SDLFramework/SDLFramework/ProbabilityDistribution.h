#pragma once
class ProbabilityDistribution
{
private:
	// Probability is in percentages
	const int totalProbability = 100;
	const int minimumProbabilityPerChoice = 10;

	int currentTotalProbability;
	int choice1Probability;
	int choice2Probability;
	int choice3Probability;
	int lastChangedChoice;

	void UpdateProbabilityLabels();
public:
	void IncreaseChoice1Probability();
	void IncreaseChoice2Probability();
	void IncreaseChoice3Probability();

	ProbabilityDistribution();
	ProbabilityDistribution(int probabilityChoice1, int probabilityChoice2, int probabilityChoice3);
	~ProbabilityDistribution();
	int GenerateRandomChoice();

	int GetChoice1Probability() { return choice1Probability; }
	int GetChoice2Probability() { return choice2Probability; }
	int GetChoice3Probability() { return choice3Probability; }

	static ProbabilityDistribution* Instance()
	{
		static ProbabilityDistribution instance;

		return &instance;
	}
};

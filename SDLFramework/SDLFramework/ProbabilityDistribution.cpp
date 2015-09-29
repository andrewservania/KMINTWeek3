#include "ProbabilityDistribution.h"
#include "Dashboard.h"
#include <cstdlib>
#include <assert.h>
#include <stack>

using namespace std;

// A class created to distribute probability among three choices in the most amateuristic way possible.
// My sincere apologies to any statisticians ,computer-math scientists, scientific software engineers.
// I stand open to all your expert feedback. :)


ProbabilityDistribution::ProbabilityDistribution() : choice1Probability(40), // percent
													 choice2Probability(30), // percent
													 choice3Probability(30)  // percent
{
	currentTotalProbability = totalProbability;
	assert((choice1Probability + choice2Probability + choice3Probability) == 100 && "The probability numbers are incorrect. Make sure the choice percentages equal 100% and 100% only.");
	UpdateProbabilityLabels();
}


ProbabilityDistribution::ProbabilityDistribution(int probabilityChoice1, int probabilityChoice2, int probabilityChoice3)
{
	currentTotalProbability = totalProbability;
	choice1Probability = probabilityChoice1;
	choice2Probability = probabilityChoice2;
	choice3Probability = probabilityChoice3;

	assert((choice1Probability + choice2Probability + choice3Probability) == 100 && "The probability numbers are incorrect. Make sure the choice percentages equal 100% and 100% only.");
	UpdateProbabilityLabels();
}

ProbabilityDistribution::~ProbabilityDistribution()
{
}

int ProbabilityDistribution::GenerateRandomChoice()
{
	int randomNumber = rand() % totalProbability + 1; // number between 0 and 100

	if (randomNumber >= 0 && randomNumber <= choice1Probability) return 1;
	if (randomNumber > choice1Probability && randomNumber <= (choice1Probability + choice2Probability)) return 2;
	if (randomNumber > (choice1Probability + choice2Probability)) return 3;

	return 0; // If the random number does not fall within the above-declared ranges, return 0
}

void ProbabilityDistribution::IncreaseChoice1Probability()
{
	if (choice1Probability != totalProbability - 2 * minimumProbabilityPerChoice)
	{
		if (choice1Probability == totalProbability - minimumProbabilityPerChoice - 1)
		{
			if (choice2Probability > minimumProbabilityPerChoice)
			{
				choice2Probability--;
			}
			else
			{
				choice3Probability--;
			}
			choice1Probability++;
		}
		else
		{
			choice1Probability += 2;
			currentTotalProbability = choice1Probability + choice2Probability + choice3Probability;
			if (currentTotalProbability > 100)
			{
				if (!(choice2Probability == minimumProbabilityPerChoice && choice3Probability == minimumProbabilityPerChoice))
				{
					if (choice2Probability == minimumProbabilityPerChoice)
					{
						if (choice3Probability == minimumProbabilityPerChoice + 1) // To avoid minus values when choice1 = 99, choice2 = 0 and choice3 = 1 and being threatened withing getting -1% as value
						{
							choice3Probability -= 1;
						}
						else{
							choice3Probability -= 2;
						}
					}
					else if (choice3Probability == minimumProbabilityPerChoice){
						if (choice2Probability == minimumProbabilityPerChoice + 1)
						{
							choice2Probability -= 1;
						}
						else{
							choice2Probability -= 2;
						}
					}
					else{
						choice2Probability--;
						choice3Probability--;
					}
					lastChangedChoice = 2;
				}
				else if (currentTotalProbability > 102)
				{
					choice1Probability -= 2;
				}
			}
		}
		UpdateProbabilityLabels();
	}
}

void ProbabilityDistribution::IncreaseChoice2Probability()
{
	if (choice2Probability != totalProbability - 2 * minimumProbabilityPerChoice)
	{
		if (choice2Probability == totalProbability - minimumProbabilityPerChoice - 1)
		{
			if (choice1Probability > minimumProbabilityPerChoice)
			{
				choice1Probability--;
			}
			else
			{
				choice3Probability--;
			}
			choice2Probability++;
		}
		else
		{
			choice2Probability += 2;

			currentTotalProbability = choice1Probability + choice2Probability + choice3Probability;
			if (currentTotalProbability > 100)
			{
				if (!(choice1Probability == minimumProbabilityPerChoice && choice3Probability == minimumProbabilityPerChoice))
				{
					if (choice1Probability == minimumProbabilityPerChoice)
					{
						if (choice3Probability == minimumProbabilityPerChoice + 1) // To avoid minus values when choice1 = 99, choice2 = 0 and choice3 = 1 and being threatened withing getting -1% as value
						{
							choice3Probability -= 1;
						}
						else{
							choice3Probability -= 2;
						}
					}
					else if (choice3Probability == minimumProbabilityPerChoice){
						if (choice1Probability == minimumProbabilityPerChoice + 1) // To avoid minus values when choice1 = 99, choice2 = 0 and choice3 = 1 and being threatened withing getting -1% as value
						{
							choice1Probability -= 1;
						}
						else{
							choice1Probability -= 2;
						}
					}
					else{
						choice1Probability--;
						choice3Probability--;
					}
					lastChangedChoice = 2;
				}
				else if (currentTotalProbability > 102)
				{
					choice2Probability -= 2;
				}
			}
		}
		UpdateProbabilityLabels();
	}
}

void ProbabilityDistribution::IncreaseChoice3Probability()
{
	if (choice3Probability != totalProbability - 2 * minimumProbabilityPerChoice)
	{
		if (choice3Probability == totalProbability - minimumProbabilityPerChoice - 1)
		{
			if (choice2Probability > minimumProbabilityPerChoice)
			{
				choice2Probability--;
			}
			else
			{
				choice1Probability--;
			}
			choice3Probability++;
		}
		else{
			choice3Probability += 2;

			currentTotalProbability = choice1Probability + choice2Probability + choice3Probability;
			if (currentTotalProbability > 100)
			{
				if (!(choice1Probability == minimumProbabilityPerChoice && choice2Probability == minimumProbabilityPerChoice))
				{
					if (choice1Probability == minimumProbabilityPerChoice)
					{
						if (choice2Probability == minimumProbabilityPerChoice + 1) // To avoid minus values when choice1 = 99, choice2 = 0 and choice3 = 1 and being threatened withing getting -1% as value
						{
							choice2Probability -= 1;
						}
						else{
							choice2Probability -= 2;
						}
					}
					else if (choice2Probability == minimumProbabilityPerChoice){
						if (choice1Probability == minimumProbabilityPerChoice + 1) // To avoid minus values when choice1 = 99, choice2 = 0 and choice3 = 1 and being threatened withing getting -1% as value
						{
							choice1Probability -= 1;
						}
						else{
							choice1Probability -= 2;
						}
					}
					else{
						choice1Probability--;
						choice2Probability--;
					}
					lastChangedChoice = 3;
				}
				else if (currentTotalProbability > 102)
				{
					choice3Probability -= 2;
				}
			}
		}

		UpdateProbabilityLabels();
	}
}

void ProbabilityDistribution::UpdateProbabilityLabels()
{
	Dashboard::Instance()->SetChoice1Probablity(choice1Probability);
	Dashboard::Instance()->SetChoice2Probablity(choice2Probability);
	Dashboard::Instance()->SetChoice3Probablity(choice3Probability);
}
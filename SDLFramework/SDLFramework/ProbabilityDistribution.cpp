#include "ProbabilityDistribution.h"
#include "Dashboard.h"
#include <cstdlib>
#include <assert.h>
#include <stack>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// A class created to distribute probability among three choices in the most amateuristic way
/// possible. My sincere apologies to any statisticians ,computer-math scientists, scientific
/// software engineers. I stand open to all your expert feedback. :)
/// 
/// Create a probability distribution object that can distribute the probability percentage
/// between 3 choices. These 3 choices get the following probability distribution by default
/// Choice 1 40% 
/// Choice 2 30%
/// Choice 3 30%
/// 
/// The method
/// </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

ProbabilityDistribution::ProbabilityDistribution() : choice1Probability(40), // percent
													 choice2Probability(30), // percent
													 choice3Probability(30)  // percent
{
	currentTotalProbability = totalProbability;
	assert((choice1Probability + choice2Probability + choice3Probability) == 100 && "The probability numbers are incorrect. Make sure the choice percentages equal 100% and 100% only.");
	UpdateProbabilityLabels();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

ProbabilityDistribution::~ProbabilityDistribution()
{
}

/// <summary>	Constructor. 
/// 			
/// 			Creates a probability distribution object that percentages custom-provided percentages
/// 			The function checks in order to make sure that percentages ALWAYS sum up to 100 and 100 ONLY.
/// 			
/// 			</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="probabilityChoice1">	The first probability choice. </param>
/// <param name="probabilityChoice2">	The second probability choice. </param>
/// <param name="probabilityChoice3">	The third probability choice. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

ProbabilityDistribution::ProbabilityDistribution(int probabilityChoice1, int probabilityChoice2, int probabilityChoice3)
{
	currentTotalProbability = totalProbability;
	choice1Probability = probabilityChoice1;
	choice2Probability = probabilityChoice2;
	choice3Probability = probabilityChoice3;

	assert((choice1Probability + choice2Probability + choice3Probability) == 100 && "The probability numbers are incorrect. Make sure the choice percentages equal 100% and 100% only.");
	UpdateProbabilityLabels();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Generates a random choice (in the form an integer) based on the distributed 
/// 			probabilities. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <returns>	The random choice. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

int ProbabilityDistribution::GenerateRandomChoice()
{
	int randomNumber = rand() % totalProbability + 1; // number between 0 and 100

	if (randomNumber >= 0 && randomNumber <= choice1Probability) return 1;
	if (randomNumber > choice1Probability && randomNumber <= (choice1Probability + choice2Probability)) return 2;
	if (randomNumber > (choice1Probability + choice2Probability)) return 3;

	return 0; // If the random number does not fall within the above-declared ranges, return 0
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Increase choice 1 probability by 2% while making sure that a choice never gets a probability
/// 			greater than 80% or lower than 10% </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Increase choice 2 probability by 2% while making sure that a choice never gets a 
/// 			probability greater than 80% or lower than 10% </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Increase choice 3 probability by 2% while making sure that a choice never gets a
/// 			probability greater than 80% or lower than 10% </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the probability labels with the lastest probability values. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ProbabilityDistribution::UpdateProbabilityLabels()
{
	Dashboard::Instance()->SetChoice1Probablity(choice1Probability);
	Dashboard::Instance()->SetChoice2Probablity(choice2Probability);
	Dashboard::Instance()->SetChoice3Probablity(choice3Probability);
}
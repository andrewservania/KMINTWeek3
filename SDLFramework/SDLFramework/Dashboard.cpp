#include "Dashboard.h"
#include "FWApplication.h"
#include "Graph.h"
#include "ProbabilityDistribution.h"

std::string Dashboard::applicationInformation;
std::string Dashboard::shortestPathLabel;
std::string Dashboard::cowStateLabel;
std::string Dashboard::rabbitStateLabel;

std::string Dashboard::comment1;
std::string Dashboard::comment2;
std::string Dashboard::comment3;
std::string Dashboard::comment4;
std::string Dashboard::comment5;
std::string Dashboard::comment6;
std::string Dashboard::comment7;
std::string Dashboard::comment8;
std::string Dashboard::comment9;
std::string Dashboard::comment10;
std::string Dashboard::comment11;
std::string Dashboard::comment12;
std::string Dashboard::comment13;


std::string Dashboard::choice1Probability;
std::string Dashboard::choice2Probability;
std::string Dashboard::choice3Probability;

std::string Dashboard::cowSleepingTurns;
using namespace std;

Dashboard::Dashboard()
{
	ApplicationInformation("Andrew Servania - KMINT Week 3");

	//comment1 = "The cow starts in a 'Chasing' state. When the cow reaches the rabbit. The rabbit makes a";
	//comment2 = "choice between three states: 'Fleeing','Search For Weapon' or Search For Pill.'";

	//comment3 = "The probability of a state being chosen depends on the probability percentage assigned to";
	//comment4 = "a given state. Initially 'Fleeing' has a 30% chance of being chosen. Search For Weapon has 40%";
	//comment5 = "and 'Search For Pill' has 30%. A states probability is increased by 2% evertime it is chosen.";
	//comment6 = "If the rabbit chooses to 'Flee'. It jumps to a random node.";

	//comment7 = "If the rabbit chooses to 'Search For a Pill it uses the A*star path-finding algorithm to find the shortest path to";
	//comment8 = "the pill. If the cow reaches the rabbit, the cow goes in a 'Sleeping' state for 5 turns and rabbit 'Flee's";
	//comment9 = "to safety. If the rabbit chooses to 'Search For a Weapon' it uses A*star as well to search for a weapon.";
	//comment10 = "After picking up the weapon, if the cow reaches a neighboring node of rabbit. The cow gets ";
	//comment11 = "gets 'blown' away to a random location. The pill and the weapon always  respawn on an empty ";
	//comment12 = "node.";

	comment1 = "The cow starts in a 'Chasing' state and the rabbit in a 'Wandering' state.";
	comment2 = "When the cow reaches the rabbit, the rabbit makes a choice between three states:";
	comment3 = "'Fleeing', 'Search For Weapon' or Search For Pill.'";


	comment4 = "If the rabbit chooses to 'Search For a Pill' it uses the A*star path-finding algorithm to find the";
	comment5 = "shortest path to the pill. If the cow reaches the rabbit, the cow goes in a 'Sleeping' state for 5 turns";
	comment6 = "and the rabbit  'Flees' to safety. If the rabbit chooses to 'Search For a Weapon', whenever ";
	comment7 = "the cow reaches a neighboring node of the rabbit, the cow gets 'blown' away to a random location.";
	comment8 = "The rabbit uses A*star as well to search for a weapon. The pill and the weapon ";
	comment9 = "always  respawn on an empty node. If the rabbit chooses to 'Flee'. It jumps to a random node.";

	comment10 = "The probability of a state being chosen simply depends on the probability percentage assigned to";
	comment11 = "a given state. Initially 'Fleeing' has a 30% chance of being chosen. Search For Weapon has 40%";
	comment12 = "and 'Search For Pill' has 30%. A state's probability is increased by 2% evertime it is chosen.";
	comment13 = "The minimum percentage for each state is 10%. and the maximum is 80%.";


  //comment6 = "-------------------------------------------------------------------------------------------";
	//ShortestPathLabel("");

	SetChoice1Probablity(ProbabilityDistribution::Instance()->GetChoice1Probability());
	SetChoice2Probablity(ProbabilityDistribution::Instance()->GetChoice2Probability());
	SetChoice3Probablity(ProbabilityDistribution::Instance()->GetChoice3Probability());

	cowSleepingTurns = "Cow Sleeping Turns: 0";
}

Dashboard::~Dashboard()
{
}

void Dashboard::Update()
{
	// Application information
	FWApplication::GetInstance()->DrawText(applicationInformation, 300, 50);

	// KMINT Week 3 Description
	FWApplication::GetInstance()->DrawText(comment1, 300, 100);
	FWApplication::GetInstance()->DrawText(comment2, 300, 120);
	FWApplication::GetInstance()->DrawText(comment3, 300, 140);
	FWApplication::GetInstance()->DrawText(comment4, 300, 180);
	FWApplication::GetInstance()->DrawText(comment5, 300, 200);
	FWApplication::GetInstance()->DrawText(comment6, 300, 220);
	FWApplication::GetInstance()->DrawText(comment7, 300, 240);
	FWApplication::GetInstance()->DrawText(comment8, 300, 260);
	FWApplication::GetInstance()->DrawText(comment9, 300, 280);
	FWApplication::GetInstance()->DrawText(comment10, 300, 320);
	FWApplication::GetInstance()->DrawText(comment11, 300, 340);
	FWApplication::GetInstance()->DrawText(comment12, 300, 360);
	FWApplication::GetInstance()->DrawText(comment13, 300, 380);

	// Cow state label
	CowStateLabel(Graph::cow->GetCurrentState());
	FWApplication::GetInstance()->DrawText(cowStateLabel, 300, 420);
	// Cow sleeping turn
	FWApplication::GetInstance()->DrawText(cowSleepingTurns, 300, 440);

	// Rabbit state label
	RabbitStateLabel(Graph::rabbit->GetCurrentState());
	FWApplication::GetInstance()->DrawText(rabbitStateLabel, 300, 460);

	// Shortest path label
	FWApplication::GetInstance()->DrawText(shortestPathLabel, 300, 500);

	// Probabilities
	FWApplication::GetInstance()->DrawText(choice1Probability, 300, 540);
	FWApplication::GetInstance()->DrawText(choice2Probability, 300, 560);
	FWApplication::GetInstance()->DrawText(choice3Probability, 300, 580);

}
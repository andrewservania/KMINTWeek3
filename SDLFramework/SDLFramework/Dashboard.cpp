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

std::string Dashboard::choice1Probability;
std::string Dashboard::choice2Probability;
std::string Dashboard::choice3Probability;

std::string Dashboard::cowSleepingTurns;
using namespace std;

Dashboard::Dashboard()
{
	ApplicationInformation("Andrew Servania - KMINT Week 3");
	comment1 = "-------------------------------------------------------------------------------------------";
	comment2 = "-------------------------------------------------------------------------------------------";
	comment3 = "-------------------------------------------------------------------------------------------";
	comment4 = "-------------------------------------------------------------------------------------------";
	comment5 = "-------------------------------------------------------------------------------------------";
	comment6 = "-------------------------------------------------------------------------------------------";
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

	// Application comments
	FWApplication::GetInstance()->DrawText(comment1, 300, 100);
	FWApplication::GetInstance()->DrawText(comment2, 300, 120);
	FWApplication::GetInstance()->DrawText(comment3, 300, 140);
	FWApplication::GetInstance()->DrawText(comment4, 300, 160);
	FWApplication::GetInstance()->DrawText(comment5, 300, 180);
	FWApplication::GetInstance()->DrawText(comment6, 300, 200);

	// Cow state label
	CowStateLabel(Graph::cow->GetCurrentState());
	FWApplication::GetInstance()->DrawText(cowStateLabel, 300, 320);

	// Rabbit state label
	RabbitStateLabel(Graph::rabbit->GetCurrentState());
	FWApplication::GetInstance()->DrawText(rabbitStateLabel, 300, 340);

	// Shortest path label
	FWApplication::GetInstance()->DrawText(shortestPathLabel, 300, 400);

	// Probabilities
	FWApplication::GetInstance()->DrawText(choice1Probability, 300, 440);
	FWApplication::GetInstance()->DrawText(choice2Probability, 300, 460);
	FWApplication::GetInstance()->DrawText(choice3Probability, 300, 480);

	// Cow sleeping turn
	FWApplication::GetInstance()->DrawText(cowSleepingTurns, 300, 500);
}
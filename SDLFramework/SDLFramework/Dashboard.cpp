#include "Dashboard.h"
#include "FWApplication.h"
#include "Graph.h"

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

int Dashboard::cowBoredomLevel;

using namespace std;

Dashboard::Dashboard()
{
	ApplicationInformation("Andrew Servania - KMINT Week 2");
		comment1 = "The cow and the rabbit start in a Wandering state.";
		comment2 = "While the cow wanders around, its boredom level raises.";
		comment3 = "When it reaches level 10, it goes on a search for a pill.";
		comment4 = "The pill triggers the cow to go and chase the rabbit.";
		comment5 = "When the cow reaches the rabbit, the rabbit goes into a Fleeing state,";
		comment6 = "jumps to a random location and both the cow and the rabbit go back to a Wandering state.";
		cowBoredomLevel = 0;
		ShortestPathLabel("");
}


Dashboard::~Dashboard()
{
}

void Dashboard::Update()
{
	FWApplication::GetInstance()->DrawText(applicationInformation, 300, 50);

	FWApplication::GetInstance()->DrawText(comment1, 300, 100);
	FWApplication::GetInstance()->DrawText(comment2, 300, 120);
	FWApplication::GetInstance()->DrawText(comment3, 300, 140);
	FWApplication::GetInstance()->DrawText(comment4, 300, 160);
	FWApplication::GetInstance()->DrawText(comment5, 300, 180);
	FWApplication::GetInstance()->DrawText(comment6, 300, 200);

	CowStateLabel(Graph::cow->GetCurrentState());
	FWApplication::GetInstance()->DrawText(cowStateLabel, 300, 320);
	RabbitStateLabel(Graph::rabbit->GetCurrentState());
	FWApplication::GetInstance()->DrawText(rabbitStateLabel, 300, 340);

	FWApplication::GetInstance()->DrawText("Cow boredom level: " + to_string(cowBoredomLevel), 300, 380);
	FWApplication::GetInstance()->DrawText(shortestPathLabel, 300, 400);


}
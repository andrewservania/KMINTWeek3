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
	FWApplication::GetInstance()->DrawText(shortestPathLabel, 300, 400);


}
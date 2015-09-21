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
	
	 static int cowBoredomLevel;
public:

	Dashboard();
	~Dashboard();
	void Update();

	// Accessors
	 std::string ApplicationInformation() const { return applicationInformation; }
	 std::string ShortestPathLabel() const { return shortestPathLabel; }
	 std::string CowStateLabel() const { return cowStateLabel; }
	 std::string RabbitStateLabel() const { return rabbitStateLabel; }
	 int CowBoredomLevel() const { return cowBoredomLevel;}

	void ApplicationInformation(std::string val) { applicationInformation = val; }
	void ShortestPathLabel(std::string val) { shortestPathLabel = val; }
	void CowStateLabel(std::string val) { cowStateLabel = "Cow State: " + val; }
	void RabbitStateLabel(std::string val) { rabbitStateLabel = "Rabbit state: " + val; }
	void CowBoredomLevel(int val) { cowBoredomLevel = val; }
	static Dashboard* Instance()
	{
		static Dashboard instance;
		return &instance;
	}
};


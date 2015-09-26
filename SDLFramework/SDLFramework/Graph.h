#pragma once
#include "Rabbit.h"
#include "Cow.h"
#include "Pill.h"
#include "Weapon.h"

class Graph
{
public:
	static Cow* cow;
	static Rabbit* rabbit;
	static Pill* pill;
	static Weapon* weapon;

	Node* node1;
	Node* node2;
	Node* node3;
	Node* node4;
	Node* node5;
	Node* node6;
	Node* node7;
	Node* node8;

	static std::vector<Node*> graphNodes;

	Graph(FWApplication* _application);
	~Graph();
	static void UpdateShortPathDescription();
};

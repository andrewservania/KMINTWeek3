#include "Graph.h"
#include <memory>
#include "AStar.h"
#include <string>
#include "Dashboard.h"

using namespace std;

Cow* Graph::cow;
Rabbit* Graph::rabbit;
vector<Node*> Graph::graphNodes;
Pill* Graph::pill;
Weapon* Graph::weapon;

Graph::Graph(FWApplication* _application)
{
	// Create nodes
	node1 = new Node(1);
	node2 = new Node(2);
	node3 = new Node(3);
	node4 = new Node(4);
	node5 = new Node(5);
	node6 = new Node(6);
	node7 = new Node(7);
	node8 = new Node(8);

	// Set their position on screen
	node1->SetOffset(900, 450);
	node2->SetOffset(600, 400);
	node3->SetOffset(700, 100);
	node4->SetOffset(830, 240);
	node5->SetOffset(1000, 100);
	node6->SetOffset(1030, 400);
	node7->SetOffset(1150, 550);
	node8->SetOffset(1150, 300);

	// Connect nodes with edges and add weight to the edges
	node1->AddEdge(node2, 10000);
	node1->AddEdge(node7, 10000);
	node1->AddEdge(node6, 10000);
	node2->AddEdge(node3, 10000);
	node2->AddEdge(node4, 10000);
	node2->AddEdge(node8, 10000);
	node3->AddEdge(node4, 10000);
	node3->AddEdge(node5, 10000);
	node4->AddEdge(node6, 10000);
	node4->AddEdge(node5, 10000);
	node5->AddEdge(node6, 10000);
	node5->AddEdge(node8, 10000);
	node7->AddEdge(node8, 10000);

	// Add the nodes to a vector
	graphNodes.push_back(node1);
	graphNodes.push_back(node2);
	graphNodes.push_back(node3);
	graphNodes.push_back(node4);
	graphNodes.push_back(node5);
	graphNodes.push_back(node6);
	graphNodes.push_back(node7);
	graphNodes.push_back(node8);

	rabbit = new Rabbit(1);												// 1) Create a rabbit
	pill = new Pill();													// 2) Create a pill at a random location
	weapon = new Weapon();												// 3) Create a weapon at a random location
	cow = new Cow(2);													// 4) Create a cow
	// NOTE: If one wants to change the order of creation of game entities, then the respawn checks declared
	//		 within their constructors must be adapted in order to keep making sure that none of the entities
	//       respawn on the same location.

	UpdateShortPathDescription();										// Update the shortest path label with the shortest path based on the cow and rabbit's current node
}

Graph::~Graph()
{
}

// Calculate and shortest path from the cow to the rabbit and update the shortest path label on the screen
void Graph::UpdateShortPathDescription()
{
	shared_ptr<AStar> aStar = make_shared<AStar>();
	auto shortestPath = aStar->GetShortestPath(cow->getCurrentNode(), rabbit->getCurrentNode());
	string shortestPathLabel = "Shortest path from cow to rabbit: ";
	while (!shortestPath.empty())
	{
		Node* step = shortestPath.top();

		shortestPathLabel += to_string(step->id).c_str();

		shortestPath.pop();
		if (!shortestPath.empty())
			shortestPathLabel += " -> ";
	}

	Dashboard::Instance()->ShortestPathLabel(shortestPathLabel);
}
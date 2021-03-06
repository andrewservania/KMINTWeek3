#include "Edge.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Edge::Edge()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Edge::~Edge()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// Create an edge based on a parent node and a child node and add it to renderable objects.
/// </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="weight">	The weight. </param>
/// <param name="parent">	[in,out] If non-null, the parent. </param>
/// <param name="child"> 	[in,out] If non-null, the child. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Edge::Edge(double weight, Node* parent, Node* child)
{
	this->weight = weight;
	this->parent = parent;
	this->child = child;
	mApplication->AddRenderable(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the edge with a given delta time </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Edge::Update(float deltaTime)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draw the actual edge on screen. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Edge::Draw()
{
	mApplication->SetColor(Color(255, 0, 0, 255));
	mApplication->DrawLine(xStart, yStart, xEnd, yEnd);
	mApplication->SetColor(Color(255, 255, 255, 255));
}
#pragma once
#include "IGameObject.h"
class BaseGameEntity :
	public IGameObject
{
private:

	int id;										// Every entity has a unique identifying number

	static int nextValidID;						// This is the next valid ID. Each time a BaseGameEntity is instantiated
												// this value is updated
	void SetID(int val);
public:
	BaseGameEntity(int id);
	virtual ~BaseGameEntity();
	virtual void Update(float deltaTime) = 0;
	int ID() const{ return id; }

};


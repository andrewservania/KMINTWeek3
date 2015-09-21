#include "BaseGameEntity.h"

int BaseGameEntity::nextValidID = 0;

BaseGameEntity::BaseGameEntity(int id)
{
	SetID(id);
}


BaseGameEntity::~BaseGameEntity()
{
}

void BaseGameEntity::SetID(int val)
{
	if (val >= nextValidID)
	{
		id = val;
		nextValidID++;
	}

}

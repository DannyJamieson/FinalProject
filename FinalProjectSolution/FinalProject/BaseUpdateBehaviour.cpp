#include "BaseUpdateBehaviour.h"

std::vector<BaseUpdateBehaviour*> BaseUpdateBehaviour::UpdateBehaviours;//List of Update Behaviours

BaseUpdateBehaviour::BaseUpdateBehaviour()
{
	UpdateBehaviours.push_back(this);
}


BaseUpdateBehaviour::~BaseUpdateBehaviour()
{
}



#include "firePillar.h"



firePillar::firePillar()
{
}

void firePillar::Update(DWORD dt)
{
	GameObject::Update(dt);
	this->SetState(FIRE_PILLAR_STATE_IDLE);
}

void firePillar::Render()
{
	int ani;
	if (state == FIRE_PILLAR_STATE_IDLE)
	{
		ani = FIRE_PILLAR_ANI_IDLE;
	}
	else
	{
		ani = FIRE_PILLAR_ANI_DESTROY;
	}
	animations[ani]->Render(x, y);
}

void firePillar::SetState(int state)
{
	GameObject::SetState(state);
}


firePillar::~firePillar()
{
}

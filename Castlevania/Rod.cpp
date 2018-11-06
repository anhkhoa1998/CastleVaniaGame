#include "Rod.h"



Rod::Rod()
{
}

void Rod::Update(DWORD dt)
{
	GameObject::Update(dt);
	
}

void Rod::Render()
{
	int ani;
	if (vx == 0)
	{
		if (nx > 0) ani = SIMON_ANI_IDLE_RIGHT;
		else ani = SIMON_ANI_IDLE_LEFT;
	}
	else if (vx > 0)
		ani = SIMON_ANI_WALKING_RIGHT;
	else ani = SIMON_ANI_WALKING_LEFT;

	animations[ani]->Render(x, y);
}

void Rod::SetState(int state)
{
	GameObject::SetState(state);
	switch (state)
	{
	case SIMON_STATE_WALKING_RIGHT:
		vx = SIMON_WALKING_SPEED;
		nx = 1;
		break;
	}
}

void Rod::SetPosition(simon * Simon)
{
	this->x = Simon->GetX();
	this->y = Simon->GetY();
}



Rod::~Rod()
{
	
}

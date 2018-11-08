#include "Weapon.h"
#include"Game.h"
#include"GameObject.h"
#include<algorithm>


Weapon::Weapon()
{

}

void Weapon::Update(DWORD dt, simon*Simon)
{
	GameObject::Update(dt);
	int ani;
	if (state == WEAPON_STATE_FIGHT)
	{
		if (Simon->GetNx() == 1)
		{
			ani = WEAPON_ANI_FIGHT_RIGHT;
			float X = Simon->GetX() + animations[ani]->getXp();
			float Y = Simon->GetY() + animations[ani]->getYp();
			this->SetPosition(Simon,X,Y);
		}
	}
}

void Weapon::Render(simon * Simon)
{
	int ani;
	if (state == WEAPON_STATE_FIGHT)
	{
		if (Simon->GetNx() == 1)
		{
			ani = WEAPON_ANI_FIGHT_RIGHT;
			animations[ani]->Render(x, y);
		}
		else
		{
			ani = WEAPON_ANI_FIGHT_LEFT;
			animations[ani]->Render(x, y);
		}
		
	}


}

void Weapon::SetState(int state,simon * Simon)
{
	GameObject::SetState(state);
	switch (state)
	{
	case WEAPON_STATE_FIGHT:
		vx = 0;
		break;
	case WEAPON_STATE_IDLE:
		break;
	}

}

void Weapon::SetPosition(simon * simon,float x,float y)
{
	this->x = x;
	this->y = y;
}


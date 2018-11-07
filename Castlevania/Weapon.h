#pragma once
#include "GameObject.h"
#include "simon.h"
#define WEAPON_STATE_FIGHT 0
#define WEAPON_STATE_IDLE 1
#define WEAPON_ANI_FIGHT_RIGHT   6
#define WEAPON_ANI_FIGHT_LEFT	 7


class Weapon :public GameObject
{
private:
	int level;

public:
	Weapon();
	virtual void Update(DWORD dt, simon *simon);
	virtual void Render(simon *simon);
	void SetState(int state, simon *simon);
	void SetLevel(int l = 1) { this->level = l; }
	void SetPosition(simon *simon,float x,float y);

};
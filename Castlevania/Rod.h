#pragma once
#include "GameObject.h"
#include "simon.h"

#define ROD_STATE_ATTACK  100
#define ROD_STATE_IDLE 200

#define ROD_ATTACK_RIGHT 6
#define ROD_ATTACK_LEFT  7

class Rod :public GameObject
{
public:
	Rod();
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
	void SetPosition(simon*Simon);
	~Rod();
};


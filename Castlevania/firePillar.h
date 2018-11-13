#pragma once
#include "GameObject.h"


#define FIRE_PILLAR_STATE_IDLE 0
#define FIRE_PILLAR_STATE_DESTROY 1

#define FIRE_PILLAR_ANI_IDLE 8
#define FIRE_PILLAR_ANI_DESTROY 9
class firePillar :public GameObject
{
public:
	firePillar();
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
	~firePillar();
};


#pragma once
#include "GameObject.h"

#define SIMON_WALKING_SPEED		0.1f
#define SIMON_JUMP_SPEED_Y		0.5f
#define SIMON_GRAVITY			0.1f

#define SIMON_STATE_IDLE_LEFT		0
#define SIMON_STATE_IDLE_RIGHT      50
#define SIMON_STATE_WALKING_RIGHT	100
#define SIMON_STATE_WALKING_LEFT	200
#define SIMON_STATE_JUMP			300
#define SIMON_STATE_ATTACK_RIGHT    400
#define SIMON_STATE_ATTACK_LEFT		500

#define SIMON_ANI_IDLE_RIGHT		0
#define SIMON_ANI_IDLE_LEFT			1
#define SIMON_ANI_WALKING_RIGHT		2
#define SIMON_ANI_WALKING_LEFT		3
#define SIMON_ANI_ATTACK_RIGHT		4
#define SIMON_ANI_ATTACK_LEFT		5

class simon :public GameObject
{
	
public:
	void Update(DWORD dt);
	void Render();
	void SetState(int state);

	int GetState() { return this->state;}
	int GetDir() { return nx; }
};


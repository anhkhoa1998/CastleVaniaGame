#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "Animations.h"


class GameObject
{
protected:
	float x;
	float y;

	float vx;
	float vy;

	float nx;

	int state;

	static vector<LPANIMATION> animations;
public:
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetState(int state) { this->state = state; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = y; }

	void GetState() { this->state; }
	float GetX() { return this->x; }
	float GetY() { return this->y; }
	static void AddAnimation(int aniId);

	GameObject();

	void Update(DWORD dt);
	void Render();
	~GameObject();
};


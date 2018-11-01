#include <d3dx9.h>

#include "GameObject.h"
#include "Game.h"
#include "Sprite.h"



GameObject::GameObject()
{
	x = y = 0;
	vx = 0.07f;
}

void GameObject::AddAnimation(int aniId)
{
	LPANIMATION ani = Animations::GetInstance()->Get(aniId);
	animations.push_back(ani);
}

void GameObject::Update(DWORD dt)
{
	x += vx * dt;
	if ((vx > 0 && x > 290) || (x < 0 && vx < 0)) vx = -vx;

}

void GameObject::Render()
{
	LPANIMATION ani;
	if (vx > 0) ani = animations[0]; else ani = animations[1];
	//ani = animations[0];
	ani->Render(x, y);
}

GameObject::~GameObject()
{

}

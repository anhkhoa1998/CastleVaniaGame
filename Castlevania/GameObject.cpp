#include <d3dx9.h>

#include "GameObject.h"
#include "Game.h"
#include "Sprite.h"

vector<LPANIMATION> GameObject::animations;

GameObject::GameObject()
{
	x = y = 0;
	vx = vy = 0;
	nx = 1;
}

void GameObject::AddAnimation(int aniId)
{
	LPANIMATION ani = Animations::GetInstance()->Get(aniId);
	animations.push_back(ani);
}

void GameObject::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

}

void GameObject::Render()
{
	
}

GameObject::~GameObject()
{

}

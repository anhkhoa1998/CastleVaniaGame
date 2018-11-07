#include "Sprite.h"
#include "Game.h"



Sprite::Sprite(int id,int left,int top, int right,int bottom, LPDIRECT3DTEXTURE9 tex,int xP,int yP)
{
	this->id = id;
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
	this->texture = tex;
	this->xP = xP;
	this->yP = yP;

}

Sprite::~Sprite()
{
}

Sprites * Sprites::__instance = NULL;

Sprites * Sprites::GetInstance()
{
	if (__instance == NULL) __instance = new Sprites();
	return __instance;
}

void Sprite::Draw(float x, float y)
{
	Game * game = Game::GetInstance();
	game->Draw(x+xP, y+yP, texture, left, top, right, bottom);
}

void Sprites::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex,int xP,int yP)
{
	LPSPRITE s = new Sprite(id, left, top, right, bottom,tex,xP,yP);
	sprites[id] = s;

}

LPSPRITE Sprites::Get(int id)
{
	return sprites[id];
}



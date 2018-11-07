#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include <unordered_map>

using namespace std;

class Sprite
{
	int id;

	int left;
	int top;
	int right;
	int bottom;

	int xP;
	int yP;

	LPDIRECT3DTEXTURE9 texture;
public:

	Sprite(int id, int left,int top,int right,int bottom,LPDIRECT3DTEXTURE9 tex,int xP,int yP);

	void Draw(float x, float y);
	float getXp() { return xP; }
	float getYp() { return yP; }
	~Sprite();
};

typedef Sprite* LPSPRITE;

class Sprites
{
	static Sprites * __instance;

	unordered_map<int, LPSPRITE> sprites;

public:
	void Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex,int xP,int yP);
	LPSPRITE Get(int id);
	

	static Sprites * GetInstance();
};




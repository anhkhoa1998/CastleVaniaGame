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

	LPDIRECT3DTEXTURE9 texture;
public:

	Sprite(int id, int left,int top,int right,int bottom,LPDIRECT3DTEXTURE9 tex);

	void Draw(float x, float y);
	~Sprite();
};

typedef Sprite* LPSPRITE;

class Sprites
{
	static Sprites * __instance;

	unordered_map<int, LPSPRITE> sprites;

public:
	void Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	LPSPRITE Get(int id);

	static Sprites * GetInstance();
};




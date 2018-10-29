#pragma once

#include <Windows.h>
#include <d3dx9.h>


class GameObject
{
protected:
	float x;
	float y;

	LPDIRECT3DTEXTURE9 texture;
public:
	void SetPosition(float x, float y) { this->x = x, this->y = y; }

	GameObject(LPCWSTR texturePath);
	void Update(DWORD dt);
	void Render();
	~GameObject();
};


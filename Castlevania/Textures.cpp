#include <Windows.h>

#include <d3dx9.h>
#include <d3d9.h>

#include "Game.h"
#include "Textures.h"

Textures * Textures::__instance = NULL;



Textures *Textures::GetInstance()
{
	if (__instance == NULL) __instance = new Textures();
	return __instance;
}

Textures::Textures()
{
}

void Textures::Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(filePath, &info);
	if (result != D3D_OK)
	{
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv = Game::GetInstance()->GetDirect3DDevice();
	LPDIRECT3DTEXTURE9 texture;

	result = D3DXCreateTextureFromFileEx(
		d3ddv,								// Pointer to Direct3D device object
		filePath,							// Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		NULL,
		&texture);								// Created texture pointer

	if (result != D3D_OK)
	{
		return;
	}

	textures[id] = texture;
}


LPDIRECT3DTEXTURE9 Textures::Get(unsigned int i)
{
	return textures[i];
}
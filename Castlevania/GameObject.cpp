#include <d3dx9.h>

#include "GameObject.h"
#include "Game.h"


GameObject::GameObject(LPCWSTR texturePath)
{
	x = y = 0;

	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(texturePath, &info);
	if (result != D3D_OK)
	{
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv = Game::GetInstance()->GetDirect3DDevice();

	result = D3DXCreateTextureFromFileEx(
		d3ddv,								
		texturePath,						
		info.Width,							
		info.Height,						
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255),			
		&info,
		NULL,
		&texture);								

	if (result != D3D_OK)
	{
		return;
	}
}

void GameObject::Update(DWORD dt)
{

}

void GameObject::Render()
{
	Game::GetInstance()->Draw(x, y, texture);
}

GameObject::~GameObject()
{
	if (texture != NULL) texture->Release();
}

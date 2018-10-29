#include "Game.h"

Game*Game::__instance = NULL;

void Game::Init(HWND hWnd)
{
	LPDIRECT3D9 d3d = Direct3DCreate9(D3D_SDK_VERSION);
	this->hWnd = hWnd;

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;

	RECT r;
	GetClientRect(hWnd, &r);

	d3dpp.BackBufferHeight = r.bottom + 1;
	d3dpp.BackBufferWidth = r.right + 1;

	d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddv);

	if (d3ddv == NULL)
	{
		MessageBox(NULL,L"d3ddv khong co gia tri", L"Caption of STDIO.VN", MB_OK);
		return;
	}

	d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	
	D3DXCreateSprite(d3ddv, &spriteHandler);
}

void Game::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture)
{
	D3DXVECTOR3 p(x, y, 0);
	spriteHandler->Draw(texture, NULL, NULL, &p, D3DCOLOR_XRGB(255, 255, 255));
}

Game::Game()
{
}


Game::~Game()
{
	if (spriteHandler != NULL) spriteHandler->Release();
	if (backBuffer != NULL) backBuffer->Release();
	if (d3ddv != NULL) d3ddv->Release();
	if (d3d != NULL) d3d->Release();
}

Game* Game::GetInstance()
{
	if (__instance == NULL) __instance = new Game();
	return __instance;
}

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>


#include "Game.h"
#include "simon.h"
#include "GameObject.h"
#include "Textures.h"
#include "Animations.h"
#include "Sprite.h"
#include "Weapon.h"
#include "firePillar.h"

#define WINDOW_NAME L"KeyBoard"
#define GAME_NAME L"CastleVania"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define BACKGROUND_COLOR D3DCOLOR_XRGB(0,255,0)

#define MAX_FRAME_RATE 30

#define ID_TEX_SIMON_LEFT 0
#define ID_TEX_SIMON_RIGHT 100
#define ID_TEX_ROI_RIGHT 300
#define ID_TEX_ROI_LEFT 400
#define ID_TEX_FIRE_PILLAR 500

Game *game;
simon *Simon;
Weapon * weap;
firePillar * frPillar;

class CSampleKeyHander : public KeyEventHandler
{
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};

CSampleKeyHander * keyHandler;

void CSampleKeyHander::OnKeyDown(int KeyCode)
{
	switch (KeyCode)
	{
	case DIK_SPACE:
		Simon->SetState(SIMON_STATE_JUMP);
		break;
	}
}

void CSampleKeyHander::OnKeyUp(int KeyCode)
{
}

void CSampleKeyHander::KeyState(BYTE *states)
{
	if (game->IsKeyDown(DIK_RIGHT))
		Simon->SetState(SIMON_STATE_WALKING_RIGHT);
	else if (game->IsKeyDown(DIK_LEFT))
		Simon->SetState(SIMON_STATE_WALKING_LEFT);
	else if (game->IsKeyDown(DIK_F))
	{
		Simon->SetState(SIMON_STATE_ATTACK);
		weap->SetState(WEAPON_STATE_FIGHT, Simon);
	}
	else
	{
		Simon->SetState(SIMON_STATE_IDLE);
		weap->SetState(WEAPON_STATE_IDLE,Simon);
	}
	
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

void LoadResources()
{
	Textures * textures = Textures::GetInstance();
	textures->Add(ID_TEX_SIMON_LEFT, L"textures\\simonLEFT.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_SIMON_RIGHT, L"textures\\simonRIGHT.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_ROI_RIGHT, L"textures\\roiRight.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_FIRE_PILLAR, L"textures\\firePillar.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_ROI_LEFT, L"textures\\roiLeft.png", D3DCOLOR_XRGB(176, 224, 248));

	Sprites * sprites = Sprites::GetInstance();
	Animations * animations = Animations::GetInstance();

	LPDIRECT3DTEXTURE9 texSimonRight = textures->Get(ID_TEX_SIMON_RIGHT);

	sprites->Add(10001, 240, 0, 300, 66, texSimonRight,0,0);
	sprites->Add(10002, 300, 0, 360, 66, texSimonRight,0,0);
	sprites->Add(10003, 360, 0, 420, 66, texSimonRight,0,0);
	sprites->Add(10004, 420, 0, 480, 66, texSimonRight,0,0);

	//attack right
	sprites->Add(10020, 0, 0, 60, 66, texSimonRight,0,0);
	sprites->Add(10021, 60, 0, 120, 66, texSimonRight,0,0);
	sprites->Add(10022, 120, 0, 180, 66, texSimonRight,0,0);



	LPDIRECT3DTEXTURE9 texSimonLeft = textures->Get(ID_TEX_SIMON_LEFT);

	sprites->Add(10011, 0, 0, 60, 66, texSimonLeft,0,0);
	sprites->Add(10012, 60, 0, 120, 66, texSimonLeft,0,0);
	sprites->Add(10013, 120, 0, 180, 66, texSimonLeft,0,0);
	sprites->Add(10014, 180, 0, 240, 66, texSimonLeft,0,0);

	//attack left
	sprites->Add(10024, 300, 0, 360, 66, texSimonLeft,0,0);
	sprites->Add(10025, 360, 0, 420, 66, texSimonLeft,0,0);
	sprites->Add(10026, 420, 0, 480, 66, texSimonLeft,0,0);

	LPDIRECT3DTEXTURE9 texSimonROIright = textures->Get(ID_TEX_ROI_RIGHT);
	sprites->Add(30011,487 , 19, 505, 66, texSimonROIright, -10,18);
	sprites->Add(30012, 328, 15, 360, 51, texSimonROIright, 0,4);
	sprites->Add(30013, 231, 19, 289, 34, texSimonROIright, 56,20);

	LPDIRECT3DTEXTURE9 texSimonROIleft = textures->Get(ID_TEX_ROI_LEFT);
	sprites->Add(30021, 135, 20, 152, 67, texSimonROIleft, 52, 16);
	sprites->Add(30022, 280, 14, 313, 51, texSimonROIleft, 28, 8);
	sprites->Add(30023, 352, 15, 407, 32, texSimonROIleft, -50, 15);

	LPDIRECT3DTEXTURE9 texFirePillar = textures->Get(ID_TEX_FIRE_PILLAR);
	sprites->Add(40011, 0, 0, 32, 64, texFirePillar, 0, 0);
	sprites->Add(40012, 32, 0, 64, 64, texFirePillar, 0, 0);

	LPANIMATION ani;
	ani = new Animation(100);
	ani->Add(10004);
	animations->Add(400, ani);

	ani = new Animation(100);
	ani->Add(10011);
	animations->Add(401, ani);

	ani = new Animation(100);
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	ani->Add(10004);
	animations->Add(500, ani);

	ani = new Animation(101);
	ani->Add(10011);
	ani->Add(10012);
	ani->Add(10013);
	ani->Add(10014);
	animations->Add(501, ani);

	ani = new Animation(100);
	ani->Add(10020);
	ani->Add(10021);
	ani->Add(10022);
	animations->Add(502, ani);

	ani = new Animation(100);
	ani->Add(10022);
	ani->Add(10021);
	ani->Add(10020);
	animations->Add(503, ani);

	ani = new Animation(100);
	ani->Add(10024);
	ani->Add(10025);
	ani->Add(10026);
	animations->Add(504, ani);

	ani = new Animation(100);
	ani->Add(30011);
	ani->Add(30012);
	ani->Add(30013);
	animations->Add(600, ani);

	ani = new Animation(100);
	ani->Add(40011);
	ani->Add(40012);
	animations->Add(800, ani);

	ani = new Animation(100);
	ani->Add(30021);
	ani->Add(30022);
	ani->Add(30023);
	animations->Add(900, ani);

	Simon = new simon();
	simon::AddAnimation(400);		// idle right
	simon::AddAnimation(401);		// idle left
	simon::AddAnimation(500);		// walk right
	simon::AddAnimation(501);		// walk left
	simon::AddAnimation(503);		// attack right
	simon::AddAnimation(504);		// attack left


	Simon->SetPosition(10.0f, 100.0f);

	
	weap = new Weapon();
	Weapon::AddAnimation(600);
	Weapon::AddAnimation(900);

	frPillar = new firePillar();
	firePillar::AddAnimation(800);

	frPillar->SetPosition(200.0f, 100.0f);

}

void Update(DWORD dt)
{
	Simon->Update(dt);
	weap->Update(dt,Simon);
	frPillar->Update(dt);
}

void Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);


		Simon->Render();
		weap->Render(Simon);
		frPillar->Render();

		spriteHandler->End();
		d3ddv->EndScene();
	}

	d3ddv->Present(NULL, NULL, NULL, NULL);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_NAME,
			GAME_NAME,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd)
	{
		MessageBox(NULL, L"Khong khoi tao duoc", L"Caption of STDIO.VN", MB_OK);
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

int Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			game->ProcessKeyboard();
			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);
	}

	return 1;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	game = Game::GetInstance();
	game->Init(hWnd);

	keyHandler = new CSampleKeyHander();
	game->InitKeyboard(keyHandler);

	LoadResources();
	Run();

	return 0;
}

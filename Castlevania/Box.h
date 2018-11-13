#pragma once
#include <Windows.h>
class Box
{
	float x;
	float y;
	
	float width;
	float height;

	float vx;
	float vy;
public:
	Box(float x,float y,int Width,int Height);
	void isColliding(const Box &other)
	{
		float left = other.x - (x + width);
		float top = (other.y + other.height) - y;
		float right = (other.x + other.width) - x;
		float bottom = other.y - (y + height);

		// mình xét ng??c l?i cho nhanh h?n
		bool i = !(left > 0 || right < 0 || top < 0 || bottom > 0);

		if (i == true)
		{
			MessageBox(NULL, L"Text of stdio.vn", L"Caption of STDIO.VN", MB_OK);
		}
	}

	void UpdateBox(float xS, float yS) { this->x = xS, this->y = yS; }

	~Box();
};


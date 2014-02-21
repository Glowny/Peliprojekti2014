#include "Enemy.h"



Enemy::~Enemy(void)
{
}

Enemy::Enemy(void)
{
	posX = 0;
	posY = 0;
	goChar = 'e';
}



Enemy::Enemy(int x, int y)
{
	posX = x;
	posY = y;
	goChar = 'e';
}

Enemy::Enemy(int x, int y, char C)
{
	posX = x;
	posY = y;
	goChar = C;
}
Enemy::Enemy(const Enemy &gameobject)
{
	posX = gameobject.posX;
	posY = gameobject.posY;
	goChar = gameobject.goChar;

}
int Enemy::Follow(int folX, int folY)
{
	if (posX < folX)			// x++
	{
		if(posY < folY)			// y++
		{
			return 3;
		}

		else if(posY > folY)			// y--
		{
			return 9;
		}

		else if(posY == folY)		//y ei minnekkää
		{
			return 6;
		}
	}

	else if (posX > folX)			//x--
	{
		if(posY < folY)
		{
			return 1;
		}

		else if(posY > folY)
		{
			return 7;
		}

		else if(posY == folY)
		{
			return 4;
		}
	}

	else if (posX == folX)			//x ei minnekkää
	{
		
		if(posY < folY)
		{
			return 2;
		}

		else if(posY > folY)
		{
			return 8;
		}

		else if(posY == folY)
		{
			return 5;
		}
	}
}
// MUISTA ELSEKSI MUUTTAA MUUTEN LIIKUTAAN YLIMÄÄRÄSIÄ

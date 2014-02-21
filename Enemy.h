#pragma once
#include "GameObject.h"
class Enemy:public GameObject
{
public:
	Enemy(void);
	~Enemy(void);
	Enemy(int x, int y);
	Enemy(int x, int y, char C);
	Enemy(const Enemy &gameobject);
	int Follow(int folX, int folY);
};


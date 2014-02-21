#pragma once
#include "GameObject.h"
class Player:public GameObject
{
public:
	Player(void);
	~Player(void);
	Player(int x, int y);
	Player(const Player &gameobject);
	Player(int x, int y, char C);
};


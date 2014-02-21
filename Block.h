#pragma once
#include "GameObject.h"
class Block: public GameObject
{
public:
	Block(void);
	Block(int x, int y);
	Block(int x, int y, char C);
	Block(const Block &gameobject);
	~Block(void);
};


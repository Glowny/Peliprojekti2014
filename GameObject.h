#pragma once
#include <string.h>
#include <iostream>
using namespace std;
class GameObject
{
public:
	GameObject(void);
	GameObject(int x, int y);
	GameObject(int x, int y, char C);
	GameObject(const GameObject &gameobject);
	virtual ~GameObject(void);

	void Movement(int xDir, int yDir);		// 1 = +. 0 = - 2 = (void).
	int nextX(int x);
	int nextY(int y);
	char getChar();

	int getX();
	int getY();

protected:
	int posX, posY;
	char goChar;
};


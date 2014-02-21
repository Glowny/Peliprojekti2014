#include "GameObject.h"


GameObject::GameObject(void)
{
	posX = 0;
	posY = 0;
	goChar = '£';
}

GameObject::GameObject(int x, int y)
{
	posX = x;
	posY = y;
	goChar = '£';
}

GameObject::GameObject(int x, int y, char C)
{
	posX = x;
	posY = y;
	goChar = C;
}
GameObject::GameObject(const GameObject &gameobject)
{
	posX = gameobject.posX;
	posY = gameobject.posY;
	goChar = gameobject.goChar;

}

GameObject::~GameObject(void)
{

}

int GameObject::getX()
{
	return posX;
}

int GameObject::getY()
{
	return posY;
}

char GameObject::getChar()
{
	return goChar;
}

int GameObject::nextX(int x)
{
	int tempX = posX;

	if ( x == 9)
		{
			tempX++;
			return tempX;
		}
	if ( x == 6)
		{
			tempX++;
			return tempX;
		}
	if ( x == 3)
		{
			tempX++;
			return tempX;
		}
	if ( x == 1)
		{

			tempX--;
			return tempX;
		}
	if ( x == 4)
		{

			tempX--;
			return tempX;
		}
	if ( x == 7)
		{

			tempX--;
			return tempX;
		}
	else
		{
			return posX;
		}
}

int GameObject::nextY(int y)
{
	int tempY = posY;

	if ( y == 7)
		{
			tempY--;
			return tempY;
		}
	if ( y == 8)
		{
			tempY--;
			return tempY;
		}
	if ( y == 9)
		{
			tempY--;
			return tempY;
		}
	if ( y == 1)
		{
			tempY++;
			return tempY;
		}
	if ( y == 2)
		{
			tempY++;
			return tempY;
		}
	if ( y == 3)
		{
			tempY++;
			return tempY;
		}
	else
		{
			return posY;
		}
}
void GameObject::Movement(int xDir, int yDir)		//antamalla oikean yhdistelmän voi liikkua minne haluaa
{
	posX = xDir;
	posY = yDir;
}

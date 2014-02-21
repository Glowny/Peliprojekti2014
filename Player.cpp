#include "Player.h"



Player::~Player(void)
{
}

Player::Player(void)
{
	posX = 0;
	posY = 0;
	goChar = 'a';
}

Player::Player(int x, int y)
{
	posX = x;
	posY = y;
	goChar = 'a';
}

Player::Player(int x, int y, char C)
{
	posX = x;
	posY = y;
	goChar = C;
}
Player::Player(const Player &gameobject)
{
	posX = gameobject.posX;
	posY = gameobject.posY;
	goChar = gameobject.goChar;

}
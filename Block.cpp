#include "Block.h"


Block::Block(void)
{
	posX = 0;
	posY = 0;
	goChar = 'b';
}

Block::Block(int x, int y)
{
	posX = x;
	posY = y;
	goChar = 'b';
}

Block::Block(int x, int y, char C)
{
	posX = x;
	posY = y;
	goChar = C;
}

Block::~Block(void)
{
}

Block::Block(const Block &gameobject)
{
	posX = gameobject.posX;
	posY = gameobject.posY;
	goChar = gameobject.goChar;

}
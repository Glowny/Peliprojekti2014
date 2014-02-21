#include "vihu.h"

vihu::vihu(float x,float y, int vA)
{
	vihuX= x;
	vihuY= y;
	vihuAika = vA;
}

float vihu::giveX()
{
	return vihuX;
}

float vihu::giveY()
{
	return vihuY;
}

void vihu::setX(float xs)
{
	vihuX = xs;
}
void vihu::setY(float xs)
{
	vihuY = xs;
}
void vihu::movement(float followX, float followY, int peliAika)
{
// vanhaa koodia, followX seurattava, vihuX = vihuX, vihuY = vihuY. 


	if (peliAika == vihuAika)
		{
			
			if(vihuX<followX) //moro heron vasemmalla, 
			{
				vihuX=vihuX+50;
				if(vihuY<followY)
				{
					vihuY=vihuY+50;
					
				}
				if(vihuY>followY)
				{
					vihuY=vihuY-50;
				}
				vihuAika = peliAika+200;
			}
			else if(vihuX>followX) //moro heron oikealla, 
			{

				vihuX=vihuX-50;
				if(vihuY<followY)
				{	
					vihuY=vihuY+50;
				}

				if(vihuY>followY)
				{
					vihuY=vihuY-50;
				}
				vihuAika = peliAika+200;
			}
			else if(vihuX==followX)
			{
				if(vihuY<followY)
				{	
					vihuY=vihuY+50;
				}

				if(vihuY>followY)
				{
					vihuY=vihuY-50;
				}
				vihuAika = peliAika+200;
			}
		}
	
}

vihu::~vihu(void)
{
}


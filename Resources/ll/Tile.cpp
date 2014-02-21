#include "Tile.h"
#include "vihu.h"


RenderWindow TileWindow;
Event TileEvent;
float HEROX = 0;
float HEROY = 0;
//float MOROX = 800, MOROY = 400;

float blockX=100, blockY=200;
int textureIndex=0;
map<string, Sprite> SpriteLib;
vector<Texture> TextureLib(10);
Input liiku;
vector<vihu*> vihut;

void TilePeli()
{
	TileWindow.create(VideoMode(1024, 576), "TilePeli");
	Initialize();
	
	int aika = 0;

	int moroaika = 0;
	
	
	vihut.push_back(new vihu(500,200, aika));
	vihut.push_back(new vihu(200,300, aika));
	vihut.push_back(new vihu(700,200, aika));
	vihut.push_back(new vihu(100,500, aika));

	while (TileWindow.isOpen())
	{
		while(TileWindow.pollEvent(TileEvent))
		
		{
			if (TileEvent.type == Event::Closed)
				TileWindow.close();
		}
	
		
		
		if (liiku.Press_Key(sf::Keyboard::Numpad6)&&HEROX<901)
				{
					HEROX = HEROX + 50;
					aika=aika+100;
				}
		if (liiku.Press_Key(sf::Keyboard::Numpad4)&&HEROX>0)
				{
					HEROX = HEROX - 50;
					aika=aika+100;
				}
		if (liiku.Press_Key(sf::Keyboard::Numpad2)&&HEROY<500)
				{
				HEROY = HEROY + 50;
				aika=aika+100;
				}
		if (liiku.Press_Key(sf::Keyboard::Numpad8)&&HEROY>0)
				{
				HEROY = HEROY - 50;
				aika=aika+100;
				}
		if (liiku.Press_Key(sf::Keyboard::Numpad7)&&HEROY>0&&HEROX>0)
		{
			HEROX = HEROX - 50;
			HEROY = HEROY - 50;
			aika=aika+100;
		}

		if (liiku.Press_Key(sf::Keyboard::Numpad9)&&HEROY>0&&HEROX<901)
		{
			HEROX = HEROX + 50;
			HEROY = HEROY - 50;
			aika=aika+100;
		}

		if (liiku.Press_Key(sf::Keyboard::Numpad1)&&HEROY<500&&HEROX>0)
		{
			HEROX = HEROX - 50;
			HEROY = HEROY + 50;
			aika=aika+100;
		}

		if (liiku.Press_Key(sf::Keyboard::Numpad3)&&HEROY<500&&HEROX<901)
		{
			HEROX = HEROX + 50;
			HEROY = HEROY + 50;
			aika=aika+100;
		}
		if (liiku.Press_Key(sf::Keyboard::Numpad5))
		{
			aika=aika+100;
		}

		
		if(liiku.Press_Key(sf::Keyboard::S))
		{
		
		vihut.push_back(new vihu(HEROX+300,HEROY, aika));
		cout<<"Vihu spawnattu koordinaatteihin"<<HEROX+300 <<HEROY<<endl;
		}


		for(int i = 0; i<vihut.size();i++)
		{
		float oldStateX=vihut[i]->giveX(),	oldStateY=vihut[i]->giveY();


	//blockkikoodi
		 
		vihut[i]->movement(HEROX,HEROY,aika);  // laita seuraamaan heroa !
		if (vihut[i]->giveX() == blockX && vihut[i]->giveY() == blockY)
			{
				vihut[i]->setX(oldStateX);
				vihut[i]->setX(oldStateY);
			}

		for (int o = 0; o<vihut.size(); o++)
			{
				if(vihut[i] != vihut[o])
				{
				if(vihut[o]->giveX() == vihut[i]->giveX() && vihut[o]->giveY() == vihut[i]->giveY())
					{
					/*	vihut[i]->setX(oldStateX);
						vihut[i]->setY(oldStateY);*/ // tähä


						if(HEROX > vihut[i]->giveX() && HEROY > vihut[i]->giveY())
						{
							if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX && vihut[o]->giveY() != oldStateY)
								{
									vihut[i]->setX(oldStateX);
									vihut[i]->setY(oldStateY);
								}
							

						}

						else if(HEROX > vihut[i]->giveX() && HEROY == vihut[i]->giveY())
						{
							if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+0);
								}

						}

						else if(HEROX > vihut[i]->giveX() && HEROY < vihut[i]->giveY())
						{
							if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+0);
								}
							//ASD
						}

						else if(HEROX > vihut[i]->giveX() && HEROY > vihut[i]->giveY())
						{
								if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+0);
								}
							
						}

						else if(HEROX < vihut[i]->giveX() && HEROY < vihut[i]->giveY())
						{
							if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX()+0 != oldStateX && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+0);
								}
							//ASD
						}

						else if(HEROX < vihut[i]->giveX() && HEROY == vihut[i]->giveY())
						{
							if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+0);
								}
							
						}

						else if(HEROX < vihut[i]->giveX() && HEROY > vihut[i]->giveY())
						{
							if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+0);
								}
								
						}

						else if(HEROX == vihut[i]->giveX() && HEROY > vihut[i]->giveY())
						{
							if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY+0);
								}
							else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX-50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+50);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()-50 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY-50);
								}
							else if(vihut[o]->giveX() != oldStateX+0 && vihut[o]->giveY()+0 != oldStateY)
								{
									vihut[i]->setX(oldStateX+0);
									vihut[i]->setY(oldStateY+0);
								}
								//asd
						}
						else
				{
					vihut[i]->setX(oldStateX);
					vihut[i]->setY(oldStateY);
				}	
						 /// WNAHA

						/*if(vihut[o]->giveX() != oldStateX+50 && vihut[o]->giveY() != oldStateY)
						{
						vihut[i]->setX(oldStateX+50);
						vihut[i]->setY(oldStateY);
						}
						else if(vihut[o]->giveX() != oldStateX-50 && vihut[o]->giveY() != oldStateY)
						{
						vihut[i]->setX(oldStateX-50);
						vihut[i]->setY(oldStateY);
						
						}
						else if(vihut[o]->giveX() != oldStateX && vihut[o]->giveY() != oldStateY+50)
						{
						vihut[i]->setX(oldStateX);
						vihut[i]->setY(oldStateY+50);
						
						}
						else if(vihut[o]->giveX() != oldStateX && vihut[o]->giveY() != oldStateY-50)
						{
						vihut[i]->setX(oldStateX);
						vihut[i]->setY(oldStateY-50);
						
						}
						else
						{
						vihut[i]->setX(oldStateX);
						vihut[i]->setY(oldStateY);
						}*/

					}

			}
			/*stuff[i]->changeXY(vihut[i]->giveX(), vihut[i]->giveY());
			*/
			}
		}
		//if (aika == moroaika)
		//{
		//	
		//	if(MOROX<HEROX)  //moro heron vasemmalla, 
		//	{
		//		MOROX=MOROX+50;
		//		if(MOROY<HEROY)
		//		{
		//			MOROY=MOROY+50;
		//			
		//		}
		//		if(MOROY>HEROY)
		//		{
		//			MOROY=MOROY-50;
		//		}
		//		moroaika = aika+200;
		//	}
		//	else if(MOROX>HEROX) //moro heron oikealla, 
		//	{

		//		MOROX=MOROX-50;
		//		if(MOROY<HEROY)
		//		{	
		//			MOROY=MOROY+50;
		//		}

		//		if(MOROY>HEROY)
		//		{
		//			MOROY=MOROY-50;
		//		}
		//		moroaika = aika+200;
		//	}
		//	else if(MOROX==HEROX)
		//	{
		//		if(MOROY<HEROY)
		//		{	
		//			MOROY=MOROY+50;
		//		}

		//		if(MOROY>HEROY)
		//		{
		//			MOROY=MOROY-50;
		//		}
		//		moroaika = aika+200;
		//	}
		//}
	


		TileWindow.clear(Color::Transparent);
		float KARTTAX=0, KARTTAY=0;

		while(KARTTAY < 550) //900
	   {
		 while(KARTTAX < 1000)//1100
			 {
				SpriteLib["testi"].setPosition(KARTTAX,KARTTAY);
				TileWindow.draw(SpriteLib["testi"]);
				KARTTAX = KARTTAX + 50;
			 }
	   KARTTAX = 0;
	   KARTTAY = KARTTAY + 50;
	   }

		SpriteLib["hero"].setPosition(HEROX,HEROY);
		SpriteLib["hero"].setScale(Vector2f(0.125f, 0.125f));
		TileWindow.draw(SpriteLib["hero"]);

		SpriteLib["block"].setPosition(blockX,blockY);
		SpriteLib["block"].setScale(Vector2f(0.125f, 0.125f));
		TileWindow.draw(SpriteLib["block"]);

		SpriteLib["moro"].setScale(Vector2f(0.125,0.125f));
		for(int i = 0; i<vihut.size();i++)
		{SpriteLib["moro"].setPosition(vihut[i]->giveX(),vihut[i]->giveY());
		TileWindow.draw(SpriteLib["moro"]);
		}

		TileWindow.display();
	}



}

















// piirtosysteemi

void CreateSprite(string name, string path)
{
	Texture texture;
	Sprite sprite;
	cout<<textureIndex<<": "<<path<<" "; // Testausta

	texture.loadFromFile(path);
	TextureLib[textureIndex] = texture;
	sprite.setTexture(TextureLib[textureIndex]);
	textureIndex++;
	SpriteLib.insert(make_pair(name,sprite));
}


// Alustaa game assetit.
void Initialize()
{
	CreateSprite("testi","Resources/ruutu.png");
	CreateSprite("hero","Resources/hero.png");
	CreateSprite("moro", "Resources/moro.png");
	CreateSprite("block", "Resources/block.png");
	cout<<"Sprites: " <<SpriteLib.size();
	cout<<" Textures: " <<TextureLib.size();
	cout<<" TextureIndex: "<<textureIndex;
}
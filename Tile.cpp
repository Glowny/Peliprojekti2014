#include "Tile.h"
#include "PlayScene.h"
#include "Enemy.h"
RenderWindow TileWindow;
Event TileEvent;

//float MOROX = 800, MOROY = 400;

float blockX=100, blockY=200;
int textureIndex=0;
map<string, Sprite> SpriteLib;
vector<Texture> TextureLib(10);
Input playerInput;
PlayScene playScene(20,20);

void TilePeli()
{
	TileWindow.create(VideoMode(1920, 1080), "TilePeli");
	Initialize();
	
	
	


	while (TileWindow.isOpen())
	{
		while(TileWindow.pollEvent(TileEvent))
		
		{
			if (TileEvent.type == Event::Closed)
				TileWindow.close();
		}
	
		
		
		if (playerInput.Press_Key(sf::Keyboard::Numpad6))
				{
					playScene.Play(6);
				}

		if (playerInput.Press_Key(sf::Keyboard::Numpad4))
				{
					playScene.Play(4);
				}

		if (playerInput.Press_Key(sf::Keyboard::Numpad2))
				{
					playScene.Play(2);
				}

		if (playerInput.Press_Key(sf::Keyboard::Numpad8))
				{
					playScene.Play(8);
				}

		if (playerInput.Press_Key(sf::Keyboard::Numpad7))
				{
					playScene.Play(7);
				}

		if (playerInput.Press_Key(sf::Keyboard::Numpad9))
				{
					playScene.Play(9);
				}

		if (playerInput.Press_Key(sf::Keyboard::Numpad1))
				{
					playScene.Play(1);
				}

		if (playerInput.Press_Key(sf::Keyboard::Numpad3))
				{
					playScene.Play(3);
				}

		if (playerInput.Press_Key(sf::Keyboard::Numpad5))
				{
					playScene.Play(5);
				}

		if(playerInput.Press_Key(sf::Keyboard::S))
				{
					playScene.Play(5);
				}

		TileWindow.clear(Color::Transparent);
		float KARTTAX=0, KARTTAY=0;

		while(KARTTAY < 1080) 
	   {
		 while(KARTTAX < 1920)
			 {
				SpriteLib["testi"].setPosition(KARTTAX,KARTTAY);
				TileWindow.draw(SpriteLib["testi"]);
				KARTTAX = KARTTAX + 50;
			 }
	   KARTTAX = 0;
	   KARTTAY = KARTTAY + 50;
	   }
	
		vector<GameObject> allObjects = playScene.GetObjectVector();
		for (int i = 0; i<allObjects.size(); i++)
			{
				if(allObjects[i].getChar() =='a')					//Player = 'a', Enemy = 'e', Block = 'b', default = "C"
				{
					SpriteLib["hero"].setPosition(allObjects[i].getX()*50,allObjects[i].getY()*50);
					SpriteLib["hero"].setScale(Vector2f(0.125f, 0.125f));
					TileWindow.draw(SpriteLib["hero"]);
				}

				else if (allObjects[i].getChar() == 'e')
				{
					SpriteLib["moro"].setPosition(allObjects[i].getX()*50,allObjects[i].getY()*50);
					SpriteLib["moro"].setScale(Vector2f(0.125,0.125f));
					TileWindow.draw(SpriteLib["moro"]);
				}

				else if (allObjects[i].getChar() == 'b')
				{
					SpriteLib["block"].setPosition(allObjects[i].getX()*50,allObjects[i].getY()*50);
					SpriteLib["block"].setScale(Vector2f(0.125f, 0.125f));
					TileWindow.draw(SpriteLib["block"]);
				}
				else
				{
					SpriteLib["hero"].setPosition(allObjects[i].getX()*50,allObjects[i].getY()*50);		// PISTÄ TÄHÄN JOKU TEKSTUURI
					SpriteLib["hero"].setScale(Vector2f(0.125f, 0.125f));
					TileWindow.draw(SpriteLib["hero"]);
				}
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
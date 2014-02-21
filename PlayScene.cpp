#include "PlayScene.h"
#include <iostream>


PlayScene::PlayScene(int width, int height)
{
	Player Player1(2,2);
	Enemy Enemy1(1,2);
	Enemy Enemy2(3,2);
	Enemy Enemy3(4,2);
	Enemy Enemy4(5,2);
	Enemy Enemy5(10,10);
	GameObject kaksi1(3,3);
	
	playerVector.push_back(Player1);
	objectVector.push_back(Enemy1);
	objectVector.push_back(Enemy2);
	objectVector.push_back(Enemy3);
	objectVector.push_back(Enemy4);
	objectVector.push_back(Enemy5);
	objectVector.push_back(kaksi1);
	objectVector.push_back(Player1);
	enemyVector.push_back(Enemy1);
	enemyVector.push_back(Enemy2);
	enemyVector.push_back(Enemy3);
	enemyVector.push_back(Enemy4);
	enemyVector.push_back(Enemy5);

	int numero = 0;

	bool goNext = CheckCollision(playerVector[0], numero);
	if (goNext == 1)
	{
		GameObject d;
		d = FindCollision(playerVector[0],numero);
		cout<<"Object in way!: "<<d.getChar()<<" on COORDS: "<<d.getX()<<", "<<d.getY()<< endl;
	}
	else
	{
		objectVector[6].Movement(playerVector[0].nextX(numero), playerVector[0].nextY(numero));
		playerVector[0].Movement(playerVector[0].nextX(numero), playerVector[0].nextY(numero));
		cout << "P COORDS: " << playerVector[0].getX()<<", "<<playerVector[0].getY() << endl;

	}
	std::cin.clear();
	
}
void PlayScene::Play(int n)
{
	int numero =n ;
	bool goNext = CheckCollision(objectVector[6], numero);
	if (goNext == 1)
	{
		GameObject d;
		d= FindCollision(objectVector[6],numero);
		cout<<"Object in way!: "<<d.getChar()<<" on COORDS: "<<d.getX()<<", "<<d.getY()<< endl;
	}
	else
	{
		playerVector[0].Movement(playerVector[0].nextX(numero), playerVector[0].nextY(numero));
		objectVector[6].Movement(objectVector[6].nextX(numero), objectVector[6].nextY(numero));
		cout << "P COORDS: " << objectVector[6].getX()<<", "<<objectVector[6].getY() << endl;

	}
	EnemyActions();
	std::cin.clear();
}


PlayScene::~PlayScene(void)
{
}
bool PlayScene::CheckCollision(GameObject c, int moveDir)
{
	int nX = c.nextX(moveDir);
	int nY = c.nextY(moveDir);
	cout << nY <<endl;
	for (int i=0; i<objectVector.size();i++)
	{
		if(objectVector[i].getX() == nX && objectVector[i].getY() == nY)
		{
			cout << nX << ", " << nY<<endl;
			return 1;		
		}
	}
	return 0;
}
GameObject PlayScene::FindCollision(GameObject c, int moveDir)
{
	int nX = c.nextX(moveDir);
	int nY = c.nextY(moveDir);
	for (int i=0; i< objectVector.size();i++)
	{
		if(objectVector[i].getX() == nX && objectVector[i].getY() == nY)
		{
			return objectVector[i];		
		}
	}
	return objectVector[0];
}

void PlayScene::EnemyActions()
{
	for (int i = 0; i < enemyVector.size(); i++)
	{
		int FollowDir = enemyVector[i].Follow(playerVector[0].getX(), playerVector[0].getY());
		bool goNext = CheckCollision(objectVector[i],FollowDir);
			while (goNext == 1)
			{
				GameObject d;
				d = FindCollision(objectVector[i],FollowDir);
				//Tee seurausysteemi niin ettei törmäile
				
			}
			
			
				enemyVector[i].Movement(enemyVector[i].nextX(FollowDir), enemyVector[i].nextY(FollowDir)); 
				objectVector[i].Movement(objectVector[i].nextX(FollowDir), objectVector[i].nextY(FollowDir)); 
			
	}

}

vector<Enemy> PlayScene::GetEnemyVector()
{
	return enemyVector;
}

vector<Player> PlayScene::GetPlayer()
{
	return playerVector;
}

vector<GameObject> PlayScene::GetObjectVector()
{
	return objectVector;
}
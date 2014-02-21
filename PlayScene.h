#pragma once
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include <vector>
class PlayScene
{
public:
	PlayScene(int width, int height);		//playskenessä tapahtuu liikkumiset, kohtaamiset.
	~PlayScene(void);
	void Play(int n);
	bool CheckCollision(GameObject c, int moveDir);
	GameObject FindCollision(GameObject c, int moveDir);
	void EnemyActions();
	vector<Enemy> GetEnemyVector();
	vector<Player> GetPlayer();
	vector<GameObject> GetObjectVector();

private:
	vector<GameObject> objectVector;
	vector<Enemy> enemyVector;
	vector<Player> playerVector;
};


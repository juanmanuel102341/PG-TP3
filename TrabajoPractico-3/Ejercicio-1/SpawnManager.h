#ifndef SPAWN_h
#define SPAWN_H
#include"Entity.h"
#include"Enemy.h"
#include<time.h>
#include<stdlib.h>
#include<list>
#include<vector>
#include"Reg.h"
class SpawnManager
{
public:
	SpawnManager();
	~SpawnManager();
	void Update();
	void Create();
	void Draw();
	const int totalEnemys = 10;
	
private:
	//std::list<Entity*>listEnemy;
	Entity*aEnemys[10];
	std::list<Entity*>listEnemyActive;
	Entity*GetEnemy();
	void OutOfBounds();
	float timer;
	int random;
};
#endif // !SPAWN_h


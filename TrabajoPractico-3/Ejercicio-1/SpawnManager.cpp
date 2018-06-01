#include"SpawnManager.h"
void SpawnManager::Update(){


	timer += 1;
	for (std::list<Entity*>::iterator it = listEnemyActive.begin(); it != listEnemyActive.end(); ++it) {
		Entity*e = *it;
		e->Move();
		
	}

if (timer > random) {
	
	random = rand() % 100+100;
	listEnemyActive.push_back( GetEnemy());
	timer = 0;
	cout << "random spawn " << random << endl;
}
OutOfBounds();
}
void SpawnManager::OutOfBounds(){
	for (std::list<Entity*>::iterator it = listEnemyActive.begin(); it != listEnemyActive.end(); ++it) {
		Entity*e = *it;
		if (e->posx + e->width< 0) {
			e->dead = true;
			e->posx = -100;
			listEnemyActive.erase(it);
			cout << "fuera enemy";
			break;
		}
	}
}
void SpawnManager::Draw(){
	for (std::list<Entity*>::iterator it = listEnemyActive.begin(); it != listEnemyActive.end(); ++it) {
		Entity*e=*it;
		e->Draw();
	
	}
}
void SpawnManager::Create(){
	for (int i = 0; i < totalEnemys; i++) {
		Entity* enemy = new Enemy();
		enemy->posx = -100;
		enemy->posy = -100;
		aEnemys[i] = enemy;
	}
	int n = SCREEN_H - aEnemys[0]->height - 100;
	 aEnemys[0]->posy=n;
	 aEnemys[0]->posx = SCREEN_W;
	
}
Entity* SpawnManager::GetEnemy () {
//	listEnemy
	for (int i = 0; i < totalEnemys;i++) {
		Entity*e = aEnemys[i];
		
		if (e->dead) {
			int n = SCREEN_H - e->height-100;
			float y = rand() % n+e->height;
			e->posy = y;
			e->posx = SCREEN_W;
			e->dead = false;
			cout << "posy " << e->posy;
			return e;
		}
		
	}
	return NULL;
}
SpawnManager::SpawnManager() {
	srand(time(NULL));
	random =  rand() % 50+150;
	timer = random;
	Create();
}
SpawnManager::~SpawnManager(){
	
}
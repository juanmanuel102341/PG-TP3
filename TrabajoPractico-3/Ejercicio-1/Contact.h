#ifndef CONTACT_H
#define CONTACT_H
#include"SpawnManager.h"
#include"Hero.h"
#include"Enemy.h"

class Contact
{
public:
	Contact(Entity*hero,SpawnManager*_spawnManger);
	~Contact();
	void Between();
	void BulletHeroeEnemy();
private:
	Entity* hero;
	SpawnManager*spawn;
};
#endif // !CONTACT_H

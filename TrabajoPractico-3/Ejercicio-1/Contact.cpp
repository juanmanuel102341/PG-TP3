#include"Contact.h"


void Contact::Between(){
	for (std::list<Entity*>::iterator it = spawn->listEnemyActive.begin(); it != spawn->listEnemyActive.end(); ++it) {
		Entity*enemy = *it;

		if (hero->posx + hero->width > enemy->posx&&hero->posx<enemy->posx + enemy->width
			&&hero->posy + hero->height>enemy->posy&&hero->posy < enemy->posy + enemy->height) {
			cout << "colision" << endl;
			enemy->posx = -100;
			enemy->posy = -100;
			enemy->dead = true;
			spawn->listEnemyActive.erase(it);
			hero->posx = -100;
			hero->posy = -100;
			hero->dead = true;
			hero->lifes--;
			hero->gui->UpdateLife(hero->lifes);
			cout << "chau heroe " << hero->lifes << endl;
			return;
		}
	}
	
}
void Contact::BulletHeroeEnemy(){
	
	for (std::list<Entity*>::iterator it = spawn->listEnemyActive.begin(); it != spawn->listEnemyActive.end(); ++it) {
		Entity*enemy = *it;
		for (std::list< Entity::Bullet*>::iterator it2 = hero->listBullets.begin(); it2 != hero->listBullets.end(); ++it2) {
			Entity::Bullet* bullet = *it2;
			if (bullet->posx + bullet->width > enemy->posx&&bullet->posx<enemy->posx + enemy->width
				&&bullet->posy + bullet->height>enemy->posy&&bullet->posy < enemy->posy + enemy->height) {
				bullet->posx = -100;
				bullet->posy = -100;
				bullet->active = false;
				hero->listBullets.erase(it2);
				enemy->posx = -100;
				enemy->posy = -100;
				enemy->dead = true;
				spawn->listEnemyActive.erase(it);
				cout << "colision bullet" << endl;
				
				return;
			
			}
		}
	}
}

Contact::Contact(Entity*_hero,SpawnManager*_spawn){
	hero = _hero;
	spawn = _spawn;
}
Contact::~Contact(){}
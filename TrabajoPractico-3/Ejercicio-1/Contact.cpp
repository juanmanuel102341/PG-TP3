#include"Contact.h"


bool Contact::Between(){
	if (hero->posx + hero->width > enemy->posx&&hero->posx<enemy->posx + enemy->width
	&&hero->posy + hero->height>enemy->posy&&hero->posy < enemy->posy + enemy->height) {
	cout << "colision" << endl;
	return true;
	}
	return false;
}
Contact::Contact(Entity*_hero,Entity*_enemy){
	hero = _hero;
	enemy = _enemy;
}
Contact::~Contact(){}
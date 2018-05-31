#include"Enemy.h"


void Enemy::Draw(){
	al_draw_bitmap(bouncer, posx, posy, 0);
}
void Enemy::Move(){}
bool Enemy::Init(){
	bouncer = al_load_bitmap("Assets/enemy.png");
	if (!bouncer) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		return false;
	}
	width = al_get_bitmap_width(bouncer);
	height = al_get_bitmap_height(bouncer);
	posx = SCREEN_H- width;
	posy = SCREEN_H / 2 - height / 2;
	return true;
}
void Enemy::Set(Reg*_reg) {
	reg = _reg;
}
Enemy::~Enemy() {
	al_destroy_bitmap(bouncer);
}

Enemy::Enemy(){
	if (!Init()) {
		cout << "enemigo no cargdo" << endl;
	}

}
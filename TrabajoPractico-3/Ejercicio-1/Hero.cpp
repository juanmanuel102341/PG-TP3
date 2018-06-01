#include"Hero.h"


void Hero::Draw(){
al_draw_bitmap(bouncer, posx, posy, 0);

}
void Hero::Move(){
	if (reg->key[KEY_UP] && posy >= 4.0) {
				posy -= velocity;
			}

			if (reg->key[KEY_DOWN] && posy<= SCREEN_H - height - 4.0) {
				posy += velocity;
			}

			if (reg->key[KEY_LEFT] && posx >= 4.0) {
				posx -= velocity;
			}

			if (reg->key[KEY_RIGHT] && posx <= SCREEN_W - width - 4.0) {
				
				posx+= velocity;
			}
			
			}
bool Hero::Init(){
	
	bouncer = al_load_bitmap("Assets/_h.png"); 
	if (!bouncer) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		return false;
	}
	width = al_get_bitmap_width(bouncer);
	height = al_get_bitmap_height(bouncer);
	posx = width;
	posy = SCREEN_H / 2 - height / 2;
	return true;

}
Hero::~Hero(){
	al_destroy_bitmap(bouncer);
}
void Hero::Set(Reg*_reg){ 
	reg = _reg;
}
Hero::Hero(){
	if (!Init()) {
		cout << "hero no cargado" << endl;
	}
	velocity = 4.0f;
	dead = false;
}
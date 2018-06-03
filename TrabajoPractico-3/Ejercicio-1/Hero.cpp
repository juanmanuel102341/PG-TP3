#include"Hero.h"


void Hero::Draw(){
al_draw_bitmap(bouncer, posx, posy, 0);
DrawBullets();
}
void Hero::DrawBullets() {
	for (std::list< Entity::Bullet*>::iterator it = listBullets.begin(); it != listBullets.end(); ++it) {
		Entity::Bullet* e = *it;
	//	cout << "posx draw " << e.posx<<endl;
		al_draw_bitmap(e->sprite, e->posx, e->posy, 0);
	}
}
void Hero::Update(double elpased) {
	Move();
	MoveBullets(elpased);
	OutSceneBullet();
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
void Hero::MoveBullets(double elapsed) {

	if (reg->key[KEY_SHOOT] == true&&elapsed>fireRate) {
		cout << "disparo" << reg->key[KEY_SHOOT] << endl;
		listBullets.push_back(GetBullet());
		elapsed = 0;
		reg->key[KEY_SHOOT] = false;
	}
	for (std::list< Entity::Bullet*>::iterator it = listBullets.begin(); it != listBullets.end(); ++it) {
		Entity::Bullet* e = *it;
		e->posx+= e->velocity;
	
		//cout << "moviendo bullet" << e.posx;
	}
}
void Hero::OutSceneBullet(){
	for (std::list< Entity::Bullet*>::iterator it = listBullets.begin(); it != listBullets.end(); ++it) {
		Entity::Bullet* e = *it;
		if (e->posx > SCREEN_W) {
			cout << "fuera bala" << endl;
			e->active = false;
			listBullets.erase(it);
			break;
		}
	}
}
bool Hero::Init(){
	
	bouncer = al_load_bitmap("Assets/_h.png");
	spriteBullet = al_load_bitmap("Assets/bullet_1.png");
	if (!bouncer||!spriteBullet) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		return false;
	}
	width = al_get_bitmap_width(bouncer);
	height = al_get_bitmap_height(bouncer);
	posx = width;
	posy = SCREEN_H / 2 - height / 2;
	return true;

}
void Hero::CreateBullets() {
	for (int i = 0; i < 15; i++) {
		Entity::Bullet* e=new Bullet;
		e->sprite = spriteBullet;
		aBullets[i] = e;
	}
}
 Entity::Bullet* Hero::GetBullet(){
	 
	 for (int i = 0; i < 15; i++) {
		 Entity::Bullet* e=aBullets[i];
		 if (!e->active) {
			 e->posx = posx;
			 e->posy = posy;
			 e->active = true;
			 p = posx;
			 return e;
		 }
	 }
	 cout << "warning bullets al limite" << endl;
	 return NULL;
	 
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
	CreateBullets();
	fireRate = 0.5f;
}
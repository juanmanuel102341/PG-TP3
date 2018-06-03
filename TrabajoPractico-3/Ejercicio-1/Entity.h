#ifndef ENTITY_H
#define ENTITY_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include"Reg.h"
#include<iostream>
#include<list>

using namespace std;
class Entity
{
public:
	struct Bullet {
		int posx, posy;
		ALLEGRO_BITMAP* sprite = NULL;
		bool active = false;
		float velocity=8.0f;
		
	};
	Entity();
	~Entity();
	virtual bool Init() = 0;
	virtual void Move() = 0;
	virtual void Draw() = 0;
	virtual void Update(double elapsed)=0;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *spriteBullet=NULL;
	virtual void Set(Reg* _reg) = 0;
	int posx;
	int posy;
	int width;
	int height;
	float velocity;
	Reg* reg;
	bool dead;
	Bullet* aBullets[15];
	list<Bullet*>listBullets;
	float fireRate;
private:

	
	
};

#endif // !ENTITY_H

#ifndef ENTITY_H
#define ENTITY_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include"Reg.h"
#include<iostream>
#include<list>
#include"Gui.h"
using namespace std;
class Entity
{
public:
	struct Bullet {
		int posx, posy,width,height;
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
	virtual void SetGui(Gui*gui)=0;
	int posx;
	int posy;
	int width;
	int height;
	int widthBullet;
	int heightBullet;
	float velocity;
	Reg* reg;
	Gui* gui;
	bool dead;
	Bullet* aBullets[15];
	list<Bullet*>listBullets;
	float fireRate;
	int lifes;
private:

	
	
};

#endif // !ENTITY_H

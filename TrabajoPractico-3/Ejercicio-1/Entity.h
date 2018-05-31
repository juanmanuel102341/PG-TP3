#ifndef ENTITY_H
#define ENTITY_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include"Reg.h"
#include<iostream>
using namespace std;
class Entity
{
public:
	Entity();
	~Entity();
	virtual bool Init()=0;
	virtual void Move()=0;
	virtual void Draw()=0;
	ALLEGRO_BITMAP *bouncer = NULL;
	virtual void Set(Reg* _reg)=0;
	int posx;
	int posy;
	int width;
	int height;
	Reg* reg;
private:
	
};

#endif // !ENTITY_H

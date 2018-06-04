#ifndef MENU_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include<iostream>
#include"Reg.h"
#define MENU_H
using namespace std;
class Menu
{
	
public:
	struct Point {
		int x, y;
	};
	Menu();
	~Menu();
	void Init();
	void Draw();
	void Update();
	bool  activeNewGame=false;
	bool activeExit=false;
private:
	ALLEGRO_BITMAP* back;
	ALLEGRO_BITMAP* newGame;
	ALLEGRO_BITMAP* exit;
	int widthBack, widthNewGame, widthExit, heighBack, heightNewGame, heighExit;
	void InputMouse();
	int posMouseX,posMouseY;
	bool Colision(Point p,int _width,int _height);
	
	Point pointNewGame;
	Point pointExit;
};

#endif // !MENU_H


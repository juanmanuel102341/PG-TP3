#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include"Reg.h"
#include"Entity.h"
#include"Hero.h"
#include"Enemy.h"
#include"Contact.h"
#include"SpawnManager.h"
#include"Gui.h"
#include"Menu.h"
using namespace std;


class Game
{
	
public:
	Game();
	~Game();
	void Run();
private:
	bool Init();
	void Render();
	void ProcessEvents();
	void Update(double elpased);
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	bool doexit = false;
	bool redraw = true;
	bool menuActive=true;
	Reg* reg;
	Entity*player;
	Entity*enemy;
	Contact* contact;
	SpawnManager* spawnManager;
	Gui*gui;
	Menu*menu;
};

#endif // !GAME_G


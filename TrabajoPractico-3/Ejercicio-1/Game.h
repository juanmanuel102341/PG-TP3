#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>
#include"Reg.h"
#include"Entity.h"
#include"Hero.h"
#include"Enemy.h"
#include"Contact.h"
#include"SpawnManager.h"
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
	void Update();
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	bool doexit = false;
	bool redraw = true;
	Reg* reg;
	Entity*player;
	Entity*enemy;
	Contact* contact;
	SpawnManager* spawnManager;
};

#endif // !GAME_G


#include"Game.h"



bool Game::Init() {
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return false;
	}
	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return false;
	}
	if (!al_init_image_addon()) {
		fprintf(stderr, "failed to initialize image addon!\n");
		return false;
	}
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return false;
	}
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return false;
	}
	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return false;
	}
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_start_timer(timer);
	reg = new Reg;
	player = new Hero();
	player->Set(reg);
	//enemy = new Enemy;
	contact = new Contact(player, enemy);
	spawnManager = new SpawnManager();
	return true;
}
void Game::Update(double elapsed) {
	player->Update(elapsed);
	//enemy->Move();
	spawnManager->Update();
	//if (contact->Between()) {
		//doexit = true;
	//}

}
void Game::Render() {
	
	//ALLEGRO_EVENT ev2;
	//al_wait_for_event(event_queue, &ev2);
//	if (ev2.type == ALLEGRO_EVENT_TIMER) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	player->Draw();
//	enemy->Draw();
	spawnManager->Draw();
	al_flip_display();
	//}
	
	
}
void Game::ProcessEvents(){
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_TIMER) {
	//logica del juego
		double e= ev.timer.timestamp;
		Update(e);
		redraw = true;
	}else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		doexit = false;
		
	}else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			reg->key[KEY_UP] = true;
			break;

		case ALLEGRO_KEY_DOWN:
			reg->key[KEY_DOWN] = true;
			break;

		case ALLEGRO_KEY_LEFT:
			reg->key[KEY_LEFT] = true;
			break;

		case ALLEGRO_KEY_RIGHT:
			reg->key[KEY_RIGHT] = true;
			break;
		case ALLEGRO_KEY_SPACE:

			cout << "apreto spacce";
			reg->key[KEY_SHOOT] = true;
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			reg->key[KEY_UP] = false;
			break;

		case ALLEGRO_KEY_DOWN:
			reg->key[KEY_DOWN] = false;
			break;

		case ALLEGRO_KEY_LEFT:
			reg->key[KEY_LEFT] = false;
			break;

		case ALLEGRO_KEY_RIGHT:
			reg->key[KEY_RIGHT] = false;
			break;

		case ALLEGRO_KEY_ESCAPE:
			doexit = true;
			break;
		case ALLEGRO_KEY_SPACE:
			cout << "arriba space";
		reg->key[KEY_SHOOT]= false;
		break;
		}
	}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			//renderizado
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
				Render();
			
		}
	
}
void Game::Run(){
	while (!doexit)
	{
		ProcessEvents();
		
		
	}

}
Game::Game() {
	cout << "iniciano juego" << endl;
	if (!Init()) {
		cout << "juego no inicializado!!!!!"<<endl;
		return;
	}
	Run();
}
Game::~Game(){
	delete spawnManager;
	delete player;
	delete enemy;
	delete contact;
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
}
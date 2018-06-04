#include"Menu.h"
void Menu::Update(){
	InputMouse();
	if (Colision(pointNewGame, widthNewGame, heightNewGame)) {
		cout << "contacto newGame" << endl;
		activeNewGame = true;
	}
	if(Colision(pointExit,widthExit,heighExit)){
		cout << "contacto exit"<<endl;
		activeExit = true;
		}

}
void Menu::Draw(){
	al_draw_bitmap(back, SCREEN_W/2 - widthBack / 2, SCREEN_H/2 - heighBack / 2, 0);
	al_draw_bitmap(newGame, pointNewGame.x,pointNewGame.y,0);
	al_draw_bitmap(exit,pointExit.x ,pointExit.y , 0);


}
void Menu::Init(){

	back=al_load_bitmap("Assets/menuBack.png");
	newGame = al_load_bitmap("Assets/newGame.png");
	exit = al_load_bitmap("Assets/menuExit.png");
	if (!back || !newGame || !exit) {
		fprintf(stderr, "failed to create menu bitmap!\n");
	}
	widthBack = al_get_bitmap_width(back);
	heighBack = al_get_bitmap_height(back);
	widthNewGame = al_get_bitmap_width(newGame);
	heightNewGame = al_get_bitmap_height(newGame);
	widthExit = al_get_bitmap_width(exit);
	heighExit = al_get_bitmap_height(exit);
	pointNewGame.x = SCREEN_W / 2 - widthBack / 2 + widthBack / 2 - widthNewGame / 2;
	pointNewGame.y = SCREEN_H / 2 - heighBack / 2 + heightNewGame / 2;
	pointExit.x = SCREEN_W / 2 - widthBack / 2 + widthBack / 2 - widthExit / 2;
	pointExit.y = SCREEN_H / 2 - heighBack / 2 + heighBack / 2 + heighExit / 2;
	
	cout << "x new game " << pointNewGame.x << endl;
}
void Menu::InputMouse(){
	ALLEGRO_MOUSE_STATE state;


	al_get_mouse_state(&state);
	if (state.buttons & 1) {
	//printf("Mouse position: (%d, %d)\n", state.x, state.y);
	posMouseX = state.x;
	posMouseY = state.y;
	}
}
bool Menu::Colision(Point point,int _width,int _height){
	if (posMouseX > point.x&&posMouseX<point.x + _width&&posMouseY>point.y&&posMouseY < point.y + _height) {
		return true;
	}
	return false;

}
Menu::Menu(){
	Init();
}
Menu::~Menu(){}
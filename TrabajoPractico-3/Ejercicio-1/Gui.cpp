#include"Gui.h"
void Gui::Init(){
	life = al_load_font("Assets/foo.ttf",24,0);
	if(!life){
		fprintf(stderr, "failed to create FONT!\n");
	}
	//nlife = life;
}
void Gui::Draw(){
	al_draw_textf(life, al_map_rgb(255, 0, 0), 10, 10, 0, "VIDAS: %i",numLife);
	

}
void Gui::Update(){

}

void Gui::UpdateLife(int _newLife) {
	numLife = _newLife;
}
Gui::Gui(){
//	textLife = "VIDA: ";
	Init();
	numLife = 3;
	
}
Gui::~Gui(){
}
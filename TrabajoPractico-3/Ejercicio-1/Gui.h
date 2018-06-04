#ifndef GUI_H
#define GUI_H
#include <allegro5/allegro.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_native_dialog.h>
#include <stdio.h>
class Gui
{
public:
	Gui();
	~Gui();
	void Update();
	void Draw();
	void Init();
	int numLife;
	void UpdateLife(int _newLife);
private:
	ALLEGRO_FONT* life;

	
};
#endif // !GUI_H

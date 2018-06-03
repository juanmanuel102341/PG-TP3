#ifndef REG_H
#define REG_H
const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,KEY_SHOOT
};
class Reg
{
	
public:
	
	Reg();
	//~Reg();
	bool key[5] = { false, false, false, false,false };
	bool shoot = false;
private:

};

#endif // !REG

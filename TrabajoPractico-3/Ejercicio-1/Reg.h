#ifndef REG_H
#define REG_H
const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
class Reg
{
	
public:
	
	Reg();
	//~Reg();
	bool key[4] = { false, false, false, false };
private:

};

#endif // !REG

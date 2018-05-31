#ifndef HERO_H
#define HERO_H
#include"Entity.h"


class Hero: public Entity
{
public:
	Hero();
	~Hero();
	virtual bool Init();
	virtual void Move();
	virtual void Draw();
	virtual void Set(Reg* reg);
private:
	Reg*reg;
};
#endif

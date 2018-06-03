#ifndef ENEMY_H
#define ENEMY_H
#include"Entity.h"
class Enemy: public Entity
{
public:
	Enemy();
	~Enemy();
	virtual bool Init() ;
	virtual void Move() ;
	virtual void Draw() ;
	void Update(double elpased);
	virtual void Set(Reg* reg);
private:

};

#endif // !ENEMY_H


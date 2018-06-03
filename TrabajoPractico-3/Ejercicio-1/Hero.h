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
	void Update(double elapsed);

private:
	
	void CreateBullets();
	Bullet* GetBullet();
	void MoveBullets(double elapsed);
	void DrawBullets();
	void OutSceneBullet();
	Reg*reg;
	int p;
	double timing;
};
#endif

#ifndef CONTACT_H
#define CONTACT_H
#include"Hero.h"
#include"Enemy.h"
class Contact
{
public:
	Contact(Entity*hero,Entity*enemy);
	~Contact();
	void Between();
	
private:
	Entity* hero;
	Entity*enemy;
};
#endif // !CONTACT_H

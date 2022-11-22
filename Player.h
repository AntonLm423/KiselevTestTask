#pragma once
#include "Entity.h" 
#include "Monster.h"

/* ќбъ€вление класса  Player*/

class Monster;

class Player : private Entity 
{
	friend class Monster; // объ€вле€ем класс Monster другом дл€ доступа к private пол€м

private:

	int healingCount = 3; // количество исцелений

public:

	
	Player(); // конструктор по умолчанию
	Player(const int health, const int damage, const int attack, const int protection); // конструктор по заданным параметрам
	
	bool Heal(); // метод исцелени€ игрока
	
	bool AttackMonster(Monster &monster); // метод нападени€ игрока на монстра

	bool AttackPlayer(Player &secondPlayer); // метод нападени€ игрока на игрока

	/* getters */
	int getTotalHealth(); 
	int getCurrentHealth(); 
	int getDamage();
	int getAttack();
	int getProtection();
	int getHealCount();

};


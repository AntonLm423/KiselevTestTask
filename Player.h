#pragma once
#include "Entity.h" 
#include "Monster.h"

/* Объявление класса  Player, наследованного от Entity */

class Monster;

class Player : private Entity 
{
	friend class Monster; // объявлеяем класс Monster другом для доступа к private полям

private:

	int healingCount = 3; // количество исцелений

public:

	
	Player(); // конструктор по умолчанию
	Player(const int health, const int damage, const int attack, const int protection); // конструктор по заданным параметрам
	
	bool Heal(); // метод исцеления игрока
	
	bool AttackMonster(Monster &monster); // метод нападения игрока на монстра

	bool AttackPlayer(Player &secondPlayer); // метод нападения игрока на игрока

	/* getters */
	int getTotalHealth(); 
	int getCurrentHealth(); 
	int getDamage();
	int getAttack();
	int getProtection();
	int getHealCount();

};


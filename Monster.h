#pragma once
#include"Entity.h"
#include"Player.h"

/* Объявление класса Monster, наследованного он Entity */

class Player;

class Monster : private Entity
{
	friend class Player; // объявлеяем класс Player другом для доступа к private полям

public:

	Monster(); // конструктор по умолчанию
	Monster(const int health, const int damage, const int attack, const int protection); // конструктор по заданным параметрам

	bool AttackPlayer(Player &player); // метод нападения монстра на игрока

	/* getters */
	int getTotalHealth();
	int getCurrentHealth();
	int getDamage();
	int getAttack();
	int getProtection();
};


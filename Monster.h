#pragma once
#include"Entity.h"
#include"Player.h"

/* ���������� ������ Monster, �������������� �� Entity */

class Player;

class Monster : private Entity
{
	friend class Player; // ���������� ����� Player ������ ��� ������� � private �����

public:

	Monster(); // ����������� �� ���������
	Monster(const int health, const int damage, const int attack, const int protection); // ����������� �� �������� ����������

	bool AttackPlayer(Player &player); // ����� ��������� ������� �� ������

	/* getters */
	int getTotalHealth();
	int getCurrentHealth();
	int getDamage();
	int getAttack();
	int getProtection();
};


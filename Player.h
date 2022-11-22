#pragma once
#include "Entity.h" 
#include "Monster.h"

/* ���������� ������  Player*/

class Monster;

class Player : private Entity 
{
	friend class Monster; // ���������� ����� Monster ������ ��� ������� � private �����

private:

	int healingCount = 3; // ���������� ���������

public:

	
	Player(); // ����������� �� ���������
	Player(const int health, const int damage, const int attack, const int protection); // ����������� �� �������� ����������
	
	bool Heal(); // ����� ��������� ������
	
	bool AttackMonster(Monster &monster); // ����� ��������� ������ �� �������

	bool AttackPlayer(Player &secondPlayer); // ����� ��������� ������ �� ������

	/* getters */
	int getTotalHealth(); 
	int getCurrentHealth(); 
	int getDamage();
	int getAttack();
	int getProtection();
	int getHealCount();

};


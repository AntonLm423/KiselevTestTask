#include "Monster.h"

/* ���������� ������� ������ Monster */

Monster::Monster()
{
	this->totalHealth = 0;
	this->currentHealth = 0;
	this->damage = 0;
	this->attack = 0;
	this->protection = 0;
}

Monster::Monster(int health, int damage, int attack, int protection)
{
	// ���� �����-���� �� ���������� ������������ �� ������������� ��������, ���������� ����������
	if (
		health < MIN_MONSTER_HEALTH || health > MAX_MONSTER_HEALTH ||
		damage < MIN_MONSTER_DAMAGE || damage > MAX_MONSTER_DAMAGE ||
		attack < MIN_MONSTER_ATTACK || attack > MAX_MONSTER_ATTACK ||
		protection < MIN_MONSTER_PROTECTION || protection > MAX_MONSTER_PROTECTION
		)
	{
		throw "�������� ��������� ������������ ������ Monster";
		return;
	}

	this->currentHealth = this->totalHealth = health;
	this->damage = damage;
	this->attack = attack;
	this->protection = protection;
}

bool Monster::AttackPlayer(Player &player) {

	// ���� �������� ������� �� ��������� ��� �������, ������� ����� �����������
	if (this->currentHealth == 0)
		return false;

	// ���� �������� ������ �� ��������� ��� ������� ���, ������� ����� ��������
	if (player.currentHealth == 0)
		return true;

	int attackMod = this->attack - player.protection + 1;

	// ������ ��������� ���� �� ���� �����
	if (attackMod <= 0)
		attackMod = 1;

	std::cout << "\n  ����� ������� �� ������. ����������� �����: " << attackMod;
	std::cout << "\n\n  ������� �����:";

	for (int i = 0; i < attackMod; i++) {

		int tmp = rollDice();


		std::cout << "\n  ������ ������(" << i + 1 << '/' << attackMod << "): " << tmp;

		// ���� ���� �������
		if (tmp == 5 || tmp == 6) {
			// ���� ���� �������, �� ������� ������������ �������� �� ��������� 
			// ���� ���������� � ���������� �� �������� �������������
			player.currentHealth -= (MIN_MONSTER_DAMAGE + rand() % this->damage);

			// �������� �� ����� ���� ������ ������������ ���������
			if (player.currentHealth < MIN_PLAYER_HEALTH)
				player.currentHealth = MIN_PLAYER_HEALTH;

			return true;
		}

	}

	return false;
}

int Monster::getTotalHealth() {
	return this->totalHealth;
}

int Monster::getCurrentHealth() {
	return this->currentHealth;
}

int Monster::getDamage() {
	return this->damage;
}

int Monster::getAttack() {
	return this->attack;
}

int Monster::getProtection() {
	return this->protection;
}
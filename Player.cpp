#include "Player.h"

/* ���������� ������� ������ Player */

Player::Player()
{
	this->totalHealth = 0;
	this->currentHealth = 0;
	this->damage = 0;
	this->attack = 0;
	this->protection = 0;
}

Player::Player(int health, int damage, int attack, int protection)
{
	// ���� �����-���� �� ���������� ������������ �� ������������� ��������, �� ���������� ������ ������
	if ( 
		health < MIN_PLAYER_HEALTH || health > MAX_PLAYER_HEALTH ||
		damage < MIN_PLAYER_DAMAGE || damage > MAX_PLAYER_DAMAGE ||
		attack < MIN_PLAYER_ATTACK || attack > MAX_PLAYER_ATTACK ||
		protection < MIN_PLAYER_PROTECTION || protection > MAX_PLAYER_PROTECTION
		)
	{
		throw "�������� ��������� ������������ ������ Player";
		return;	
	}

	this->currentHealth = this->totalHealth = health;
	this->damage = damage;
	this->attack = attack;
	this->protection = protection;
}


bool Player::Heal()
{
	// ���� ����������� ������� ���������� 
	if (healingCount == 0) 
		return false;

	// ���� �������� ��� ������������
	if (this->currentHealth == this->totalHealth)
		return false;

	this->currentHealth += this->totalHealth / 2;

	// ���� ����� ��������� ����� �� ������� ������������� �������� !�������� �������!
	if (this->currentHealth > totalHealth)
		this->currentHealth = totalHealth;

	// ���� ����� ��������� ����� �� ������� !������������� �������� ��� ������!
	if (this->currentHealth > MAX_PLAYER_HEALTH)
		this->currentHealth = MAX_PLAYER_HEALTH;
	
	this->healingCount--;
	return true;
}

bool Player::AttackMonster(Monster &monster)
{
	// ���� �������� ������ �� ��������� ��� �������, ������� ����� �����������
	if (this->currentHealth == 0) 
		return false;

	// ���� �������� ������� �� ��������� ��� ������� ���, ������� ����� ��������
	if (monster.currentHealth == 0) 
		return true;

	int attackMod = this->attack - monster.protection + 1;
	
	// ������ ��������� ���� �� ���� �����
	if (attackMod <= 0)
		attackMod = 1;

	std::cout << "\n  ����� ������ �� �������. ����������� �����: " << attackMod;
	std::cout << "\n\n  ������� �����:";

	for (int i = 0; i < attackMod; i++) {
		
		int tmp = rollDice();
		
		
		std::cout << "\n  ������ ������(" << i + 1 << '/' << attackMod << "): " << tmp;

		// ���� ���� �������
		if (tmp == 5 || tmp == 6) {
			// ���� ���� �������, �� ������� ������������ �������� �� ��������� 
			// ���� ���������� � ���������� �� �������� �������������
			monster.currentHealth -= (MIN_PLAYER_DAMAGE + rand() % this->damage);
			
			// �������� �� ����� ���� ������ ������������ ���������
			if (monster.currentHealth < MIN_MONSTER_HEALTH)
				monster.currentHealth = MIN_MONSTER_HEALTH;

			return true;
		}
		
	}

	
	return false;
}



bool Player::AttackPlayer(Player& secondPlayer) {

	// ���� �������� ��������� ������ �� ��������� ��� �������, ������� ����� �����������
	if (this->currentHealth == 0)
		return false;

	// ���� �������� ����������� ������ �� ��������� ��� ������� ���, ������� ����� ��������
	if (secondPlayer.currentHealth == 0)
		return true;

	int attackMod = this->attack - secondPlayer.protection + 1;

	// ������ ��������� ���� �� ���� �����
	if (attackMod <= 0)
		attackMod = 1;


	std::cout << "\n  ����� ������ �� �������. ����������� �����: " << attackMod;
	std::cout << "\n\n  ������� �����:";

	srand((unsigned)time(NULL));

	for (int i = 0; i < attackMod; i++) {

		int tmp = rollDice();


		std::cout << "\n  ������ ������(" << i + 1 << '/' << attackMod << "): " << tmp;

		// ���� ���� �������
		if (tmp == 5 || tmp == 6) {
			// ���� ���� �������, �� ������� ������������ �������� �� ��������� 
			// ���� ���������� � ���������� �� �������� �������������
			secondPlayer.currentHealth -= (MIN_PLAYER_DAMAGE + rand() % this->damage);

			// �������� �� ����� ���� ������ ������������ ���������
			if (secondPlayer.currentHealth < MIN_MONSTER_HEALTH)
				secondPlayer.currentHealth = MIN_MONSTER_HEALTH;

			return true;
		}

	}

	return false;
}

int Player::getTotalHealth() {
	return this->totalHealth;
}

int Player::getCurrentHealth() {
	return this->currentHealth;
}

int Player::getDamage() {
	return this->damage;
}

int Player::getAttack() {
	return this->attack;
}

int Player::getProtection() {
	return this->protection;
}

int Player::getHealCount() {
	return this->healingCount;
}
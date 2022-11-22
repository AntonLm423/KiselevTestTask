#include "Monster.h"

/* Определния функций класса Monster */

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
	// если какой-либо из параметров конструктора не удовлетворяет условиям, генерируем исключение
	if (
		health < MIN_MONSTER_HEALTH || health > MAX_MONSTER_HEALTH ||
		damage < MIN_MONSTER_DAMAGE || damage > MAX_MONSTER_DAMAGE ||
		attack < MIN_MONSTER_ATTACK || attack > MAX_MONSTER_ATTACK ||
		protection < MIN_MONSTER_PROTECTION || protection > MAX_MONSTER_PROTECTION
		)
	{
		throw "Неверные параметры конструктора класса Monster";
		return;
	}

	this->currentHealth = this->totalHealth = health;
	this->damage = damage;
	this->attack = attack;
	this->protection = protection;
}

bool Monster::AttackPlayer(Player &player) {

	// если здоровье монстра не позволяет ему напасть, считаем атака безуспешной
	if (this->currentHealth == 0)
		return false;

	// если здоровье игрока не позволяет ему принять бой, считаем атаку успешной
	if (player.currentHealth == 0)
		return true;

	int attackMod = this->attack - player.protection + 1;

	// всегда бросается хотя бы один кубик
	if (attackMod <= 0)
		attackMod = 1;

	std::cout << "\n  Атака монстра на игрока. Модификатор атаки: " << attackMod;
	std::cout << "\n\n  Процесс атаки:";

	for (int i = 0; i < attackMod; i++) {

		int tmp = rollDice();


		std::cout << "\n  Бросок кубика(" << i + 1 << '/' << attackMod << "): " << tmp;

		// если удар успешен
		if (tmp == 5 || tmp == 6) {
			// если удар успешен, то берется произвольное значение из параметра 
			// урон атакующего и вычитается из здоровья защищающегося
			player.currentHealth -= (MIN_MONSTER_DAMAGE + rand() % this->damage);

			// здоровье не может быть меньше минимального параметра
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
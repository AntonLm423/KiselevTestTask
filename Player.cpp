#include "Player.h"

/* Определния функций класса Player */

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
	// если какой-либо из параметров конструктора не удовлетворяет условиям, то возвращаем пустой объект
	if ( 
		health < MIN_PLAYER_HEALTH || health > MAX_PLAYER_HEALTH ||
		damage < MIN_PLAYER_DAMAGE || damage > MAX_PLAYER_DAMAGE ||
		attack < MIN_PLAYER_ATTACK || attack > MAX_PLAYER_ATTACK ||
		protection < MIN_PLAYER_PROTECTION || protection > MAX_PLAYER_PROTECTION
		)
	{
		throw "Неверные параметры конструктора класса Player";
		return;	
	}

	this->currentHealth = this->totalHealth = health;
	this->damage = damage;
	this->attack = attack;
	this->protection = protection;
}


bool Player::Heal()
{
	// если закончились попытки исцелиться 
	if (healingCount == 0) 
		return false;

	// если здоровье уже максимальное
	if (this->currentHealth == this->totalHealth)
		return false;

	this->currentHealth += this->totalHealth / 2;

	// если после исцеления вышли за пределы максимального здоровья !текущего объекта!
	if (this->currentHealth > totalHealth)
		this->currentHealth = totalHealth;

	// если после исцеления вышли за пределы !максимального здоровья для игрока!
	if (this->currentHealth > MAX_PLAYER_HEALTH)
		this->currentHealth = MAX_PLAYER_HEALTH;
	
	this->healingCount--;
	return true;
}

bool Player::AttackMonster(Monster &monster)
{
	// если здоровье игрока не позволяет ему напасть, считаем атака безуспешной
	if (this->currentHealth == 0) 
		return false;

	// если здоровье монстра не позволяет ему принять бой, считаем атаку успешной
	if (monster.currentHealth == 0) 
		return true;

	int attackMod = this->attack - monster.protection + 1;
	
	// всегда бросается хотя бы один кубик
	if (attackMod <= 0)
		attackMod = 1;

	std::cout << "\n  Атака игрока на монстра. Модификатор атаки: " << attackMod;
	std::cout << "\n\n  Процесс атаки:";

	for (int i = 0; i < attackMod; i++) {
		
		int tmp = rollDice();
		
		
		std::cout << "\n  Бросок кубика(" << i + 1 << '/' << attackMod << "): " << tmp;

		// если удар успешен
		if (tmp == 5 || tmp == 6) {
			// если удар успешен, то берется произвольное значение из параметра 
			// урон атакующего и вычитается из здоровья защищающегося
			monster.currentHealth -= (MIN_PLAYER_DAMAGE + rand() % this->damage);
			
			// здоровье не может быть меньше минимального параметра
			if (monster.currentHealth < MIN_MONSTER_HEALTH)
				monster.currentHealth = MIN_MONSTER_HEALTH;

			return true;
		}
		
	}

	
	return false;
}



bool Player::AttackPlayer(Player& secondPlayer) {

	// если здоровье надающего игрока не позволяет ему напасть, считаем атака безуспешной
	if (this->currentHealth == 0)
		return false;

	// если здоровье защищающего игрока не позволяет ему принять бой, считаем атаку успешной
	if (secondPlayer.currentHealth == 0)
		return true;

	int attackMod = this->attack - secondPlayer.protection + 1;

	// всегда бросается хотя бы один кубик
	if (attackMod <= 0)
		attackMod = 1;


	std::cout << "\n  Атака игрока на монстра. Модификатор атаки: " << attackMod;
	std::cout << "\n\n  Процесс атаки:";

	srand((unsigned)time(NULL));

	for (int i = 0; i < attackMod; i++) {

		int tmp = rollDice();


		std::cout << "\n  Бросок кубика(" << i + 1 << '/' << attackMod << "): " << tmp;

		// если удар успешен
		if (tmp == 5 || tmp == 6) {
			// если удар успешен, то берется произвольное значение из параметра 
			// урон атакующего и вычитается из здоровья защищающегося
			secondPlayer.currentHealth -= (MIN_PLAYER_DAMAGE + rand() % this->damage);

			// здоровье не может быть меньше минимального параметра
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
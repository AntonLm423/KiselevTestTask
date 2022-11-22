#include "Entity.h"

/* Определния функций класса Entity */

int Entity::rollDice() {
	// генератор псведослучайных чисел
	return 1 + rand() % 6;
}
#pragma once
#include"Constants.h"
#include<ctime>
#include<random>
#include<iostream>

/* Базовый класс */

class Entity
{
protected:

	int totalHealth; // всего здоровья
	int currentHealth; // здоровье в текущий момент времени(после битвы)

	int damage;

	int attack;
	int protection;

protected:

	int rollDice(); // бросок кубика(генератор вседослучайных чисел в диапазоне)


};


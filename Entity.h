#pragma once
#include"Constants.h"
#include<ctime>
#include<random>
#include<iostream>

/* ������� ����� */

class Entity
{
protected:

	int totalHealth; // ����� ��������
	int currentHealth; // �������� � ������� ������ �������(����� �����)

	int damage;

	int attack;
	int protection;

protected:

	int rollDice(); // ������ ������(��������� �������������� ����� � ���������)


};


#include "Entity.h"

/* ���������� ������� ������ Entity */

int Entity::rollDice() {
	// ��������� ��������������� �����
	return 1 + rand() % 6;
}
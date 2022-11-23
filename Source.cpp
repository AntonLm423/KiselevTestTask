/* 
	�������� ������� ��� ����� ������������� Heads and Hands
	��������: ������� �����
*/

#include<iostream>
#include<windows.h> 
#include<locale>
#include"Entity.h"
#include"Player.h"
#include"Monster.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	/* ���� ������������� ������ */
	// ������������� �������������� ������ � ������������(���������� ����������)
	int health, damage, attack, protection = 0;
	do
	{

		cout << "\n***��������� ���� ���������� ������***\n";
		cout << "    *��� ����� ����� ���� ������\n\n";
		cout << "  ������� �������� ������: ";
		cin >> health;
		cout << "  ������� ���� ������: ";
		cin >> damage;
		cout << "  ������� �������� ����� ������: ";
		cin >> attack;
		cout << "  ������� �������� ������ ������: ";
		cin >> protection;
	
	} while (
		health < MIN_PLAYER_HEALTH || health > MAX_PLAYER_HEALTH ||
		damage < MIN_PLAYER_DAMAGE || damage > MAX_PLAYER_DAMAGE ||
		attack < MIN_PLAYER_ATTACK || attack > MAX_PLAYER_ATTACK ||
		protection < MIN_PLAYER_PROTECTION || protection > MAX_PLAYER_PROTECTION
		);

	// ������ ����� ������ ����� ����������� � ����������
	Player player((int)health, (int)damage, (int)attack, (int)protection);

	/*  ������� ����  */
	int answer = -1;
	do {
		system("cls");
		
		cout << "***������� ����***" <<
			"\n\n �������� ��������:" <<
			"\n  (1) �������� ��� ���������" <<
			"\n  (2) �������� ���������" <<
			"\n  (3) ��������� ���������� �������" <<
			"\n  (4) ������������ ����� ���������� ������� �� ����" <<
			"\n  (5) ��������� ���������� ������" <<
			"\n  (0) �����" <<
			"\n\n ����: ";

		cin >> answer;
		
		switch (answer) {
			/* �������� ��������� ������ */
		case 1: {

			system("cls");
			cout << " �������������� ������:" <<
				"\n  ��������: " << player.getCurrentHealth() << '/' << player.getTotalHealth() <<
				"\n  ����: " << player.getDamage() <<
				"\n  ����� " << player.getAttack() <<
				"\n  ������ " << player.getProtection() <<
				"\n  �������� ���������: " << player.getHealCount();

			cout << endl << endl;
			system("pause");
			break;
		}
			  /* �������� ������ */
		case 2: {
			system("cls");

			if (player.Heal())
				cout << "\n ����� ������� ������! ��� ��������: " << player.getCurrentHealth() << '/' << player.getTotalHealth();
			else
				cout << "\n �� ������� �������� ������!";

			cout << endl << endl;
			system("pause");
			break;
		}
			  /* ��������� �������� ����������� ������� */
		case 3: {
			system("cls");

			if (player.getCurrentHealth() == 0)
				cout << "\n\n  ���� �������� �� ��������� ������� �� �������";
			else {

				// ������ ���������� �������
				srand((unsigned)time(NULL));
				Monster randMonster(
					1 + rand() % MAX_MONSTER_HEALTH,
					MIN_MONSTER_DAMAGE + rand() % MAX_MONSTER_DAMAGE,
					MIN_MONSTER_ATTACK + rand() % MAX_MONSTER_ATTACK,
					MIN_MONSTER_PROTECTION + rand() % MAX_MONSTER_PROTECTION
				);

				// ������� ��� ���������
				cout << "  ��������� ������: " <<
					"\n  ��������: " << randMonster.getCurrentHealth() << '/' << randMonster.getTotalHealth() <<
					"\n  ����: " << randMonster.getDamage() <<
					"\n  ����� " << randMonster.getAttack() <<
					"\n  ������ " << randMonster.getProtection();


				if (player.AttackMonster(randMonster))
					cout << "\n\n  ��� ������� ��������� �������! ��� �������� ����� ���������: " << randMonster.getCurrentHealth() << '/' << randMonster.getTotalHealth();
				else
					cout << "\n\n  ��� �� ������� ��������� ������� :(";
			}

			cout << endl << endl;
			system("pause");
			break;
		}
			  /* ����������� ��������� �������� ���������� ������� �� ���� */
		case 4: {
			system("cls");
			
			// ���� ����������� ��������
			if (player.getCurrentHealth() == 0) {
				cout << "\n\n  ���� �������� �� ��������� ����������� ���������";
			}
			else {
				// ������ ���������� �������
				srand((unsigned)time(NULL));

				Monster randMonster(
					1 + rand() % MAX_MONSTER_HEALTH,
					MIN_MONSTER_DAMAGE + rand() % MAX_MONSTER_DAMAGE,
					MIN_MONSTER_ATTACK + rand() % MAX_MONSTER_ATTACK,
					MIN_MONSTER_PROTECTION + rand() % MAX_MONSTER_PROTECTION
				);

				// ������� ��� ���������
				cout << "\n\n  ��������� ������: " <<
					"\n  ��������: " << randMonster.getCurrentHealth() << '/' << player.getTotalHealth() <<
					"\n  ����: " << randMonster.getDamage() <<
					"\n  ����� " << randMonster.getAttack() <<
					"\n  ������ " << randMonster.getProtection();


				if (randMonster.AttackPlayer(player))
					cout << "\n\n  ��� �������� ������! ���� �������� ����� ���������: " << player.getCurrentHealth() << '/' << player.getTotalHealth();
				else
					cout << "\n\n  ������� �� ������� ��������� ��� :)";
			}

			cout << endl << endl;
			system("pause");
			break;
		}
		/* ����� �� �������� ���������� ������ */
		case 5: {
			system("cls");

			// ���� ����������� ��������
			if (player.getCurrentHealth() == 0)
				cout << "\n\n  ���� �������� �� ��������� �������";
			else {
				// ������ ���������� ������
				srand((unsigned)time(NULL));

				Player randPlayer(
					1 + rand() % MAX_PLAYER_HEALTH,
					MIN_PLAYER_DAMAGE + rand() % MAX_PLAYER_DAMAGE,
					MIN_PLAYER_ATTACK + rand() % MAX_PLAYER_ATTACK,
					MIN_PLAYER_PROTECTION + rand() % MAX_PLAYER_PROTECTION
				);

				// ������� ��� ���������
				cout << "\n\n  ��������� �����: " <<
					"\n  ��������: " << randPlayer.getCurrentHealth() << '/' << randPlayer.getTotalHealth() <<
					"\n  ����: " << randPlayer.getDamage() <<
					"\n  ����� " << randPlayer.getAttack() <<
					"\n  ������ " << randPlayer.getProtection();


				if (player.AttackPlayer(randPlayer))
					cout << "\n\n  �� ������� ��������� ���������� ������! ��� �������� ����� ���������: " << randPlayer.getCurrentHealth() << '/' << randPlayer.getTotalHealth();
				else
					cout << "\n\n  ��� �� ������� ��������� ���������� ������ :(";
			}
			cout << endl << endl;
			system("pause");
			break;
		}
		default: 
			break;
		}

	} while (answer != 0);




	cout << "\n\n�������� ������� ��� ����� ������������� Heads and Hands\n";
	system("pause");
}


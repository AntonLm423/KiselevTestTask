/* 
	Тестовое задание для школы разработчиков Heads and Hands
	Выполнил: Киселев Антон
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

	/* ВВОД ХАРАКТЕРИСТИК ИГРОКА */
	// предусмотрена дополнительная защита в конструкторе(вызывается исключение)
	int health, damage, attack, protection = 0;
	do
	{

		cout << "\n***ПЕРВИЧНЫЙ ВВОД ПАРАМЕТРОВ ИГРОКА***\n";
		cout << "    *все числа должы быть целыми\n\n";
		cout << "  Введите здоровье игрока: ";
		cin >> health;
		cout << "  Введите урон игрока: ";
		cin >> damage;
		cout << "  Введите параметр атаки игрока: ";
		cin >> attack;
		cout << "  Введите параметр защиты игрока: ";
		cin >> protection;
	
	} while (
		health < MIN_PLAYER_HEALTH || health > MAX_PLAYER_HEALTH ||
		damage < MIN_PLAYER_DAMAGE || damage > MAX_PLAYER_DAMAGE ||
		attack < MIN_PLAYER_ATTACK || attack > MAX_PLAYER_ATTACK ||
		protection < MIN_PLAYER_PROTECTION || protection > MAX_PLAYER_PROTECTION
		);

	// создаём оъект игрока через конструктор с параметром
	Player player((int)health, (int)damage, (int)attack, (int)protection);

	/*  ГЛАВНОЕ МЕНЮ  */
	int answer = -1;
	do {
		system("cls");
		
		cout << "***ГЛАВНОЕ МЕНЮ***" <<
			"\n\n Выберите действие:" <<
			"\n  (1) Показать мои параметры" <<
			"\n  (2) Исцелить персонажа" <<
			"\n  (3) Атаковать случайного монстра" <<
			"\n  (4) Инициировать атаку случайного монстра на себя" <<
			"\n  (5) Атаковать случайного игрока" <<
			"\n  (0) Выход" <<
			"\n\n Ввод: ";

		cin >> answer;
		
		switch (answer) {
			/* ПОКАЗАТЬ ПАРАМЕТРЫ ИГРОКА */
		case 1: {

			system("cls");
			cout << " Характеристики игрока:" <<
				"\n  Здоровье: " << player.getCurrentHealth() << '/' << player.getTotalHealth() <<
				"\n  Урон: " << player.getDamage() <<
				"\n  Атака " << player.getAttack() <<
				"\n  Защита " << player.getProtection() <<
				"\n  Осталось исцелений: " << player.getHealCount();

			cout << endl << endl;
			system("pause");
			break;
		}
			  /* ИСЦЕЛИТЬ ИГРОКА */
		case 2: {
			system("cls");

			if (player.Heal())
				cout << "\n Игрок успешно исцелён! Его здоровье: " << player.getCurrentHealth() << '/' << player.getTotalHealth();
			else
				cout << "\n Не удалось исцелить игрока!";

			cout << endl << endl;
			system("pause");
			break;
		}
			  /* АТАКОВАТЬ СЛУЧАЙНО СОЗДАНННОГО МОНСТРА */
		case 3: {
			system("cls");

			if (player.getCurrentHealth() == 0)
				cout << "\n\n  Ваше здоровье не позволяет напасть на монстра";
			else {

				// создаём случайного монстра
				srand((unsigned)time(NULL));
				Monster randMonster(
					1 + rand() % MAX_MONSTER_HEALTH,
					MIN_MONSTER_DAMAGE + rand() % MAX_MONSTER_DAMAGE,
					MIN_MONSTER_ATTACK + rand() % MAX_MONSTER_ATTACK,
					MIN_MONSTER_PROTECTION + rand() % MAX_MONSTER_PROTECTION
				);

				// выводим его параметры
				cout << "  Случайный монстр: " <<
					"\n  Здоровье: " << randMonster.getCurrentHealth() << '/' << randMonster.getTotalHealth() <<
					"\n  Урон: " << randMonster.getDamage() <<
					"\n  Атака " << randMonster.getAttack() <<
					"\n  Защита " << randMonster.getProtection();


				if (player.AttackMonster(randMonster))
					cout << "\n\n  Вам удалось атаковать монстра! Его здоровье после нападения: " << randMonster.getCurrentHealth() << '/' << randMonster.getTotalHealth();
				else
					cout << "\n\n  Вам не удалось атаковать монстра :(";
			}

			cout << endl << endl;
			system("pause");
			break;
		}
			  /* ИНЦИИРОВАТЬ НАПАДЕНИЕ СЛУЧАЙНО СОЗДАННОГО МОНСТРА НА СБЕЯ */
		case 4: {
			system("cls");
			
			// если закончилось здоровье
			if (player.getCurrentHealth() == 0) {
				cout << "\n\n  Ваше здоровье не позволяет инциировать нападение";
			}
			else {
				// создаём случайного монстра
				srand((unsigned)time(NULL));

				Monster randMonster(
					1 + rand() % MAX_MONSTER_HEALTH,
					MIN_MONSTER_DAMAGE + rand() % MAX_MONSTER_DAMAGE,
					MIN_MONSTER_ATTACK + rand() % MAX_MONSTER_ATTACK,
					MIN_MONSTER_PROTECTION + rand() % MAX_MONSTER_PROTECTION
				);

				// выводим его параметры
				cout << "\n\n  Случайный монстр: " <<
					"\n  Здоровье: " << randMonster.getCurrentHealth() << '/' << player.getTotalHealth() <<
					"\n  Урон: " << randMonster.getDamage() <<
					"\n  Атака " << randMonster.getAttack() <<
					"\n  Защита " << randMonster.getProtection();


				if (randMonster.AttackPlayer(player))
					cout << "\n\n  Вас атаковал монстр! Ваше здоровье после нападения: " << player.getCurrentHealth() << '/' << player.getTotalHealth();
				else
					cout << "\n\n  Монстру не удалось атаковать вас :)";
			}

			cout << endl << endl;
			system("pause");
			break;
		}
		/* АТАКА НА СЛУЧАЙНО СОЗДАННОГО ИГРОКА */
		case 5: {
			system("cls");

			// если закончилось здоровье
			if (player.getCurrentHealth() == 0)
				cout << "\n\n  Ваше здоровье не позволяет напасть";
			else {
				// создаём случайного игрока
				srand((unsigned)time(NULL));

				Player randPlayer(
					1 + rand() % MAX_PLAYER_HEALTH,
					MIN_PLAYER_DAMAGE + rand() % MAX_PLAYER_DAMAGE,
					MIN_PLAYER_ATTACK + rand() % MAX_PLAYER_ATTACK,
					MIN_PLAYER_PROTECTION + rand() % MAX_PLAYER_PROTECTION
				);

				// выводим его параметры
				cout << "\n\n  Случайный игрок: " <<
					"\n  Здоровье: " << randPlayer.getCurrentHealth() << '/' << randPlayer.getTotalHealth() <<
					"\n  Урон: " << randPlayer.getDamage() <<
					"\n  Атака " << randPlayer.getAttack() <<
					"\n  Защита " << randPlayer.getProtection();


				if (player.AttackPlayer(randPlayer))
					cout << "\n\n  Вы успешно атаковали случайного игрока! Его здоровье после нападения: " << randPlayer.getCurrentHealth() << '/' << randPlayer.getTotalHealth();
				else
					cout << "\n\n  Вам не удалось атаковать случайного игрока :(";
			}
			cout << endl << endl;
			system("pause");
			break;
		}
		default: 
			break;
		}

	} while (answer != 0);




	cout << "\n\nТестовое задание для школы разработчиков Heads and Hands\n";
	system("pause");
}


#include "default.h"
#include "menu.h"

user user;
int current_users = 0;

bool menuUsers()
{
	bool end = 0;
	char symbol;
	char object[100];
	int current_max = 5;
	int id;

	menuUsers_render(current_users);

	symbol = _getch();
	switch (symbol)
	{
	case 72: // клавиша вверх
		if (current_users > 0)
			current_users--;
		else
			current_users = current_max;
		break;
	case 80: // клавиша вниз
		if (current_users < current_max)
			current_users++;
		else
			current_users = 0;
		break;
	case 13: // клавиша ввод
		switch (current_users)
		{
		case 0:
			user.id = getId();
			user.hits = 0;
			cout << "Enter user name: ";
			cin.getline(user.name, 16);
			cout << "Enter user surname: ";
			cin.getline(user.surname, 16);
			cout << "Enter user patronymic: ";
			cin.getline(user.patronymic, 16);
			cout << "Enter user birthday: ";
			cin.getline(user.birthday, 20);
			cout << "Enter user passport: ";
			cin.getline(user.passport, 100);
			addUser(user, true);
			break;
		case 1:
			cout << "Enter user ID: ";
			cin >> id;
			editUser(id);
			break;
		case 2:
			getUsers();
			break;
		case 3:
			cout << "Enter user ID: ";
			cin >> id;
			deleteUser(id);
			break;
		case 4:
			cout << "Enter find object: ";
			cin.getline(object, 16);
			findUser(object);
			break;
		case 5:
			end = 1;
			cls();
			break;
		}
		break;
	case 27: // клавиша esc
		end = 1;
		break;
	default:
		//cout << (int)symbol;
		break;
	}
	// ¬вод данных
	return end;
}

int menuUsers_render(int current)
{
	cls();
	setColor(0, 15);
	cout << "Choose menu option:" << endl;
	setColor(1, 15);
	if (current == 0)
		setColor(15, 0);
	cout << "Add user" << endl;
	setColor(1, 15);
	if (current == 1)
		setColor(15, 0);
	cout << "Edit user" << endl;
	setColor(1, 15);
	if (current == 2)
		setColor(15, 0);
	cout << "Users list" << endl;
	setColor(1, 15);
	if (current == 3)
		setColor(15, 0);
	cout << "Delete user" << endl;
	setColor(1, 15);
	if (current == 4)
		setColor(15, 0);
	cout << "Find user" << endl;
	setColor(1, 15);
	if (current == 5)
		setColor(15, 0);
	cout << "Back " << endl;
	setColor(0, 15);

	return current;
}
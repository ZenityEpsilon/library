#include "default.h"
#include "menu.h"

int current = 0;

bool menuMain()
{
	bool
		end = 0,
		end_users = 0,
		end_books = 0;
	char symbol;
	int current_max = 2;

	menuMain_render(current);

	symbol = _getch();
	switch (symbol)
	{
	case 72: // клавиша вверх
		if (current > 0)
			current--;
		else
			current = current_max;
		break;
	case 80: // клавиша вниз
		if (current < 2)
			current++;
		else
			current = 0;
		break;
	case 13: // клавиша ввод
		switch (current)
		{
		case 0:
			while (!end_users)
			{
				end_users = menuUsers();
			}
			break;
		case 1:
			while (!end_books)
			{
				end_books = menuBooks();
			}
			break;
		case 2:
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

int menuMain_render(int current)
{
	cls();
	setColor(0, 15);
	cout << "Choose menu option:" << endl;
	setColor(1, 15);
	if (current == 0)
		setColor(15, 0);
	cout << "Users" << endl;
	setColor(1, 15);
	if (current == 1)
		setColor(15, 0);
	cout << "Books" << endl;
	setColor(1, 15);
	if (current == 2)
		setColor(15, 0);
	cout << "Exit " << endl;
	// ¬вод данных

	return current;
}
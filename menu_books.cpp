#include "default.h"
#include "menu.h"

int current_books = 0;

bool menuBooks()
{
	bool end = 0;
	char symbol;
	int current_max = 4;

	menuBooks_render(current_books);

	symbol = _getch();
	switch (symbol)
	{
	case 72: // клавиша вверх
		if (current_books > 0)
			current_books--;
		else
			current_books = current_max;
		break;
	case 80: // клавиша вниз
		if (current_books < current_max)
			current_books++;
		else
			current_books = 0;
		break;
	case 13: // клавиша ввод
		switch (current_books)
		{
		case 0:
			cout << "Add user todo";
			break;
		case 1:
			cout << "Edit user todo";
			break;
		case 2:
			cout << "Delete user todo";
			break;
		case 3:
			cout << "Find user todo";
			break;
		case 4:
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

int menuBooks_render(int current)
{
	cls();
	setColor(0, 15);
	cout << "Choose menu option:" << endl;
	setColor(1, 15);
	if (current == 0)
		setColor(15, 0);
	cout << "Add book" << endl;
	setColor(1, 15);
	if (current == 1)
		setColor(15, 0);
	cout << "Edit book" << endl;
	setColor(1, 15);
	if (current == 2)
		setColor(15, 0);
	cout << "Delete book" << endl;
	setColor(1, 15);
	if (current == 3)
		setColor(15, 0);
	cout << "Find book" << endl;
	setColor(1, 15);
	if (current == 4)
		setColor(15, 0);
	cout << "Back " << endl;

	return current;
}
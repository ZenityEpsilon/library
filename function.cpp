#include "default.h"

void arReload(user *& arr, size_t size, size_t new_size)
{
	user * new_arr = new user[new_size];
	size = size < new_size ? size : new_size;

	for (size_t i = 0; i < size; ++i)
		new_arr[i] = arr[i];

	delete[] arr;

	arr = new_arr;
}

void elementDelete(user*& arr, size_t size, size_t exclude)
{
	size_t j = 0;
	user* new_arr = new user[size - 1];

	for (size_t i = 0; i < size; ++i)
	{
		if (i != exclude)
		{
			new_arr[j] = arr[i];
			j++;
		}
	}

	delete[] arr;

	arr = new_arr;
}

void cls(int time)
{
	Sleep(time);
	setColor(0, 15);
	system("CLS");
}

void setColor(int Bg, int Tex)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Bg = Bg << 4 | Tex;
	SetConsoleTextAttribute(hConsole, Bg);
}

int charToInt(char* arr)
{
	int len = strlen(arr);
	int value = 0;

	for (int i = 0; i < len; i++)
	{
		value += (arr[i] - 48) * pow(10, len - i - 1);
	}
	return value;
}

void paintLine(char ch, int size)
{
	for (int j = 0; j < size; j++)
	{
		cout << ch;
	}
}
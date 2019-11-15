#include "default.h"
#include "menu.h"

//void SetColorBgTex(int Bg = 0, int Tex = 15);

void main() {
	loadUsers();
	user user;
	char test[100];
	for (int i = 0; i < 0; i++)
	{
		cout << "Enter user name: ";
		cin.getline(user.name, 100);
		cout << "Enter user surname: ";
		cin.getline(user.surname, 100);
		addUser(user);
	}
	getClients();
	cin.getline(test, 100);

	cout << test;

	//SetColorBgTex(13, 10);
	cout << "This color" << endl;
	//SetColorBgTex(3, 7);
	cout << "New color" << endl;
}

//void SetColorBgTex(int Bg, int Tex) {
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	Bg = Bg << 4 | Tex;
//	SetConsoleTextAttribute(hConsole, Bg);
//}
#include "default.h"
#include "menu.h"

ofstream file;
ifstream fin;

int index = 0;
user * users = new user[index];

void showUsers(user * items, int size)
{
	int length = 96;

	paintLine('-', length);
	cout << endl;
	cout
		<< "|" << setw(5) << "ID "
		<< "|" << setw(7) << "Books "
		<< "|" << setw(16) << "Name "
		<< "|" << setw(16) << "Surname "
		<< "|" << setw(16) << "Patronymic "
		<< "|" << setw(12) << "Birthday "
		<< "|" << setw(16) << "Passport ID "
		<< "|" << endl;

	paintLine('=', length);
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout
			<< "|" << setw(4) << items[i].id << " "
			<< "|" << setw(6) << items[i].hits << " "
			<< "|" << setw(15) << items[i].name << " "
			<< "|" << setw(15) << items[i].surname << " "
			<< "|" << setw(15) << items[i].patronymic << " "
			<< "|" << setw(11) << items[i].birthday << " "
			<< "|" << setw(15) << items[i].passport  << " "
			<< "|" << endl;
		paintLine('-', length);
		cout << endl;
	}

	system("pause");
}

void getUsers() 
{
	showUsers(users, index);
}

//void addUser(user item, bool save = 0)
//{
//	user * items = new user[index + 1];
//
//	for (int i = 0; i < index; i++)
//	{
//		items[i] = users[i];
//	}
//	items[index] = item;
//	index++;
//	my_realloc(users, index - 1, index);
//	memcpy(users, items, index);
//	cout << item.name << " " << item.surname << " added " << index << endl;
//	delete[] items;
//	if (save)
//	{
//		saveUsers();
//		cout << "Save users...";
//	}
//}

void addUser(user item, bool save)
{
	arReload(users, index, index + 1);
	users[index] = item;
	index++;
	cout << item.id << " " << item.name << " " << item.surname << " added" << endl;
	if (save)
		saveUsers();
	system("pause");
}

void deleteUser(int id)
{
	for (int i = 0; i < index; i++)
	{
		if (users[i].id == id)
		{
			elementDelete(users, index, i);
			index--;
			saveUsers();
			break;
		}
	}
}

void findUser(char object[16])
{
	int size = 0;
	bool reach = 0;
	user * items = new user[size];

	for (int i = 0; i < index; i++)
	{
		reach = 0;

		if (users[i].id == charToInt(object))
			reach = 1;
		if (strstr(users[i].name, object) != NULL)
			reach = 1;
		if (strstr(users[i].surname, object) != NULL)
			reach = 1;
		if (strstr(users[i].patronymic, object) != NULL)
			reach = 1;
		if (strstr(users[i].passport, object) != NULL)
			reach = 1;

		if (reach)
		{
			arReload(items, size, size + 1);
			items[size] = users[i];
			size++;
			continue;
		}
	}

	if (size > 0)
	{
		showUsers(items, size);
	}
	else
	{
		cout << "Users not found!" << endl;
		system("pause");
	}
}

void editUser(int id)
{
	char word[16] = {};
	for (int i = 0; i < index; i++)
	{
		if (users[i].id == id)
		{
			cout
				<< "Name - " << users[i].name << endl
				<< "Edit?:";
			cin.ignore();
			cin.getline(word, 16);
			if (strcmp(word, "") != 0)
				memcpy(users[i].name, word, 16);
			cout
				<< "Surname - " << users[i].surname << endl
				<< "Edit?:";
			cin.getline(word, 16);
			if (strcmp(word, "") != 0)
				memcpy(users[i].surname, word, 16);
			cout
				<< "Patronymic - " << users[i].patronymic << endl
				<< "Edit?:";
			cin.getline(word, 16);
			if (strcmp(word, "") != 0)
				memcpy(users[i].patronymic, word, 16);
			cout
				<< "Birthdey - " << users[i].birthday << endl
				<< "Edit?:";
			cin.getline(word, 16);
			if (strcmp(word, "") != 0)
				memcpy(users[i].birthday, word, 16);
			cout
				<< "Passport ID - " << users[i].passport << endl
				<< "Edit?:";
			cin.getline(word, 16);
			if (strcmp(word, "") != 0)
				memcpy(users[i].passport, word, 16);

			saveUsers();
			break;
		}
	}
}

void setUser(int id, user user)
{
	users[id] = user;
}

void saveUsers()
{
	file.open("users.csv");
	for (int i = 0; i < index; i++)
	{
		file
			<< users[i].id << ";" 
			<< users[i].hits << ";" 
			<< users[i].name << ";" 
			<< users[i].surname << ";"
			<< users[i].patronymic << ";" 
			<< users[i].birthday << ";" 
			<< users[i].passport << endl;
	}
	file.close();
	cout << "User save!" << endl;
}

void loadUsers()
{
	char path[10] = "users.csv";
	user item;
	char word[100] = {};
	char ch;
	int i = 0, // номер символа в строке
		j = 0, // номер символа в слове
		k = 0; // номер слова в строке

	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Error loading users" << endl;
	}
	else
	{
		cout << "Starting to load users" << endl;

		while (fin.get(ch))
		{
			i++;
			switch (ch)
			{
			case ';':
				j = 0;
				switch (k)
				{
				case 0:
					item.id = charToInt(word);
					break;
				case 1:
					item.hits = charToInt(word);
					break;
				case 2:
					memcpy(item.name, word, 16);
					break;
				case 3:
					memcpy(item.surname, word, 16);
					break;
				case 4:
					memcpy(item.patronymic, word, 16);
					break;
				case 5:
					memcpy(item.birthday, word, 20);
					break;
				case 6:
					memcpy(item.passport, word, 20);
					break;
				}
				memset(word, 0, strlen(word));
				k++;
				break;
			case '\n':
				i = 0;
				j = 0;
				switch (k)
				{
				case 0:
					item.id = charToInt(word);
					break;
				case 1:
					item.hits = charToInt(word);
					break;
				case 2:
					memcpy(item.name, word, 16);
					break;
				case 3:
					memcpy(item.surname, word, 16);
					break;
				case 4:
					memcpy(item.patronymic, word, 16);
					break;
				case 5:
					memcpy(item.birthday, word, 20);
					break;
				case 6:
					memcpy(item.passport, word, 20);
					break;
				}
				memset(word, 0, strlen(word));
				k = 0;
				addUser(item);
				break;
			default:
				word[j] = ch;
				j++;
				break;
			}
			
		}
		fin.close();
		cout << "Users successfully loaded" << endl;
	}
}

int getId()
{
	int i = 0;
	bool reach = 0;

	while (!reach)
	{
		for (int j = 0; j < index; j++)
		{
			if (users[j].id == i)
			{
				i++;
				reach = 1;
				break;
			}
		}
		if (reach)
		{
			reach = 0;
			continue;
		}
		else
			return i;
	}

}
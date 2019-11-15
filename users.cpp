#include "default.h"

ofstream file;
ifstream fin;

int index = 0;
user * users = new user[index];

//user users[1] = {};

void getClients() 
{
	for (int i = 0; i < index; i++)
	{
		cout
			<< users[i].name << " "
			<< users[i].surname << endl;
	}
}

void addUser(user item, bool save = 0)
{
	user * items = new user[index + 1];

	for (int i = 0; i < index; i++)
	{
		items[i] = users[i];
	}
	items[index] = item;
	index++;
	memcpy(users, items, index * sizeof(user));
	cout << item.name << " " << item.surname << " added" << endl;
	delete[] items;
	if(save)
		saveUsers();
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
			<< users[i].name << ";" << users[i].surname << endl;
	}
	file.close();
	cout << "End" << endl;
}

void loadUsers()
{
	char path[] = "users.csv";
	user item;
	user item2 = { "wasd", "qwert" };
	char word[100] = "";
	char ch;
	int i = 0, // номер символа в строке
		j = 0, // номер символа в слове
		k = 0; // номер слова в строке

	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Error loading users" << endl;
		//exit(0);
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
					memcpy(item.name, word, 100);
					break;
				case 1:
					memcpy(item.surname, word, 100);
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
					memcpy(item.name, word, 100);
					break;
				case 1:
					memcpy(item.surname, word, 100);
					break;
				}
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
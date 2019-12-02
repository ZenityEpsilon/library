struct user
{
	int id;
	int hits;
	char name[16];
	char surname[16];
	char patronymic[16];
	char birthday[20];
	char passport[20];
};

void getUsers();
void addUser(user item, bool save = false);
void saveUsers();
void loadUsers();
void deleteUser(int id);
void findUser(char object[16]);
void editUser(int id);
int getId();

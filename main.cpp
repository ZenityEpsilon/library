#include "default.h"
#include "menu.h"


void main() {
	bool end = 0;

	loadUsers();

	while (!end)
		end = menuMain();
}
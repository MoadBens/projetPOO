#include <iostream>
#include "sqlite3.h"
#include "Personnel.h"
#include "Materiel.h"
#include "Medicament.h"
#include "Stock.h"
#include "Admin.h"
#include "Technicien.h"
#include "Salle.h"
#include "SystemeAuthentification.h"
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	SystemeAuthentification* a = new SystemeAuthentification("hello");
	vector<Personnel*> users;
	users = a->FetchUsers();
	std::cout << users[0]->get_nom() << std::endl;
	return 0;
}


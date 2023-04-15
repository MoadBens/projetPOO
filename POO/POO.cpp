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
	Admin* ad = new Admin(1,"MOMO","MOMO","test");
	
	SystemeAuthentification* a = new SystemeAuthentification("hello");
	Admin* admin= new Admin(2,"Mohamed","ZAML","KHIKHI");
	admin->AjouterUtilisateur("SEGUIN", "SARA", 2, "97BA");
	admin->AjouterUtilisateur("Mohamed", "ZAML", 2, "97BA");
	admin->SupprimerUtilisateur("Mohamed","ZAML");
	vector<Personnel*> users;
	users = a->FetchUsers();
	std::cout << users[0]->get_nom() << std::endl;
	return 0;
}


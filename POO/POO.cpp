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
#include "Notif.h"
#include "observateur.h"
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	
	Admin* admin = Admin::getInstance();

	SystemeAuthentification* a = new SystemeAuthentification("hello");

	admin->AjouterUtilisateur("SEGUIN", "SARA", 2, "97BA");
	admin->SupprimerUtilisateur("Mohamed", "ZAML");
	vector<Personnel*> users;
	users = a->FetchUsers();
	Personnel* p1 = users[0];
	observateur* obs = new observateur(false,p1);
	Notif* noti1 = new Notif("TEST TEST");
	noti1->setobservateurs(obs);
	vector<observateur> observers = noti1->getobservateurs();
	//cout<< observers[0]. <<endl;
	return 0;
}


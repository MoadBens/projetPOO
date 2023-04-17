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
#include "Patient.h"
#include <vector>
#include "ChefBloc.h"
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	/*Admin* admin = Admin::getInstance();

	SystemeAuthentification* a = new SystemeAuthentification( );

	admin->AjouterUtilisateur("SEGUIN", "SARA", 2, "97BA");
	admin->SupprimerUtilisateur("Mohamed", "ZAML");
	vector<Personnel*> users;
	users = a->FetchUsers();
	Personnel* p1 = users[0];
	observateur* obs = new observateur(false,p1);
	Notif* noti1 = new Notif("TEST TEST");
	noti1->setobservateurs(obs);
	vector<observateur*> observers = noti1->getobservateurs();
	//cout<< observe
	rs[0]. <<endl;*/

	/*Salle* salle = new Salle(1);
	Patient* patient = new Patient(1, "Naima", "97ba");
	Operation* operation = new Operation({ "Mehdi", "Moad", "Mohamed" }, salle, std::chrono::system_clock::now(), 2, 13, patient, "No comment");
	ChefBloc* chef = new ChefBloc(1, "Moad", "Zaml", "sirT9wd");
	chef->CreerOperation(operation);*/
	//Stock* stock = new Stock(10, 20, 1);
	
	
	/*
	Materiel* materiel = new Materiel(10, 20, 1, 100, 5);
	vector<Materiel*> m;
	m = materiel->FetchMateriel();
	int a = m[0]->get_duree_de_garantie();
	int b = m[1]->get_duree_de_garantie();
	vector<int> s;
	s.push_back(b);
	s.push_back(a);
	std::cout << "Premier Duree de garantie du vecteur avant sort : " << s[0] << std::endl;
	std::cout << "Deuxieme Duree de garantie du vecteur avant sort : " << s[1] << std::endl;
	std::sort(s.begin(), s.end());
	std::cout << "Apres sort: ";
	for (auto element : s) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
	*/



	/*
	Medicament* medicament = new Medicament(10, 20, 1, "19/02/2022");
	medicament->AjouterMedicament(10, 20, 3, "19/02/2022");
	medicament->AjouterMedicament(10, 20, 1, "19/02/2022");
	medicament->AjouterMedicament(20, 30, 2, "21/03/2022");
	medicament->SupprimerMedicament(20, "21/03/2022");
	*/
	/*
	Materiel* materiel = new Materiel(40, 50, 3, 200, 6);
	materiel->AjouterMateriel(40, 50, 3, 200, 6);
	materiel->SupprimerMateriel(40, 200);
	materiel->ModifierMateriel(40, 200);
	*/
	return 0;
}


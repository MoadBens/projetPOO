#pragma once
#include <string>
#include "Personnel.h"
#include <vector>
#include "Medicament.h"
#include "Materiel.h"
#include "Operation.h"
#include "AlerteClass.h"

using namespace std;

class SystemeAuthentification
{
public :
	SystemeAuthentification();
	vector<Personnel*> FetchUsers();
	bool VerifierConnexion(std::string nom, std::string prenom, std::string mdp);
	Personnel* ActualUser(std::string nom,std::string prenom,std::string mdp);
	int getLevel(string nom, string prenom, string mdp);
	vector<Operation*> FetchOperations();
	vector<Medicament*> FetchMedicament();
	void AjouterMedicament(Medicament* m);
	void ModifierMedicament(string name,Medicament* medoc);
	void SupprimerMedicament(int Quantite, std::string date_expiration);
	vector<Materiel*> FetchMateriel();
	void AjouterMateriel(Materiel* mat);
	void ModifierMateriel(string name, Materiel* mat);
	void SupprimerMateriel(string name);
	void SendAlert(Personnel* p,string notif);
	vector<AlerteClass*> FetchAlerts();
	void SupprimerAlerte(string message,string destinateur);
};


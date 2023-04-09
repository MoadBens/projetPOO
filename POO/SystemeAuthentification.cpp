#include "SystemeAuthentification.h"
#include "sqlite3.h"
#include <iostream>

SystemeAuthentification::SystemeAuthentification(string bd) 
{
	bd_ = bd;
};

/*vector<Personnel> SystemeAuthentification::FetchUsers()
{

};*/
bool SystemeAuthentification::VerifierConnexion(Personnel* personne, string mdp)
{
	bool Verification = false;
	if (personne->get_mdp() == mdp) { Verification = true; }
	return Verification;
};


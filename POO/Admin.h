#pragma once
#include "Personnel.h"
class Admin : public Personnel
{
public:
	Admin(int ID, std::string nom, std::string prenom,std::string mdp);

	void AjouterUtilisateur(int ID, std::string nom, std::string prenom);
	void ModifierUtilisateur(Personnel* personnel);
	void SupprimerUtilisateur(Personnel* personnel);
private:


};
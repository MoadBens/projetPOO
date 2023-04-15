#pragma once
#include "Personnel.h"
class Admin : public Personnel
{
public:
	Admin(int ID, std::string nom, std::string prenom,std::string mdp);

	void AjouterUtilisateur(std::string nom, std::string prenom,int niveau,std::string mdp );
	void ModifierUtilisateur(std::string nom,std::string prenom);
	void SupprimerUtilisateur(std::string nom, std::string prenom);
private:


};
#pragma once
#include "Personnel.h"
class Admin : public Personnel
{
public:

	static Admin* getInstance();
	void setName(std::string name);
	std::string getName();
	void AjouterUtilisateur(std::string nom, std::string prenom,int niveau,std::string mdp );
	void ModifierUtilisateur(std::string nom,std::string prenom);
	void SupprimerUtilisateur(std::string nom, std::string prenom);
private:

	static Admin* instance;
	std::string name;

	Admin(std::string name);
	Admin(const Admin&) = delete;
	Admin& operator=(const Admin&) = delete;
	~Admin();
};
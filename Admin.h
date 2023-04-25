#pragma once
#include "Personnel.h"
class Admin : public Personnel
{
public:

	static Admin* getInstance();
	void setName(std::string nom);
	std::string getName();
	void AjouterUtilisateur(std::string nom, std::string prenom,int niveau,std::string mdp );
	void ModifierUtilisateur(std::string nom,std::string prenom,Personnel* p);
	void SupprimerUtilisateur(std::string nom, std::string prenom);
private:

	static Admin* instance;
	std::string nom_;
	std::string prenom_;
	std::string mdp_;

	Admin(std::string nom, std::string prenom, std::string mdp);
	Admin(const Admin&) = delete;
	Admin& operator=(const Admin&) = delete;
	~Admin();
};
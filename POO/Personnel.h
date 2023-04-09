#pragma once
#include <string>
class Personnel
{
public :
	Personnel();
	Personnel(int ID, std::string nom, std::string prenom,std::string mdp);
	int get_ID();
	std::string get_nom();
	std::string get_prenom();
	int get_niveau();
	std::string get_mdp();
	void set_ID(int ID);
	void set_nom(std::string nom);
	void set_prenom(std::string prenom);
	void set_niveau(int niveau);
	void set_mdp(std::string mdp);
private :
	int ID_;
	std::string nom_;
	std::string prenom_;
	int niveau_acces_;
	std::string mdp_;
};


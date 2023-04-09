#pragma once
#include <string>
class Personnel
{
public :
	Personnel(int ID, std::string nom, std::string prenom);
	int get_ID();
	std::string get_nom();
	std::string get_prenom();
	int get_niveau();
	void set_ID(int ID);
	void set_nom(string nom);
	void set_prenom(string prenom);
	void set_niveau(int niveau);
	
private :
	int ID_;
	std::string nom_;
	std::string prenom_;
	int niveau_acces_;
};


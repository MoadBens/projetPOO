#pragma once
#include <string>
class Personnel
{
public :
	Personnel(int ID, std::string nom, std::string prenom);
	
private :
	int ID_;
	std::string nom_;
	std::string prenom_;
	int niveau_acces_;
};


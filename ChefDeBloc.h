#pragma once
#include "Personnel.h"
#include "Operation.h"
#include "Salle.h"
class ChefDeBloc : public Personnel
{
public:
	ChefDeBloc(int ID, std::string nom, std::string prenom, std::string mdp,int niveau);

void CreerOperation(std::string salle, std::string date, int duree, std::string patient, std::string commentaire, std::string personnel);
private:


};

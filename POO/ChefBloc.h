#pragma once
#include "Personnel.h"
#include "Operation.h"
class ChefBloc : public Personnel
{
public:
	ChefBloc(int ID, std::string nom, std::string prenom, std::string mdp);

	Operation creerOperation(std::vector<std::string> listeEmploye, Salle* salle, std::chrono::system_clock::time_point date, float duree, float heureDebut, Patient* patient, std::string commentaire); // Déclaration de la fonction
	
private:


};
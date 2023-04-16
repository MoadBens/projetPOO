#pragma once
#include "Personnel.h"
#include "Operation.h"
#include "Salle.h"
class ChefBloc : public Personnel
{
public:
	ChefBloc(int ID, std::string nom, std::string prenom, std::string mdp);

	void CreerOperation(Operation* operation);
private:


};
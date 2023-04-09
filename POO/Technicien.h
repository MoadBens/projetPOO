#pragma once
#include "Personnel.h"
#include "Stock.h"
class Technicien : public Personnel
{
public:
	Technicien(int ID, std::string nom, std::string prenom,std::string mdp);

	void ModifierStock(Stock* Stock,int quantite);
	void AjouterItem(Stock* Stock,int quantite);
private:


};
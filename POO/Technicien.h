#pragma once
#include "Personnel.h"
#include "Stock.h"
class Technicien : public Personnel
{
public:
	Technicien(int ID, std::string nom, std::string prenom);

	void ModifierStock(Stock* Stock);
	void AjouterItem(Stock* Stock);
private:


};
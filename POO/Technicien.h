#pragma once
#include "Personnel.h"
class Technicien : public Personnel
{
public:
	Technicien(int ID, std::string nom, std::string prenom);

	void ModifierStock();
	void AjouterItem();
private:


};
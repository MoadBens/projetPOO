#pragma once
#include <string>
#include <vector>
#include "Medicament.h"
#include "Materiel.h"
class Stock
{
public:
	Stock();
	Stock(int quantite, std::string nom, int limite, int ID);
	vector<Medicament*> FetchMedoc();
	vector<Materiel*> FetchMateriel();
	int get_quantite();
	std::string get_nom();
	int get_limite();
	int get_ID();
	void set_quantite(int quantite);
	void set_nom(std::string nom);
	void set_limite(int limite);
	void set_ID(int ID);
private:
	int quantite_;
	std::string nom_;
	int limite_;
	int ID_;
};


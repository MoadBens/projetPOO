#pragma once
#include "Stock.h"
#include <string>
#include <chrono>

using namespace std;

class Materiel : public Stock
{
public:
	Materiel();
	Materiel(int quantite, std::string nom, int limite, int ID);
	string get_duree_de_vie();
	string get_duree_de_garantie();
	void set_duree_de_vie(string duree_de_vie);
	void set_duree_de_garantie(string duree_de_garantie);
private:
	string duree_de_vie_;
	string duree_de_garantie_;
	
};


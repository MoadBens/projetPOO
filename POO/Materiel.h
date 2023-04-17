#pragma once
#include "Stock.h"
#include <string>
#include <chrono>
#include <vector>
using namespace std;

class Materiel : public Stock
{
public:
	Materiel(int quantite, int limite, int ID, string duree_de_vie, string duree_de_garantie);
	vector<Materiel*> FetchMateriel();
	int get_quantite();
	int get_limite();
	int get_ID();
	string get_duree_de_vie();
	string get_duree_de_garantie();
	void set_quantite(int quantite);
	void set_limite(int limite);
	void set_ID(int ID);
	void set_duree_de_vie(string duree_de_vie);
	void set_duree_de_garantie(string duree_de_garantie);

private:
	string duree_de_vie_;
	string duree_de_garantie_;
};


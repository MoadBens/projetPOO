#pragma once
#include "Stock.h"
#include <string>
#include <chrono>
#include <vector>
using namespace std;

class Materiel : public Stock
{
public:
	Materiel(int quantite, int limite, int ID, int duree_de_vie, int duree_de_garantie);
	vector<Materiel*> FetchMateriel();
	void AjouterMateriel(int quantite, int limite, int ID, int duree_de_vie, int duree_de_garantie);
	void ModifierMateriel(int quantite, int duree_de_vie);
	void SupprimerMateriel(int quantite, int duree_de_vie);
	int get_quantite();
	int get_limite();
	int get_ID();
	int get_duree_de_vie();
	int get_duree_de_garantie();
	void set_quantite(int quantite);
	void set_limite(int limite);
	void set_ID(int ID);
	void set_duree_de_vie(int duree_de_vie);
	void set_duree_de_garantie(int duree_de_garantie);

private:
	int duree_de_vie_;
	int duree_de_garantie_;
};


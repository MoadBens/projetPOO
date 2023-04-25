#pragma once
#include "Stock.h"
#include <string>
#include <chrono>
#include <vector>
using namespace std;

class Materiel : public Stock
{
public:
	Materiel();
	Materiel(int ID,std::string name,int quantite, int limite, int duree_de_vie, int duree_de_garantie);
	vector<Materiel*> FetchMateriel();
	void AjouterMateriel(std::string name,int quantite, int limite, int ID, int duree_de_vie, int duree_de_garantie);
	void ModifierMateriel(int ID, int quantite, int duree_de_vie);
	void SupprimerMateriel(int ID);
	int get_quantite();
	int get_limite();
	int get_ID();
	int get_duree_de_vie();
	int get_duree_de_garantie();
	std::string get_name();
	void set_quantite(int quantite);
	void set_limite(int limite);
	void set_ID(int ID);
	void set_duree_de_vie(int duree_de_vie);
	void set_duree_de_garantie(int duree_de_garantie);
	void set_name(std::string name);

private:
	int duree_de_vie_;
	int duree_de_garantie_;
};

#pragma once
#include "Stock.h"
#include <string>
#include <chrono>
#include <vector>

using namespace std;

class Medicament : public Stock
{
public:
	Medicament(int ID,std::string name,int quantite, int limite, string date_expiration);
	Medicament();
	vector<Medicament*> FetchMateriel();
	void AjouterMedicament(int quantite, int limite, int ID, string date_expiration);
	void ModifierMedicament(int Quantite, std::string date_expiration);
	void SupprimerMedicament(int Quantite, std::string date_expiration);
	int get_quantite();
	int get_limite();
	int get_ID();
	std::string get_name();
	string get_date_expiration();
	void set_quantite(int quantite);
	void set_limite(int limite);
	void set_ID(int ID);
	void set_date_expiration(string date_expiration);
	void set_name(string name);

private:
	string date_expiration_;
};
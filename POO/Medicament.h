#pragma once
#include "Stock.h"
#include <string>
#include <chrono>
#include <vector>

using namespace std;

class Medicament: public Stock
{
public:
	Medicament(int quantite, int limite, int ID, string date_expiration);
	vector<Medicament*> FetchMateriel();
	int get_quantite();
	int get_limite();
	int get_ID();
	string get_date_expiration();
	void set_quantite(int quantite);
	void set_limite(int limite);
	void set_ID(int ID);
	void set_date_expiration(string date_expiration);

private:
	string date_expiration_;
};

#pragma once
#include "Stock.h"
#include <string>
#include <chrono>

using namespace std;

class Medicament: public Stock
{
public:
	Medicament();
	Medicament(int quantite, std::string nom, int limite, int ID);
	string get_date_expiration();
	void set_date_expiration(string date_expiration);
private:
	string date_expiration_;
};

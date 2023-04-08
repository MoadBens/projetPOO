#pragma once
#include "Stock.h"
#include <string>
#include <chrono>

using namespace std;

class Medicament: public Stock
{
public:
	Medicament(int quantite, int limite, int ID);


private:
	std::time_t date_expiration_;
};

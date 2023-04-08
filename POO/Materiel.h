#pragma once
#include "Stock.h"
#include <string>
#include <chrono>

using namespace std;

class Materiel : public Stock
{
public:
	Materiel(int quantite, int limite, int ID, std::time_t duree_de_vie, std::time_t duree_de_garantie);


private:
	std::time_t duree_de_vie_;
	std::time_t duree_de_garantie_;
};


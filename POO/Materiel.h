#pragma once
#include "Stock.h"
#include <string>

using namespace std;

class Materiel : public Stock
{
public:
	Materiel(int quantite, int limite, int ID);


private:
	string duree_de_vie_;
	string duree_de_garantie_;
};


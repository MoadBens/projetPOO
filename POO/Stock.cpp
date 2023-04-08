#include "Stock.h"


Stock::Stock(int quantite, int limite, int ID) 
{
	quantite_= quantite;
	limite_ = limite;
	ID_ = ID;
}
// GETTERS

int Stock::get_quantite() {
	return quantite_;
};
int Stock::get_limite() {
	return quantite_;
};
int Stock::get_ID() {
	return ID_;
};

// SETTERS

void Stock::set_quantite(int quantite) {
	quantite_ = quantite;
};
void Stock::set_limite(int limite) {
	limite_ = limite;
};
void Stock::set_ID(int ID) {
	ID_ = ID;
};
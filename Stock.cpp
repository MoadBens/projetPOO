#include "Stock.h"

//CONSTRUCTEUR
Stock::Stock() {}
Stock::Stock(int ID,std::string name,int quantite, int limite)
{
	quantite_ = quantite;
	limite_ = limite;
	ID_ = ID;
	nom_ = name;
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
std::string Stock::get_name() {
	return nom_;
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
void Stock::set_name(std::string name) {
	 nom_=name;
};
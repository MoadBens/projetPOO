#include "Medicament.h"
using namespace std;

Medicament::Medicament() {}
Medicament::Medicament(int quantite, string nom, int limite, int ID) : Stock(quantite, nom, limite, ID) {
    // initialisation des attributs spécifiques au technicien

}

string Medicament::get_date_expiration() {
	return date_expiration_;
};

void Medicament::set_date_expiration(string date_expiration) {
	date_expiration_ = date_expiration;
};
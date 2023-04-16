#include "Medicament.h"
using namespace std;

Medicament::Medicament(int quantite, int limite, int ID, string date_expiration) : Stock(quantite, limite, ID) {
    // initialisation des attributs spécifiques au technicien
    date_expiration_= date_expiration;
}

// GETTERS
int Medicament::get_quantite() {
    return Stock::get_quantite();
}
int Medicament::get_limite() {
    return Stock::get_limite();
}
int Medicament::get_ID() {
    return Stock::get_ID();
}
string Medicament::get_date_expiration() {
    return date_expiration_;
}

// SETTERS
void Medicament::set_quantite(int quantite) {
    Stock::set_quantite(quantite);
}
void Medicament::set_limite(int limite) {
    Stock::set_limite(limite);
}
void Medicament::set_ID(int ID) {
    Stock::set_ID(ID);
}
void Medicament::set_date_expiration(string date_expiration) {
    date_expiration_ = date_expiration;
}

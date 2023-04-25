#include "Medicament.h"
#include "sqlite3.h"
#include <iostream>
#include <algorithm> // Pour les algorithmes STL
#include <cstring> // Pour std::strcmp
using namespace std;

Medicament::Medicament(int ID,std::string name,int quantite, int limite, string date_expiration) : Stock(ID,name,quantite, limite) {
    // initialisation des attributs spécifiques au technicien
    date_expiration_ = date_expiration;
}
Medicament::Medicament() {}
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
string Medicament::get_name() { 
    return Stock::get_name(); }
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
void Medicament::set_name(string name) { 
    Stock::set_name(name); }

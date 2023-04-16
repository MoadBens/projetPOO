#include "Materiel.h"


Materiel::Materiel(int quantite, int limite, int ID, string duree_de_vie, string duree_de_garantie) : Stock(quantite, limite, ID) {
    // initialisation des attributs spécifiques au technicien
    duree_de_vie_ = duree_de_vie;
    duree_de_garantie_ = duree_de_garantie;

}

// GETTERS
int Materiel::get_quantite() {
    return Stock::get_quantite();
}
int Materiel::get_limite() {
    return Stock::get_limite();
}
int Materiel::get_ID() {
    return Stock::get_ID();
}
string Materiel::get_duree_de_vie() {
    return duree_de_vie_;
}

string Materiel::get_duree_de_garantie() {
    return duree_de_garantie_;
}

// SETTERS
void Materiel::set_quantite(int quantite) {
    Stock::set_quantite(quantite);
}
void Materiel::set_limite(int limite) {
    Stock::set_limite(limite);
}
void Materiel::set_ID(int ID) {
    Stock::set_ID(ID);
}
void Materiel::set_duree_de_vie(string duree_de_vie) {
    duree_de_vie_ = duree_de_vie;
}

void Materiel::set_duree_de_garantie(string duree_de_garantie) {
    duree_de_garantie_ = duree_de_garantie;
}

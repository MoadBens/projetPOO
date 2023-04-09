#include "Materiel.h"
using namespace std;

Materiel::Materiel() {}
Materiel::Materiel(int quantite, string nom, int limite, int ID) : Stock(quantite, nom, limite, ID) {
    // initialisation des attributs spécifiques au technicien
    

}

string Materiel::get_duree_de_vie() {
    return duree_de_vie_;
};

void Materiel::set_duree_de_vie(string duree_de_vie) {
    duree_de_vie_ = duree_de_vie;
};

string Materiel::get_duree_de_garantie() {
    return duree_de_garantie_;
};

void Materiel::set_duree_de_garantie(string duree_de_garantie) {
    duree_de_garantie_ = duree_de_garantie;
};
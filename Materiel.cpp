#include "Materiel.h"
#include "sqlite3.h"
#include <iostream>
#include <algorithm> // Pour les algorithmes STL
#include <cstring> // Pour std::strcmp
//CONSTRUCTEUR
Materiel::Materiel() {};
Materiel::Materiel(int ID,std::string name,int quantite, int limite, int duree_de_vie, int duree_de_garantie) : Stock(ID,name,quantite, limite) {
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
int Materiel::get_duree_de_vie() {
    return duree_de_vie_;
}
int Materiel::get_duree_de_garantie() {
    return duree_de_garantie_;
}
std::string Materiel::get_name() {
    return Stock::get_name(); }

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
void Materiel::set_duree_de_vie(int duree_de_vie) {
    duree_de_vie_ = duree_de_vie;
}
void Materiel::set_duree_de_garantie(int duree_de_garantie) {
    duree_de_garantie_ = duree_de_garantie;
}
void Materiel::set_name(std::string name) {
    Stock::set_name(name); }

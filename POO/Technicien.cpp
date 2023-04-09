#include "Technicien.h"

Technicien::Technicien(int ID, std::string nom, std::string prenom) : Personnel(ID, nom, prenom) {
    // initialisation des attributs spécifiques au technicien
}

void Technicien::ModifierStock(Stock* stock,int quantite) {
    // implémentation de la méthode ModifierStock
    stock->set_quantite(quantite);
}

void Technicien::AjouterItem(Stock* Stock,int quantite) {
    // implémentation de la méthode AjouterItem
}
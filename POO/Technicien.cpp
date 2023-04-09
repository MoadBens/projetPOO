#include "Technicien.h"

Technicien::Technicien(int ID, std::string nom, std::string prenom,std::string mdp) : Personnel(ID, nom, prenom,mdp) {
    // initialisation des attributs spécifiques au technicien
}

void Technicien::ModifierStock(Stock* stock,int quantite) {
    // implémentation de la méthode ModifierStock
    stock->set_quantite(quantite);
}

void Technicien::AjouterItem(Stock* Stock,int quantite) {
    // implémentation de la méthode AjouterItem
}
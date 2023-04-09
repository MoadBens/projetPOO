#include "Technicien.h"

Technicien::Technicien(int ID, std::string nom, std::string prenom) : Personnel(ID, nom, prenom) {
    // initialisation des attributs spécifiques au technicien
}

void Technicien::ModifierStock(Stock* Stock) {
    // implémentation de la méthode ModifierStock
}

void Technicien::AjouterItem(Stock* Stock) {
    // implémentation de la méthode AjouterItem
}
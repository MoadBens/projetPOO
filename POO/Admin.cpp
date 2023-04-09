#include "Admin.h"
#include "Technicien.h"

Admin::Admin(int ID, std::string nom, std::string prenom,std::string mdp) : Personnel(ID, nom, prenom,mdp) {
    // initialisation des attributs spécifiques au technicien
}

void Admin::AjouterUtilisateur(int ID, std::string nom, std::string prenom) {
    // implémentation de la méthode ModifierStock
}

void Admin::ModifierUtilisateur(Personnel* personne) {
    // implémentation de la méthode AjouterItem
}
void Admin::SupprimerUtilisateur(Personnel* personne) {
    // implémentation de la méthode AjouterItem
}
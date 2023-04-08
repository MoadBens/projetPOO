#include "Materiel.h"


Materiel::Materiel(int quantite, int limite, int ID, std::time_t duree_de_vie, std::time_t duree_de_garantie) : Stock(quantite, limite, ID) {
    // initialisation des attributs spécifiques au technicien
    duree_de_vie_ = duree_de_vie;
    duree_de_garantie_ = duree_de_garantie;

}
#include "ChefBloc.h"

ChefBloc::ChefBloc(int ID, std::string nom, std::string prenom, std::string mdp) : Personnel(ID, nom, prenom, mdp) {
    // initialisation des attributs spécifiques au chef de bloc
}

Operation ChefBloc::creerOperation(std::vector<std::string> listeEmploye, Salle* salle, std::chrono::system_clock::time_point date, float duree, float heureDebut, Patient* patient, std::string commentaire)
{
    return Operation(listeEmploye, salle, date, duree, heureDebut, patient, commentaire);
}



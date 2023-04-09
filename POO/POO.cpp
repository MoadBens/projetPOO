#include <iostream>
#include "Personnel.h"
#include "Operation.h"
#include "ChefBloc.h"
#include "Salle.h"
#include "Patient.h"
int main()
{
    std::string prenom = "Mehdi";
    std::string nom = "Yahyaoui";
    int ID = 1;
    std::vector<std::string> listeEmploye = { "Mehdi", "Moad" };
    int numSalle = 1;
    Salle* salle = new Salle(numSalle);
    std::chrono::system_clock::time_point date = std::chrono::system_clock::now();
    
    float duree = 2.5;
    float heureDebut = 10.0;
    Patient* patient = new Patient(1,nom,prenom);
    
    std::string commentaire = "commentaire";
    ChefBloc* Chefbloc1 = new ChefBloc(ID,nom,prenom);
    Operation operation = Chefbloc1->creerOperation(listeEmploye, salle, date, duree, heureDebut, patient, commentaire);
    
    
}

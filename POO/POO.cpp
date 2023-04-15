#include "sqlite3.h"
#include "Personnel.h"
#include "Materiel.h"
#include "Medicament.h"
#include "Patient.h"
#include "Stock.h"
#include "Admin.h"
#include "ChefBloc.h"
#include "Technicien.h"
#include "Salle.h"
#include "SystemeAuthentification.h"
#include <vector>
#include <iostream>

using namespace std;
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
    std::string mdp = "Moad";
    ChefBloc* Chefbloc1 = new ChefBloc(ID,nom,prenom,mdp);
    Operation operation = Chefbloc1->creerOperation(listeEmploye, salle, date, duree, heureDebut, patient, commentaire);
    
    
}



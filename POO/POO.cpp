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
    std::string mdp = "Moad";
    ChefBloc* Chefbloc1 = new ChefBloc(ID,nom,prenom,mdp);
    Operation operation = Chefbloc1->creerOperation(listeEmploye, salle, date, duree, heureDebut, patient, commentaire);
    
    
}

int main(int argc, char** argv)
{
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("example.db", &DB);
    string query = "SELECT * FROM Connexion;";

    cout << "STATE OF TABLE BEFORE INSERT" << endl;

    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    string sql("INSERT INTO Connexion VALUES(4, 'momo', 'GATES', 30, 'PALO ALTO');");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;

    cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
    return (0);
}


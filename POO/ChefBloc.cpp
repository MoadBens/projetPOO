#include "ChefBloc.h"
#include "Technicien.h"
#include "sqlite3.h"
#include "iostream"
//#include "Salle.h"
//#include "Operation.h"

ChefBloc::ChefBloc(int ID, std::string nom, std::string prenom, std::string mdp) : Personnel(ID, nom, prenom, mdp) {
    // initialisation des attributs spécifiques à l'administrateur
}

void ChefBloc::CreerOperation(Operation* operation) {
    //CONNEXION AU FICHIER DE LA BDD
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string sql = "INSERT INTO Operation (Salle, Duree, Heure, Patient) VALUES ('" + to_string(operation->getSalle()->get_num()) + "'," + to_string(operation->getDuree()) + ",'" + to_string(operation->getHeureDebut()) + "','" + operation->getPatient()->get_nom() + "')";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Error executing SQL statement: " << sqlite3_errmsg(db) << std::endl;
    }
    else {
        std::cout << "L'operation a été ajouté avec succès !" << std::endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
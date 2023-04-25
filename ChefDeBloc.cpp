#include "ChefDeBloc.h"
#include "Technicien.h"
#include "sqlite3.h"
#include "iostream"


ChefDeBloc::ChefDeBloc(int ID, std::string nom, std::string prenom, std::string mdp,int niveau) : Personnel(ID, nom, prenom, mdp,niveau) {
    // initialisation des attributs spécifiques à l'administrateur
}

void ChefDeBloc::CreerOperation(std::string salle, std::string date, int duree, std::string patient, std::string commentaire, std::string personnel) {
    //CONNEXION AU FICHIER DE LA BDD
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;

    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string sql = "INSERT INTO Operation (Salle, Date, Duree, Patient,Commentaire,Personnel) VALUES (\"" + salle + "\",\"" + 
        date+"\",\"" + std::to_string(duree)+"\",\""+patient+"\",\""+commentaire+"\",\""+personnel+"\")";

    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);

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
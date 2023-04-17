#include "SystemeAuthentification.h"
#include "sqlite3.h"
#include <iostream>
#include <algorithm> // Pour les algorithmes STL
#include <cstring> // Pour std::strcmp

SystemeAuthentification::SystemeAuthentification()
{

};

vector<Personnel*> SystemeAuthentification::FetchUsers()
{
    std::vector<Personnel> people;
    //CONNEXION AU FICHIER DE LA BDD
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, "SELECT * FROM Connexion", -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    }

    std::vector<Personnel*> personnel;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Personnel* p = new Personnel();
        p->set_ID(sqlite3_column_int(stmt, 0));
        p->set_nom(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        p->set_prenom(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        p->set_niveau(sqlite3_column_int(stmt, 3));
        p->set_mdp(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        personnel.push_back(p);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return personnel;
};

bool SystemeAuthentification::VerifierConnexion(std::string nom, std::string prenom, std::string mdp)
{
    bool Verification = false;
    std::vector<Personnel> people;
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string query = "SELECT * FROM Connexion WHERE NOM='" + nom + "' AND PRENOM='" + prenom + "' AND MDP='" + mdp + "'";
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    }

    Personnel* p = new Personnel();
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        p->set_ID(sqlite3_column_int(stmt, 0));
        std::cout << sqlite3_column_int(stmt, 0) << std::endl;
        p->set_nom(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        std::cout << sqlite3_column_int(stmt, 1) << std::endl;
        p->set_prenom(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        std::cout << sqlite3_column_int(stmt, 2) << std::endl;
        p->set_niveau(sqlite3_column_int(stmt, 3));
        std::cout << sqlite3_column_int(stmt, 3) << std::endl;
        p->set_mdp(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        std::cout << sqlite3_column_int(stmt, 4) << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    if (p->get_mdp().compare(mdp) == 0 && p->get_nom().compare(nom) == 0 && p->get_prenom().compare(prenom) == 0) {
        Verification = true;
    

        }

    return Verification;
};



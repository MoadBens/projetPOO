#include "Admin.h"
#include "Technicien.h"
#include "sqlite3.h"
#include "iostream"
#include "Admin.h"

Admin* Admin::instance = nullptr;

Admin::Admin(std::string nom, std::string prenom, std::string mdp) : nom_(nom),prenom_(prenom),mdp_(mdp) {} // constructor is defined here

Admin* Admin::getInstance() {
    if (!instance) {
        instance = new Admin("Admin","Admin","Admin");
    }
    return instance;
}

void Admin::setName(std::string nom) {
    this->nom_ = nom;
}

std::string Admin::getName() {
    return nom_;
}

void Admin::AjouterUtilisateur(std::string nom, std::string prenom, int niveau, std::string mdp) {
    //CONNEXION AU FICHIER DE LA BDD
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string sql = "INSERT INTO Connexion (NOM, PRENOM, NIVEAU, MDP) VALUES ('" + nom + "','" + prenom + "'," + std::to_string(niveau) + ",'" + mdp + "')";
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
    } else {
        std::cout << "Utilisateur ajoute avec succes !" << std::endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void Admin::ModifierUtilisateur(std::string nom,std::string prenom) {
    // implémentation de la méthode DeleteItem
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string sql = "UPDATE Connexion SET NOM='"+nom+"',PRENOM='"+prenom+"'WHERE NOM ='"+nom+"' AND PRENOM='"
        +prenom+"'";
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
        std::cout << "Utilisateur modifie avec succes !" << std::endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
void Admin::SupprimerUtilisateur(std::string nom,std::string prenom) {
    // implémentation de la méthode DeleteItem
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string sql = "DELETE FROM Connexion WHERE NOM ='" + nom + "' AND PRENOM='" + prenom + "'";
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
        std::cout << "Utilisateur supprime avec succès !" << std::endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

Admin::~Admin()
{
    // Destruction de l'instance unique
    delete instance;
    instance = nullptr;
}
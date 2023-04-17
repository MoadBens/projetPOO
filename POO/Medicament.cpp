#include "Medicament.h"
#include "sqlite3.h"
#include <iostream>
#include <algorithm> // Pour les algorithmes STL
#include <cstring> // Pour std::strcmp
using namespace std;

Medicament::Medicament(int quantite, int limite, int ID, string date_expiration) : Stock(quantite, limite, ID) {
    // initialisation des attributs spécifiques au technicien
    date_expiration_= date_expiration;
}

// GETTERS
int Medicament::get_quantite() {
    return Stock::get_quantite();
}
int Medicament::get_limite() {
    return Stock::get_limite();
}
int Medicament::get_ID() {
    return Stock::get_ID();
}
string Medicament::get_date_expiration() {
    return date_expiration_;
}

// SETTERS
void Medicament::set_quantite(int quantite) {
    Stock::set_quantite(quantite);
}
void Medicament::set_limite(int limite) {
    Stock::set_limite(limite);
}
void Medicament::set_ID(int ID) {
    Stock::set_ID(ID);
}
void Medicament::set_date_expiration(string date_expiration) {
    date_expiration_ = date_expiration;
}


vector<Medicament*> Medicament::FetchMateriel()
{
    std::vector<Medicament> medoc;
    //CONNEXION AU FICHIER DE LA BDD
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, "SELECT * FROM Medicament", -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    }

    std::vector<Medicament*> medicament;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Medicament* me = new Medicament(get_quantite(), get_limite(), get_ID(), get_date_expiration());

        me->set_ID(sqlite3_column_int(stmt, 0));
        me->set_limite(sqlite3_column_int(stmt, 1));
        me->set_quantite(sqlite3_column_int(stmt, 2));
        me->set_date_expiration(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        medicament.push_back(me);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return medicament;
};

void Medicament::AjouterMedicament(int quantite, int limite, int ID, string date_expiration) {
    //CONNEXION AU FICHIER DE LA BDD
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string sql = "INSERT INTO Medicament (ID, Limite, Quantite, DateExpiration) VALUES ('" + to_string(ID) + "','" + to_string(limite) + "'," + to_string(quantite) + ",'" + date_expiration + "')";
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
        std::cout << "Utilisateur ajoute avec succes !" << std::endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void Medicament::ModifierMedicament(int Quantite, std::string date_expiration) {
    // implémentation de la méthode DeleteItem
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string sql = "UPDATE Medicament SET Quantite='" + std::to_string(Quantite) + "',DateExpiration='" + date_expiration + "'WHERE Quantite ='" + std::to_string(Quantite) + "' AND DateExpiration='" + date_expiration + "'";
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

void Medicament::SupprimerMedicament(int Quantite, std::string date_expiration) {
    // implémentation de la méthode DeleteItem
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string sql = "DELETE FROM Medicament WHERE Quantite ='" + to_string(Quantite) + "' AND DateExpiration='" + date_expiration + "'";
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
        std::cout << "Utilisateur supprime avec succes !" << std::endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

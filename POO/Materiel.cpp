#include "Materiel.h"
#include "sqlite3.h"
#include <iostream>
#include <algorithm> // Pour les algorithmes STL
#include <cstring> // Pour std::strcmp

Materiel::Materiel(int quantite, int limite, int ID, int duree_de_vie, int duree_de_garantie) : Stock(quantite, limite, ID) {
    // initialisation des attributs spécifiques au technicien
    duree_de_vie_ = duree_de_vie;
    duree_de_garantie_ = duree_de_garantie;

}

// GETTERS
int Materiel::get_quantite() {
    return Stock::get_quantite();
}
int Materiel::get_limite() {
    return Stock::get_limite();
}
int Materiel::get_ID() {
    return Stock::get_ID();
}
int Materiel::get_duree_de_vie() {
    return duree_de_vie_;
}

int Materiel::get_duree_de_garantie() {
    return duree_de_garantie_;
}

// SETTERS
void Materiel::set_quantite(int quantite) {
    Stock::set_quantite(quantite);
}
void Materiel::set_limite(int limite) {
    Stock::set_limite(limite);
}
void Materiel::set_ID(int ID) {
    Stock::set_ID(ID);
}
void Materiel::set_duree_de_vie(int duree_de_vie) {
    duree_de_vie_ = duree_de_vie;
}

void Materiel::set_duree_de_garantie(int duree_de_garantie) {
    duree_de_garantie_ = duree_de_garantie;
}

vector<Materiel*> Materiel::FetchMateriel()
{
    std::vector<Materiel> matos;
    //CONNEXION AU FICHIER DE LA BDD
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, "SELECT * FROM Materiel", -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    }

    std::vector<Materiel*> materiel;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Materiel* m = new Materiel(get_quantite(), get_limite(), get_ID(), get_duree_de_vie(), get_duree_de_garantie());
        
        m->set_ID(sqlite3_column_int(stmt, 0));
        m->set_limite(sqlite3_column_int(stmt, 1));
        m->set_quantite(sqlite3_column_int(stmt, 2));
        m->set_duree_de_vie(sqlite3_column_int(stmt, 3));
        m->set_duree_de_garantie(sqlite3_column_int(stmt, 4));
        materiel.push_back(m);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return materiel;
};


void Materiel::AjouterMateriel(int quantite, int limite, int ID, int duree_de_vie, int duree_de_garantie) {
    //CONNEXION AU FICHIER DE LA BDD
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string sql = "INSERT INTO Materiel (ID, Limite, Quantite, duree_de_vie_, duree_de_garantie) VALUES ('" + std::to_string(ID) + "','" + std::to_string(limite) + "'," + std::to_string(quantite) + ",'" + std::to_string(duree_de_vie) + "','" + std::to_string(duree_de_garantie) + "')";
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

void Materiel::ModifierMateriel(int quantite, int duree_de_vie) {
    // implémentation de la méthode DeleteItem
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string sql = "UPDATE Materiel SET Quantite='" + to_string(quantite) + "',duree_de_vie_='" + to_string(duree_de_vie) + "'WHERE Quantite ='" + std::to_string(quantite) + "' AND duree_de_vie_='" + to_string(duree_de_vie) + "'";
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

void Materiel::SupprimerMateriel(int quantite, int duree_de_vie) {
    // implémentation de la méthode DeleteItem
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    //ENVOI DE LA REQUETE
    sqlite3_stmt* stmt;
    std::string sql = "DELETE FROM Materiel WHERE Quantite ='" + to_string(quantite) + "' AND duree_de_vie_='" + to_string(duree_de_vie) + "'";
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

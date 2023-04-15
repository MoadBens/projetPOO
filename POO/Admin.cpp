#include "Admin.h"
#include "Technicien.h"
#include "sqlite3.h"
#include "iostream"

Admin::Admin(int ID, std::string nom, std::string prenom,std::string mdp) : Personnel(ID, nom, prenom,mdp) {
    // initialisation des attributs spécifiques à l'administrateur
}

/*void Admin::AjouterUtilisateur(std::string nom, std::string prenom, int niveau, std::string mdp) {
	
	//CONNEXION AU FICHIER DE LA BDD
	sqlite3* db;
	int rc = sqlite3_open("example.db", &db);
	if (rc) {
		std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
	}

	//ENVOI DE LA REQUETE
	sqlite3_stmt* stmt;
	std::string sql = "INSERT INTO Connexion (ID, NOM, PRENOM, NIVEAU, MDP) VALUES (8,\""+nom+"\",\""+prenom+"\","+std::to_string(niveau)+",\""+mdp+"\");";
	std::cout <<sql.c_str() << std::endl;

	rc = sqlite3_prepare_v2(db,sql.c_str(), -1, &stmt, nullptr);
	if (rc != SQLITE_OK) {
		std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
	}
}*/
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
        std::cout << "L'utilisateur a été ajouté avec succès !" << std::endl;
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
        std::cout << "L'utilisateur a été ajouté avec succès !" << std::endl;
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
        std::cout << "L'utilisateur a été ajouté avec succès !" << std::endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
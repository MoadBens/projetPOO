#include "SystemeAuthentification.h"
#include "sqlite3.h"
#include <iostream>

SystemeAuthentification::SystemeAuthentification(string bd) 
{
	bd_ = bd;
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
bool SystemeAuthentification::VerifierConnexion(Personnel* personne, string mdp)
{
	bool Verification = false;
	if (personne->get_mdp() == mdp) { Verification = true; }
	return Verification;
};


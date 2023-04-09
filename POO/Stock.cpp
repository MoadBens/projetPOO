#include "Stock.h"
#include "sqlite3.h"
#include <iostream>
using namespace std;

Stock::Stock(int quantite, string nom, int limite, int ID)
{
	quantite_= quantite;
	nom_ = nom;
	limite_ = limite;
	ID_ = ID;
}
// GETTERS

int Stock::get_quantite() {
	return quantite_;
};
string Stock::get_nom() {
	return nom_;
};
int Stock::get_limite() {
	return quantite_;
};
int Stock::get_ID() {
	return ID_;
};

// SETTERS

void Stock::set_quantite(int quantite) {
	quantite_ = quantite;
};
void Stock::set_nom(string nom) {
	nom_ = nom;
};
void Stock::set_limite(int limite) {
	limite_ = limite;
};
void Stock::set_ID(int ID) {
	ID_ = ID;
};


vector<Medicament*> Stock::FetchMedoc()
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
		Medicament* m = new Medicament();
		m->set_ID(sqlite3_column_int(stmt, 0));
		m->set_nom(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		m->set_quantite(sqlite3_column_int(stmt, 2));
		m->set_limite(sqlite3_column_int(stmt, 3));
		m->set_date_expiration(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
		medicament.push_back(m);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return medicament;
};

vector<Materiel*> Stock::FetchMateriel()
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
		Materiel* ma = new Materiel();
		ma->set_ID(sqlite3_column_int(stmt, 0));
		ma->set_nom(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		ma->set_limite(sqlite3_column_int(stmt, 2));
		ma->set_quantite(sqlite3_column_int(stmt, 3));
		ma->set_duree_de_vie(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
		ma->set_duree_de_garantie(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		materiel.push_back(ma);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return materiel;
};
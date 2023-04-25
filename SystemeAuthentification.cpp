	#include "SystemeAuthentification.h"
	#include "sqlite3.h"
	#include <iostream>
	#include <algorithm>

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
	std::string query = "SELECT * FROM Connexion WHERE NOM='"+nom+"' AND PRENOM='"+prenom+"' AND MDP='"+mdp+"'";
	rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
	if (rc != SQLITE_OK) {
		std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
	}

	Personnel* p= new Personnel();
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		p->set_ID(sqlite3_column_int(stmt, 0));
		std::cout<< sqlite3_column_int(stmt, 0) <<std::endl;
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
	if (p->get_mdp() == mdp && p->get_nom() == nom && p->get_prenom() == prenom) { Verification = true; }
	return Verification;
};
vector<Operation*> SystemeAuthentification::FetchOperations() {
	//CONNEXION AU FICHIER DE LA BDD
	sqlite3* db;
	int rc = sqlite3_open("example.db", &db);
	if (rc) {
		std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
	}

	//ENVOI DE LA REQUETE
	sqlite3_stmt* stmt;
	rc = sqlite3_prepare_v2(db, "SELECT * FROM Operation", -1, &stmt, nullptr);
	if (rc != SQLITE_OK) {
		std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
	}

	std::vector<Operation*> ListeOp;
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		Operation* o = new Operation();
		o->set_ID(sqlite3_column_int(stmt, 0));
		o->set_Salle(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		o->set_Date(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		o->set_Duree(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		o->set_Patient(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
		o->set_Commentaire(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		o->set_ListeEmploye(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
		ListeOp.push_back(o);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return ListeOp;
}
Personnel* SystemeAuthentification::ActualUser(std::string nom,std::string prenom,std::string mdp) {
	vector<Personnel*> personnelList = FetchUsers();
	Personnel* target = new Personnel();
	auto it = std::find_if(personnelList.begin(), personnelList.end(),
		[nom, prenom, mdp](Personnel* p) {
			return p->get_nom() == nom && p->get_prenom() == prenom && p->get_mdp() == mdp;
		});

	if (it != personnelList.end()) {
		// Personnel with matching attributes was found
		Personnel* matchingPersonnel = *it;
		// Do something with the matching personnel
	}
	else {
		// Personnel with matching attributes was not found
	}

	return *it;
}
int SystemeAuthentification::getLevel(string nom,string prenom, string mdp) {
	vector<Personnel*> people = this->FetchUsers();
	int a = 0;
	for (int i = 0;i < people.size();i++) {
		if (people[i]->get_mdp()==mdp && people[i]->get_nom()==nom && people[i]->get_prenom()==prenom) {
			a = people[i]->get_niveau();
		}
	}
	return a;
}

vector<Medicament*> SystemeAuthentification::FetchMedicament()
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
		Medicament* me = new Medicament();

		me->set_ID(sqlite3_column_int(stmt, 0));
		me->set_limite(sqlite3_column_int(stmt, 1));
		me->set_quantite(sqlite3_column_int(stmt, 2));
		me->set_date_expiration(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		me->set_name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
		medicament.push_back(me);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return medicament;
};

void SystemeAuthentification::AjouterMedicament(Medicament* m) {
	//CONNEXION AU FICHIER DE LA BDD
	sqlite3* db;
	int rc = sqlite3_open("example.db", &db);
	if (rc) {
		std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
		return;
	}

	//ENVOI DE LA REQUETE
	sqlite3_stmt* stmt;
	std::string sql = "INSERT INTO Medicament (ID, Limite, Quantite, Date_expiration,Nom) VALUES (" 
		+ to_string(m->get_ID()) + "," + to_string(m->get_limite()) + "," + to_string(m->get_quantite()) +
		",'" + m->get_date_expiration()+"','"+m->get_name()+"')";
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

void SystemeAuthentification::ModifierMedicament(string name, Medicament* medoc) {
	// implémentation de la méthode ModifierMedicament
	sqlite3* db;
	int rc = sqlite3_open("example.db", &db);
	if (rc) {
		std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
		return;
	}

	//ENVOI DE LA REQUETE
	sqlite3_stmt* stmt;
	std::string sql = "UPDATE Medicament SET Quantite="+to_string(medoc->get_quantite())+
		", Limite = " + to_string(medoc->get_limite()) + ", Date_expiration = '"+
		medoc->get_date_expiration()+"' WHERE Nom = '"+name+"'";
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

void SystemeAuthentification::SupprimerMedicament(int Quantite, std::string date_expiration) {
	// implémentation de la méthode DeleteItem
	sqlite3* db;
	int rc = sqlite3_open("example.db", &db);
	if (rc) {
		std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
		return;
	}

	//ENVOI DE LA REQUETE
	sqlite3_stmt* stmt;
	std::string sql = "DELETE FROM Medicament WHERE Quantite ='" + to_string(Quantite) + "' AND Date_expiration='" + date_expiration + "'";
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

vector<Materiel*> SystemeAuthentification::FetchMateriel()
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
		Materiel* m = new Materiel();

		m->set_ID(sqlite3_column_int(stmt, 0));
		m->set_limite(sqlite3_column_int(stmt, 1));
		m->set_quantite(sqlite3_column_int(stmt, 2));
		m->set_duree_de_vie(sqlite3_column_int(stmt, 3));
		m->set_duree_de_garantie(sqlite3_column_int(stmt, 4));
		m->set_name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		materiel.push_back(m);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return materiel;
};

void SystemeAuthentification::AjouterMateriel(Materiel* m) {
	//CONNEXION AU FICHIER DE LA BDD
	sqlite3* db;
	int rc = sqlite3_open("example.db", &db);
	if (rc) {
		std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
		return;
	}

	//ENVOI DE LA REQUETE
	sqlite3_stmt* stmt;
	std::string sql = "INSERT INTO Materiel (ID, Limite, Quantite, duree_de_vie, duree_de_garantie, Nom) VALUES (" +
		to_string(m->get_ID()) + "," + to_string(m->get_limite()) + "," + to_string(m->get_quantite()) + ","
		+ to_string(m->get_duree_de_vie()) + "," + to_string(m->get_duree_de_garantie()) + ",'" + m->get_name() + "')";
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
		std::cout << "Matériel ajoute avec succes !" << std::endl;
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void SystemeAuthentification::ModifierMateriel(string name, Materiel* m) {
	// implémentation de la méthode DeleteItem
	sqlite3* db;
	int rc = sqlite3_open("example.db", &db);
	if (rc) {
		std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
		return;
	}

	//ENVOI DE LA REQUETE
	sqlite3_stmt* stmt;
	std::string sql = "UPDATE Materiel SET Quantite=" + to_string(m->get_quantite()) + ",duree_de_vie=" +
		to_string(m->get_duree_de_vie()) + ",duree_de_garantie=" + to_string(m->get_duree_de_vie()) + ",Limite=" + to_string(m->get_limite())+
		"WHERE Nom ='" + m->get_name() + "'";
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

void SystemeAuthentification::SupprimerMateriel(string name) {
	// implémentation de la méthode DeleteItem
	sqlite3* db;
	int rc = sqlite3_open("example.db", &db);
	if (rc) {
		std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
		return;
	}

	//ENVOI DE LA REQUETE
	sqlite3_stmt* stmt;
	std::string sql = "DELETE FROM Materiel WHERE Nom='"+name+"'";
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


void SystemeAuthentification::SendAlert(Personnel* p,string notif) {
	sqlite3* db;
	int rc = sqlite3_open("example.db", &db);
	if (rc) {
		std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
	}

	//ENVOI DE LA REQUETE
	sqlite3_stmt* stmt;
	std::string sql = "INSERT INTO Notif (Destinateur, Message) VALUES (\"" + p->get_nom()+" "+p->get_prenom() + "\", \"" + notif + "\")";
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
		std::cout << "Utilisateur supprime avec succes !" << std::endl;
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}
vector<AlerteClass*> SystemeAuthentification::FetchAlerts() {
	sqlite3* db;
	int rc = sqlite3_open("example.db", &db);
	if (rc) {
		std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
		
	}

	//ENVOI DE LA REQUETE
	sqlite3_stmt* stmt;
	vector<AlerteClass*> Alertes;
	std::string sql = "SELECT * FROM Notif";
	rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
	if (rc != SQLITE_OK) {
		std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		
	}
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		AlerteClass* alerte = new AlerteClass();

		alerte->set_desti(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		alerte->set_Message(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));

		Alertes.push_back(alerte);
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
	return Alertes;
}
void SystemeAuthentification::SupprimerAlerte(string message, string destinateur) {
	// implémentation de la méthode DeleteItem
	sqlite3* db;
	int rc = sqlite3_open("example.db", &db);
	if (rc) {
		std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
	}

	//ENVOI DE LA REQUETE
	sqlite3_stmt* stmt;
	std::string sql = "DELETE FROM Notif WHERE Destinateur=\"" + destinateur + "\" AND Message= \"" + message + "\"";
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
		std::cout << "Utilisateur supprime avec succes !" << std::endl;
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}
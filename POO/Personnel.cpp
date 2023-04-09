#include "Personnel.h"
#include<string>

using namespace std;

Personnel::Personnel(int ID, string nom, string prenom,string mdp)
{
	nom_ = nom;
	prenom_ = prenom;
	ID_ = ID;
	mdp_ = mdp;
}
int Personnel::get_ID() { return ID_; }
std::string Personnel::get_nom() { return nom_; }
std::string Personnel::get_prenom() { return prenom_; }
int Personnel::get_niveau() { return niveau_acces_; }
std::string Personnel::get_mdp() { return mdp_; };

void Personnel::set_ID(int ID) { ID_ = ID; }
void Personnel::set_nom(string nom) { nom_ = nom; }
void Personnel::set_prenom(string prenom) { prenom_ = prenom; }
void Personnel::set_niveau(int niveau) { niveau_acces_ = niveau; }
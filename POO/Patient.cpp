#include "Patient.h"
#include <string>
using namespace std;

Patient::Patient(int numero, string nom, string prenom) 
{
	numero_ = numero;
	nom_ = nom;
	prenom_ = prenom;
}
int Patient::get_num() { return numero_; }
std::string Patient::get_nom() { return nom_; }
std::string Patient::get_prenom() { return prenom_; }


void Patient::set_num(int num) { numero_ = num; }
void Patient::set_nom(string nom) { nom_ = nom; }
void Patient::set_prenom(string prenom) { prenom_ = prenom; }

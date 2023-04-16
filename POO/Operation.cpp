#include "Operation.h"
using namespace std;

Operation::Operation(std::vector<std::string> Liste_Employe, Salle* Salle, std::chrono::system_clock::time_point date, float Duree, float HeureDebut, Patient* Patient, std::string Commentaire)
{
	Liste_Employe_ = Liste_Employe;
	Salle_ = Salle;
	date_ = date;
	Duree_ = Duree;
	HeureDebut_ = HeureDebut;
	Patient_ = Patient;
	Commentaire_ = Commentaire;
}
Salle* Operation::getSalle() {
	return Salle_;
}
float Operation::getDuree() {
	return Duree_;
}
float Operation::getHeureDebut() {
	return HeureDebut_;
}
Patient* Operation::getPatient() {
	return Patient_;
}


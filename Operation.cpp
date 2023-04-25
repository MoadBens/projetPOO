#include "Operation.h"
#include "Personnel.h"
using namespace std;

Operation::Operation(std::string Liste_Employe, std::string Salle, std::string date, std::string Duree, std::string HeureDebut, std::string Patient, std::string Commentaire)
{
	Liste_Employe_ = Liste_Employe;
	Salle_ = Salle;
	date_ = date;
	Duree_ = Duree;
	HeureDebut_ = HeureDebut;
	Patient_ = Patient;
	Commentaire_ = Commentaire;
}
Operation::Operation() {}
// getters
std::string Operation::get_ListeEmploye() 
{
    return Liste_Employe_;
}

std::string Operation::get_Salle() 
{
    return Salle_;
}

std::string Operation::get_Date()
{
    return date_;
}

std::string Operation::get_Duree()
{
    return Duree_;
}

std::string Operation::get_HeureDebut()
{
    return HeureDebut_;
}

std::string Operation::get_Patient()
{
    return Patient_;
}

std::string Operation::get_Commentaire() 
{
    return Commentaire_;
}

// setters
/*void Operation::setListeEmploye(std::vector<Personnel*> Liste_Employe)
{
    Liste_Employe_ = Liste_Employe;
}*/

void Operation::set_Salle(std::string Salle)
{
    Salle_ = Salle;
}

void Operation::set_Date(std::string date)
{
    date_ = date;
}

void Operation::set_Duree(std::string Duree)
{
    Duree_ = Duree;
}

void Operation::set_HeureDebut(std::string HeureDebut)
{
    HeureDebut_ = HeureDebut;
}

void Operation::set_Patient(std::string Patient)
{
    Patient_ = Patient;
}

void Operation::set_Commentaire(std::string Commentaire)
{
    Commentaire_ = Commentaire;
}
void Operation::set_ID(int ID) { ID_ = ID; };
void Operation::set_ListeEmploye(std::string Liste_Employe) {
    Liste_Employe_ += Liste_Employe; };
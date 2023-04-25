#pragma once
#include "Salle.h"
#include "Patient.h"
#include <string>
#include <vector>
#include "Personnel.h"
class Operation
{
public:
	Operation(std::string Liste_Employe, std::string Salle, std::string date, std::string Duree, std::string HeureDebut, std::string Patient, std::string Commentaire);
    Operation();
    // getters
    std::string get_ListeEmploye() ;
    std::string get_Salle();
    std::string get_Date() ;
    std::string get_Duree() ;
    std::string get_HeureDebut() ;
    std::string get_Patient() ;
    std::string get_Commentaire() ;


    // setters
    void set_ListeEmploye(std::string Liste_Employe);
    void set_ID(int ID);
    void set_Salle(std::string Salle);
    void set_Date(std::string date);
    void set_Duree(std::string Duree);
    void set_HeureDebut(std::string HeureDebut);
    void set_Patient(std::string Patient);
    void set_Commentaire(std::string Commentaire);
private:
    int ID_;
	std::string Liste_Employe_;
	std::string Salle_;
	std::string date_;
    std::string Duree_;
    std::string HeureDebut_;
	std::string Patient_;
	std::string Commentaire_;
};



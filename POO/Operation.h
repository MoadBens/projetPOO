#pragma once
#include "Salle.h"
#include "Patient.h"
#include <string>
#include <vector>
#include <chrono>
class Operation
{
public:
	Operation(std::vector<std::string> Liste_Employe, Salle* Salle, std::chrono::system_clock::time_point date, float Duree, float HeureDebut, Patient* Patient, std::string Commentaire);

private:
	std::vector<std::string> Liste_Employe_;
	Salle* Salle_;
	std::chrono::system_clock::time_point date_;
	float Duree_;
	float HeureDebut_;
	Patient* Patient_;
	std::string Commentaire_;
};



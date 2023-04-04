#include "Patient.h"
#include <string>
using namespace std;

Patient::Patient(int numero, string nom, string prenom) 
{
	numero_ = numero;
	nom_ = nom;
	prenom_ = prenom;
}
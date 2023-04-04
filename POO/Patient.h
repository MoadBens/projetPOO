#pragma once
#include <string>
using namespace std;
class Patient
{
public:
	Patient(int numero, string nom, string prenom);
private:
	int numero_;
	string nom_;
	string prenom_;

};


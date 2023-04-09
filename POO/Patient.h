#pragma once
#include <string>
using namespace std;

class Patient
{
public:
	Patient(int numero, string nom, string prenom);
	int get_num();
	string get_nom();
	string get_prenom();
	void set_num(int num);
	void set_nom(string nom);
	void set_prenom(string prenom);
private:
	int numero_;
	string nom_;
	string prenom_;

};


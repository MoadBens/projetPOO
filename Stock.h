#pragma once
#include "iostream"
class Stock
{
public:
	Stock(int ID, std::string name,int quantite, int limite);
	Stock();
	int get_quantite();
	int get_limite();
	int get_ID();
	std::string get_name();
	void set_quantite(int quantite);
	void set_limite(int limite);
	void set_ID(int ID);
	void set_name(std::string name);
private:
	int quantite_;
	int limite_;
	int ID_;
	std::string nom_;
};
#pragma once
class Stock
{
public:
	Stock(int quantite,int limite,int ID);
	int get_quantite();
	int get_limite();
	int get_ID();
	void set_quantite(int quantite);
	void set_limite(int limite);
	void set_ID(int ID);
private:
	int quantite_;
	int limite_;
	int ID_;
};


#include "Salle.h"

Salle::Salle(int numero) 
{
	numero_ = numero;
}

int Salle::get_num() { return numero_; };
void Salle::set_num(int num) { numero_ = num; };
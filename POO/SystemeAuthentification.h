#pragma once
#include <string>
#include "Personnel.h"
#include <vector>

using namespace std;

class SystemeAuthentification
{
public :
	SystemeAuthentification(string bd);
	vector<Personnel*> FetchUsers();
	bool VerifierConnexion(Personnel* personne,string mdp);
private :
	string bd_;
};


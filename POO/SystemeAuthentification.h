#pragma once
#include <string>
#include "Personnel.h"
#include <vector>

using namespace std;

class SystemeAuthentification
{
public:
    SystemeAuthentification();
    vector<Personnel*> FetchUsers();
    bool VerifierConnexion(std::string nom, std::string prenom, std::string mdp);
    Personnel* ActualUser(std::string nom, std::string prenom, std::string mdp);

};


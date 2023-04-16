#pragma once
#include <iostream>
#include <vector>
#include "observateur.h"

class Notif
{
public :
	Notif(std::string message);
	std::string getMessage();
	std::vector<observateur*> getobservateurs();
	void setMessage(std::string message);
	void setobservateurs(observateur* observateur);
private :
	std::string message_;
	std::vector <observateur*> observateurs_;


};


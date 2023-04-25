#pragma once
#include <iostream>
#include <vector>
#include "Personnel.h"
class observateur
{
public:
	observateur(bool notification_,Personnel* personnel_);

	void mettreAJour();

	std::vector<std::string> getMessage();

	bool getNotification();

	Personnel* getPersonnel();
	

	void addMessage(std::string message);

	void setNotification(bool notification);
	

	void setPersonnel(Personnel* personnel);
	
private:

	std:: vector<std::string> messages_;
	bool notification_;
	Personnel* personnel_;

};


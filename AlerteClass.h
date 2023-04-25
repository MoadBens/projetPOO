#pragma once
#include "iostream"

class AlerteClass
{

public:
	AlerteClass();
	AlerteClass(std::string message, std::string destinateur);
	std::string get_Message();
	void set_Message(std::string message);
	std::string get_desti();
	void set_desti(std::string destinateur);
private:
	std::string message_;
	std::string destinateur_;
};


#include "Notif.h"

Notif::Notif(std::string message) { message_ = message; };
std::string Notif::getMessage()  {
	return message_;
};
std::vector<observateur*> Notif::getobservateurs()  {
	return observateurs_;
};
void  Notif::setMessage(std::string message)  {
	message_ = message;
};
void Notif::setobservateurs(observateur* observateur)  {
	observateurs_.push_back(observateur);
};
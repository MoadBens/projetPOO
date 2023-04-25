#include "observateur.h"

observateur::observateur(bool notif, Personnel* personnel) : notification_(notif), personnel_(personnel) {};
// Getters


std::vector<std::string> observateur::getMessage()  {
    return messages_;
}

bool observateur :: getNotification()  {
    return notification_;
}

Personnel* observateur:: getPersonnel()  {
    return personnel_;
}
// Setters


void observateur:: addMessage(std::string message) {
    messages_.push_back(message);
}

void observateur::setNotification(bool notification) {
    notification_ = notification;
}

void observateur::setPersonnel(Personnel* personnel) {
    personnel_ = personnel;
}
void observateur::mettreAJour() {
    notification_ = true;
}
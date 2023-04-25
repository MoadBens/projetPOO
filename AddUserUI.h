#pragma once

#include <QMainWindow>
#include "ui_AddUserUI.h"
#include "Admin.h"

class AddUserUI : public QMainWindow
{
	Q_OBJECT

public:
	AddUserUI(QWidget *parent = 0);
	~AddUserUI();
	void onClicked();
	void onClicked2();
	Personnel* ActualUser;
private:
	Ui::AddUserUIClass ui;
	Admin* admin;
	std::string nom;
	std::string prenom;
	std::string mdp;
	int niveau_acces;

};

#pragma once

#include <QMainWindow>
#include "ui_ModifierUserUI.h"
#include "SystemeAuthentification.h"
#include <vector>
#include "Admin.h"

class ModifierUserUI : public QMainWindow
{
	Q_OBJECT

public:
	ModifierUserUI(QWidget *parent = nullptr);
	~ModifierUserUI();
	vector<Personnel*> users;
	void onClicked();
	void update_list();
	void onListItemClicked();
	void onClicked2();
	Personnel* ActualUser;
private:
	Ui::ModifierUserUIClass ui;
	SystemeAuthentification* sys;
	Admin* admin;
	std::string nom;
	std::string prenom;
	std::string mdp;
	int niveau_acces;

};

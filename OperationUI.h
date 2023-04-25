#pragma once

#include <QMainWindow>
#include "ui_OperationUI.h"
#include "SystemeAuthentification.h"
#include "Personnel.h"
#include "ChefDeBloc.h"

class OperationUI : public QMainWindow
{
	Q_OBJECT

public:
	OperationUI(Personnel* user,QWidget *parent = nullptr);
	~OperationUI();
	void onClicked();
	void onClicked2();
	Personnel* ActualUser;
private:
	Ui::OperationUIClass ui;
	SystemeAuthentification* sys;
	ChefDeBloc* chef;
	std::string duree;
	std::string date;
	std::string patient;
	std::string commentaire;
	std::vector<Personnel*> users;
	std::vector<Personnel*> team;
	std::string salle;

};

#pragma once

#include <QMainWindow>
#include "ui_Alerte.h"
#include "AlerteClass.h"
#include <vector>
#include "SystemeAuthentification.h"

class Alerte : public QMainWindow
{
	Q_OBJECT

public:
	Alerte(Personnel* user,QWidget *parent = nullptr);
	~Alerte();
	int UserLevel_;
	std::vector<AlerteClass*> Alertes;
	SystemeAuthentification* sys;
	void Lire();
	void onClicked();
	Personnel* ActualUser;
private:
	Ui::AlerteClass ui;
};

#pragma once

#include <QMainWindow>
#include "ui_TechnicienUI.h"
#include "Technicien.h"
#include "ListeStockUI.h"
#include "ListeStockUI2.h"
#include "Alerte.h"

class TechnicienUI : public QMainWindow
{
	Q_OBJECT

public:
	TechnicienUI(Personnel* user, QWidget* parent = nullptr);
	~TechnicienUI();
	Personnel* ActualUser;
	void onClicked();
	void onClicked2();
	void onClicked3();
	void onClicked4();
private:
	Ui::TechnicienUIClass ui;
	ListeStockUI* interfaceListeStock;
	ListeStockUI2* interfaceListeStock2;
	Alerte* interfaceAlerte;

};

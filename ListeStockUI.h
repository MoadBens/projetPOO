#pragma once

#include <QMainWindow>
#include "ui_ListeStockUI.h"
#include "Personnel.h"
#include "Materiel.h"
#include "Medicament.h"
#include "SystemeAuthentification.h"
#include "AlerteClass.h"
class ListeStockUI : public QMainWindow
{
	Q_OBJECT

public:
	ListeStockUI(Personnel* user, QWidget* parent = nullptr);
	~ListeStockUI();
	Personnel* ActualUser;
	void onClicked();
	void onClicked2();
	void onClicked3();
	void onClicked4();
	void onClicked5();
	void onClicked6();
	int UserLevel_;
	vector<Medicament*> medicaments;
	vector<Medicament*> medoc();
	vector<AlerteClass*> Alertes;
private:
	Ui::ListeStockUIClass ui;
	SystemeAuthentification* sys;
	

};

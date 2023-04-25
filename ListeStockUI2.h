#pragma once

#include <QMainWindow>
#include "ui_ListeStockUI2.h"
#include "Personnel.h"
#include "Materiel.h"
#include "Medicament.h"
#include "SystemeAuthentification.h"
#include "AlerteClass.h"

class ListeStockUI2 : public QMainWindow
{
	Q_OBJECT

public:
	ListeStockUI2(Personnel* user,QWidget *parent = nullptr);
	~ListeStockUI2();
	Personnel* ActualUser;
	void onClicked();
	void onClicked2();
	void onClicked3();
	void onClicked4();
	void onClicked5();
	//void onClicked6();
	vector<Materiel*>materiel();
	int UserLevel_;
	SystemeAuthentification* sys;
	vector<Materiel*> materiels;
	vector<AlerteClass*> Alertes;
private:
	Ui::ListeStockUI2Class ui;
	
};

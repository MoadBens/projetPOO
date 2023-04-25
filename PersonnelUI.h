#pragma once

#include <QMainWindow>
#include "ui_PersonnelUI.h"
#include "Personnel.h"
#include "ListeStockUI.h"
#include "ListeStockUI2.h"
#include "ListeOpUI.h"

class PersonnelUI : public QMainWindow
{
	Q_OBJECT

public:
	PersonnelUI(Personnel* user,QWidget *parent = nullptr);
	~PersonnelUI();
	Personnel* ActualUser;
	int UserLevel_;
	void onClicked();
	void onClicked2();
	void onClicked3();
	void onClicked4();
	ListeStockUI* interfaceListeStock;
	ListeStockUI2* interfaceListeStock2;
	ListeOpUI* interfaceOP;
private:
	Ui::PersonnelUIClass ui;
};

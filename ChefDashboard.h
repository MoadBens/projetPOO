#pragma once

#include <QMainWindow>
#include "ui_ChefDashboard.h"
#include "OperationUI.h"
#include "ListeOpUI.h"
#include "ListeStockUI.h"

class ChefDashboard : public QMainWindow
{
	Q_OBJECT

public:
	ChefDashboard(Personnel* user,QWidget* parent = nullptr);
	~ChefDashboard();
	Personnel* ActualUser;
	int UserLevel;
	
private:
	Ui::ChefDashboardClass ui;
	OperationUI* interfaceOP;
	ListeStockUI* interfaceStock;
	ListeOpUI* interfaceListe;

	void onClicked();
	void onClicked2();
	void onClicked3();
	void onClicked4();
};

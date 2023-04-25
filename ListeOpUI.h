#pragma once

#include <QMainWindow>
#include "ui_ListeOpUI.h"
#include "SystemeAuthentification.h"
#include "Operation.h"
#include "ChefDeBloc.h"
#include <vector>

class ListeOpUI : public QMainWindow
{
	Q_OBJECT

public:
	ListeOpUI(Personnel* user,QWidget *parent = nullptr);
	~ListeOpUI();
	Personnel* ActualUser;
	void onClicked();
	void onClicked2();
private:
	Ui::ListeOpUIClass ui;
	std::vector<Operation*> operations;
	SystemeAuthentification* sys;
	ChefDeBloc* chef;


};

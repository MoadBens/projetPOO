#pragma once

#include <QMainWindow>
#include "ui_DeleteUserUI.h"
#include "SystemeAuthentification.h"
#include <vector>
#include "Admin.h"


class DeleteUserUI : public QMainWindow
{
	Q_OBJECT

public:
	DeleteUserUI(QWidget *parent = nullptr);
	~DeleteUserUI();
	void onClicked();
	void onClicked2();
	vector<Personnel*> users;
	Personnel* ActualUser;
private:
	Ui::DeleteUserUIClass ui;
	SystemeAuthentification* sys;
	Admin* admin;

};

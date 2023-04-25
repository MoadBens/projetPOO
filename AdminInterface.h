#pragma once

#include <QMainWindow>
#include "ui_AdminInterface.h"
#include "ModifierUserUI.h"
#include "DeleteUserUi.h"
#include "AddUserUI.h"


class AdminInterface : public QMainWindow
{
	Q_OBJECT

public:
	AdminInterface(Personnel* user, QWidget* parent = nullptr);
	void onClicked3();
	void onClicked4();
	void onClicked5();
	void onClicked6();
	~AdminInterface();
	Personnel* ActualUser;
private:
	Ui::AdminInterfaceClass ui;
	AddUserUI* interfaceAdd;
	ModifierUserUI* interfaceModify;
	DeleteUserUI* interfaceDelete;

};

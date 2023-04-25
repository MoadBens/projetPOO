#include "AdminInterface.h"
#include "DeleteUserUI.h"
#include "ModifierUserUI.h"
#include "AddUserUI.h"
#include "Admin.h"

AdminInterface::AdminInterface(Personnel* user,QWidget *parent)
	: QMainWindow(parent)
{
	ActualUser = user;
	ui.setupUi(this);
	Admin* admin = Admin::getInstance();
	QObject::connect(ui.pushButton_Modify, &QPushButton::clicked, this, &AdminInterface::onClicked3);
	QObject::connect(ui.pushButton_Add, &QPushButton::clicked, this, &AdminInterface::onClicked4);
	QObject::connect(ui.pushButton_Delete, &QPushButton::clicked, this, &AdminInterface::onClicked5);
	QObject::connect(ui.pushButton_4, &QPushButton::clicked, this, &AdminInterface::onClicked6);
	QPixmap pixmap("deco.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton_4->setIcon(ButtonIcon);
	ui.pushButton_4->setIconSize(pixmap.rect().size());
}
AddUserUI* interfaceAdd;
DeleteUserUI* interfaceDelete;
ModifierUserUI* interfaceModify;
void AdminInterface::onClicked3() {  //Access to Modify_user interface
	//hide();
	interfaceModify = new ModifierUserUI(this);
	interfaceModify->show();


}
void AdminInterface::onClicked4() {   //Access to Add_user interface
	//hide();
	interfaceAdd = new AddUserUI(this);
	interfaceAdd->show();
}
void AdminInterface::onClicked5() {   //Access to Delete_user interface
	//hide();
	interfaceDelete = new DeleteUserUI(this);
	interfaceDelete->show();
}
void AdminInterface::onClicked6() {   //Access to Delete_user interface
	close();
	QWidget* parent = this->parentWidget();
	parent->show();
}
AdminInterface::~AdminInterface() // delete the interface
{}

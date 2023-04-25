#include "PersonnelUI.h"


PersonnelUI::PersonnelUI(Personnel* user,QWidget *parent)
	: QMainWindow(parent)
{
	ActualUser = user;
	ui.setupUi(this);
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &PersonnelUI::onClicked);
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &PersonnelUI::onClicked2);
	QObject::connect(ui.pushButton_3, &QPushButton::clicked, this, &PersonnelUI::onClicked3);
	QObject::connect(ui.pushButton_4, &QPushButton::clicked, this, &PersonnelUI::onClicked4);
	QPixmap pixmap("deco.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton_4->setIcon(ButtonIcon);
	ui.pushButton_4->setIconSize(pixmap.rect().size());
}

PersonnelUI::~PersonnelUI()
{}

void PersonnelUI::onClicked() {
	interfaceOP = new ListeOpUI(ActualUser, this);
	interfaceOP->show();
}
void PersonnelUI::onClicked2() {
	interfaceListeStock2 = new ListeStockUI2(ActualUser, this);
	interfaceListeStock2->show();
}
void PersonnelUI::onClicked3() {
	interfaceListeStock = new ListeStockUI(ActualUser, this);
	interfaceListeStock->show();
}
void PersonnelUI::onClicked4() {
	close();
	QWidget* parent = this->parentWidget();
	parent->show();
}

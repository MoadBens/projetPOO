#include "TechnicienUI.h"
#include <QMessageBox>

TechnicienUI::TechnicienUI(Personnel* user, QWidget *parent)
	: QMainWindow(parent)
{
	ActualUser = user;
	ui.setupUi(this);
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &TechnicienUI::onClicked);
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &TechnicienUI::onClicked2);
	QObject::connect(ui.pushButton_3, &QPushButton::clicked, this, &TechnicienUI::onClicked3);
	QObject::connect(ui.pushButton_4, &QPushButton::clicked, this, &TechnicienUI::onClicked4);
	QPixmap pixmap("deco.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton_4->setIcon(ButtonIcon);
	ui.pushButton_4->setIconSize(pixmap.rect().size());
}

TechnicienUI::~TechnicienUI()
{}
//ACCEDER AU STOCK MATERIEL
void TechnicienUI::onClicked() {
	interfaceListeStock = new ListeStockUI(ActualUser,this);
	interfaceListeStock->show();
}
//ACCEDER AU STOCK MEDICAMENT
void TechnicienUI::onClicked2() {
	interfaceListeStock2 = new ListeStockUI2(ActualUser,this);
	interfaceListeStock2->show();
}
//ACCEDER AUX ALERTES
void TechnicienUI::onClicked3() {
	interfaceAlerte = new Alerte(ActualUser,this);
	interfaceAlerte->show();
}
void TechnicienUI::onClicked4() {
	hide();
	QWidget* parent = this->parentWidget();
	parent->show();
}
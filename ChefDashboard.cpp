#include "ChefDashboard.h"
#include "OperationUI.h"
#include "ListeOpUI.h"
#include "ListeStockUI.h"


ChefDashboard::ChefDashboard(Personnel* user,QWidget* parent)
	: QMainWindow(parent)
{
	ActualUser = user;
	ui.setupUi(this);
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &ChefDashboard::onClicked);
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &ChefDashboard::onClicked3);
	QObject::connect(ui.pushButton_3, &QPushButton::clicked, this, &ChefDashboard::onClicked2);
	QObject::connect(ui.pushButton_4, &QPushButton::clicked, this, &ChefDashboard::onClicked4);
	QPixmap pixmap("deco.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton_4->setIcon(ButtonIcon);
	ui.pushButton_4->setIconSize(pixmap.rect().size());
}

ChefDashboard::~ChefDashboard()
{}
void ChefDashboard::onClicked() {  // CREER OPERATION
	interfaceOP = new OperationUI(ActualUser,this);
	interfaceOP->show();

}
void ChefDashboard::onClicked2() { // VOIR LA LISTE DES OPERATIONS
	interfaceListe = new ListeOpUI(ActualUser,this);
	interfaceListe->show();

}
void ChefDashboard::onClicked3() { // VOIR LE STOCK
	interfaceStock = new ListeStockUI(ActualUser,this);
	interfaceStock->show();

}
void ChefDashboard::onClicked4() { // VOIR LE STOCK
	hide();
	QWidget* parent = this->parentWidget();
	parent->show();

}
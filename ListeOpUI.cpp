#include "ListeOpUI.h"
#include <QMessageBox>

ListeOpUI::ListeOpUI(Personnel* user,QWidget *parent)
	: QMainWindow(parent)
{
	ActualUser = user;
	ui.setupUi(this);
	sys = new SystemeAuthentification();
	chef = new ChefDeBloc(1,"chef","chef","chef",2);
	operations=sys->FetchOperations();
	ui.tableWidget->setRowCount(operations.size());
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &ListeOpUI::onClicked);
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &ListeOpUI::onClicked2);
	QPixmap pixmap("icon.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton->setIcon(ButtonIcon);
	ui.pushButton->setIconSize(pixmap.rect().size());

	QPixmap pixmap2("calendar.png");
	QIcon ButtonIcon2(pixmap2);
	ui.pushButton_2->setIcon(ButtonIcon2);
	ui.pushButton_2->setIconSize(pixmap2.rect().size());
	int columns = ui.tableWidget->columnCount();

	for (int row = 0; row < operations.size(); row++) {

		QString nom_salle = QString::fromStdString(operations[row]->get_Salle());
		QString patient = QString::fromStdString(operations[row]->get_Patient());
		QString date = QString::fromStdString(operations[row]->get_Date());
		QString duree = QString::fromStdString(operations[row]->get_Duree());
		QString commentaire = QString::fromStdString(operations[row]->get_Commentaire());
		QString personnel = QString::fromStdString(operations[row]->get_ListeEmploye()).trimmed();
		//QMessageBox::information(this, "1", QString::fromStdString(operations[row]->get_ListeEmploye()));

		std::vector<QString> list = {nom_salle,patient,date,duree,commentaire,personnel};
		for (int column = 0;column < columns; ++column) {
			ui.tableWidget->setItem(row,column, new QTableWidgetItem(QString(list[column])));
		}
	}

}

ListeOpUI::~ListeOpUI()
{}
void ListeOpUI::onClicked() {
	close();deleteLater();
}
void ListeOpUI::onClicked2() {
	ui.tableWidget->verticalHeader()->sectionClicked(2);
}
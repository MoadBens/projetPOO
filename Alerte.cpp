#include "Alerte.h"
#include <QMessageBox>

Alerte::Alerte(Personnel* user,QWidget* parent)
	: QMainWindow(parent)
{
	ActualUser = user;
	ui.setupUi(this);
	Alertes = sys->FetchAlerts();
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &Alerte::Lire);
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &Alerte::onClicked);
	QPixmap pixmap("icon.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton_2->setIcon(ButtonIcon);
	ui.pushButton_2->setIconSize(pixmap.rect().size());

	sys = new SystemeAuthentification();
	vector<AlerteClass*> Alertes = sys->FetchAlerts();
	//ON CHOISIT LE NOMBBRE DE LIGNES A PARTIR DE LA BDD
	ui.tableWidget->setRowCount(Alertes.size());
	//ON COMPTE LES COLONNES
	int columns = ui.tableWidget->columnCount();
	//ON REMPLIT LE TABLEAU

	for (int row = 0; row < Alertes.size(); ++row) {

		QString destinateur = QString::fromStdString(Alertes [row] ->get_desti());
		QString message = QString::fromStdString(Alertes[row]->get_Message());

		std::vector<QString> list = { destinateur,message };

		for (int column = 0;column < columns; ++column) {
			ui.tableWidget->setItem(row, column, new QTableWidgetItem(QString(list[column])));
		}
	}
}

Alerte::~Alerte()
{}

void Alerte::Lire() {
	Alertes = sys->FetchAlerts();
	QTableWidgetItem* item = ui.tableWidget->currentItem();
	if (item) {
		int row = item->row();
		ui.tableWidget->removeRow(row);
		sys->SupprimerAlerte(Alertes[row]->get_Message(),Alertes[row]->get_desti());
	}
	else {
		QMessageBox::information(this, "Erreur de suppression", "Vous n'avez séletionné aucune notification ! ");
	}
}
void Alerte::onClicked() {
	close();deleteLater();
}
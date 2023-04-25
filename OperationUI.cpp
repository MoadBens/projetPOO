#include "OperationUI.h"
#include "SystemeAuthentification.h"
#include <QMessageBox>

OperationUI::OperationUI(Personnel* user,QWidget *parent)
	: QMainWindow(parent)
{
	ActualUser = user;
	ui.setupUi(this);
	sys = new SystemeAuthentification();
	chef = new ChefDeBloc(ActualUser->get_ID(), ActualUser->get_nom(), ActualUser->get_prenom(), ActualUser->get_mdp(), ActualUser->get_niveau());
	ui.listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	QPixmap pixmap("icon.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton_2->setIcon(ButtonIcon);
	ui.pushButton_2->setIconSize(pixmap.rect().size());
	users = sys->FetchUsers();
	for (int i = 0; i < users.size(); i++) {
		if (users[i]->get_niveau()!=1) {
			std::string nom_complet = users[i]->get_nom() + " " + users[i]->get_prenom();
			ui.listWidget->addItem(QString::fromStdString(nom_complet));
		}
	}
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &OperationUI::onClicked);
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &OperationUI::onClicked2);

}

OperationUI::~OperationUI()
{}

void OperationUI::onClicked() {
	
	date = ui.dateTimeEdit->dateTime().toString("dd-MM-yy hh:mm").toStdString();
	duree = ui.comboBox_2->currentText().toStdString();
	patient = ui.comboBox->currentText().toStdString();
	salle= ui.comboBox_3->currentText().toStdString();
	commentaire = ui.lineEdit_4->text().toStdString();

	if (date.empty() || duree.empty() || patient.empty() || salle.empty() )
		{
			QMessageBox::information(this, "Erreur", "Veuillez remplir tous les champs afin de procéder à la création .");
		}
	else
	{
		std::string personnel;
		ui.listWidget->selectedItems();
		foreach(QListWidgetItem * item, ui.listWidget->selectedItems()) {
			int row = ui.listWidget->row(item);
			personnel += item->text().toStdString()+",";

		}
		chef->CreerOperation(salle, date, (duree[0] - '0'), patient, commentaire,personnel);
		QMessageBox::information(this, "Programmation d'opérations", "Votre opération a bien été programmée !");

	}
}
void OperationUI::onClicked2() {
	this->close();
	this->deleteLater();
}
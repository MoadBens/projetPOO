#include "ListeStockUI.h"
#include <QMessageBox>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>

bool compare_dates(Medicament* m1, Medicament* m2) {
	std::string dateString1 = m1->get_date_expiration();
	std::string dateString2 = m2->get_date_expiration();

	// parse the date strings of the two objects and convert them to time_t values
	std::istringstream iss1(dateString1);
	std::vector<std::string> tokens1;
	std::string token1;
	while (std::getline(iss1, token1, '/'))
	{
		tokens1.push_back(token1);
	}
	std::tm tm1 = { 0, 0, 0, std::stoi(tokens1[0]), std::stoi(tokens1[1]) - 1, std::stoi(tokens1[2]) - 1900 };
	std::time_t time1 = std::mktime(&tm1);

	std::istringstream iss2(dateString2);
	std::vector<std::string> tokens2;
	std::string token2;
	while (std::getline(iss2, token2, '/'))
	{
		tokens2.push_back(token2);
	}
	std::tm tm2 = { 0, 0, 0, std::stoi(tokens2[0]), std::stoi(tokens2[1]) - 1, std::stoi(tokens2[2]) - 1900 };
	std::time_t time2 = std::mktime(&tm2);

	// compare the time_t values to determine the order
	return time1 < time2;
}

ListeStockUI::ListeStockUI(Personnel* user, QWidget* parent)
	: QMainWindow(parent)
{	//INITIALIASTION DU NIVEAU ET DE L'UI
	ActualUser = user;
	ui.setupUi(this);
	//BOUTONS
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &ListeStockUI::onClicked);
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &ListeStockUI::onClicked2);
	QObject::connect(ui.pushButton_3, &QPushButton::clicked, this, &ListeStockUI::onClicked3);
	QObject::connect(ui.pushButton_4, &QPushButton::clicked, this, &ListeStockUI::onClicked4);
	QObject::connect(ui.pushButton_5, &QPushButton::clicked, this, &ListeStockUI::onClicked5);
	QObject::connect(ui.pushButton_6, &QPushButton::clicked, this, &ListeStockUI::onClicked6);
	//ICONE
	QPixmap pixmap("icon.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton_4->setIcon(ButtonIcon);
	ui.pushButton_4->setIconSize(pixmap.rect().size());
	/////////////////////////////////
	QPixmap pixmap2("calendar.png");
	QIcon ButtonIcon2(pixmap2);
	ui.pushButton_6->setIcon(ButtonIcon2);
	ui.pushButton_6->setIconSize(pixmap2.rect().size());
	//VERIFICATION DU NIVEAU D'ACCES
	if (ActualUser->get_niveau() != 1) {
		ui.pushButton->hide();
		ui.pushButton_2->hide();
		ui.pushButton_3->hide();
	}
	else { ui.pushButton_5->hide(); }
	//FETCH MEDOC
	sys = new SystemeAuthentification();
	vector<Medicament*> medicaments = sys->FetchMedicament();

	//ON CHOISIT LE NOMBBRE DE LIGNES A PARTIR DE LA BDD
	ui.tableWidget->setRowCount(medicaments.size());
	//ON COMPTE LES COLONNES
	int columns = ui.tableWidget->columnCount();
	//ON REMPLIT LE TABLEAU
	
	for (int row = 0; row < medicaments.size(); ++row) {

		QString limite = QString::fromStdString(to_string(medicaments[row]->get_limite()));
		QString quantite = QString::fromStdString(to_string(medicaments[row]->get_quantite()));
		QString date = QString::fromStdString(medicaments[row]->get_date_expiration());
		QString nom = QString::fromStdString(medicaments[row]->get_name());

		std::vector<QString> list = { nom,quantite,limite,date };
		
		for (int column = 0;column < columns; ++column) {
			ui.tableWidget->setItem(row, column, new QTableWidgetItem(QString(list[column])));
		}
	}
}

ListeStockUI::~ListeStockUI()
{}

//MODIFIER ITEM
void ListeStockUI::onClicked() {
	int a = sys->FetchMedicament().size();
	vector<Medicament*> medocs = medoc();
	for (int i = 0;i < medocs.size();i++) {
		if (i <= a - 1){

			sys->ModifierMedicament(medocs[i]->get_name(), medocs[i]);
		}
		else {
			sys->AjouterMedicament(medocs[i]);
		}

	}
	QMessageBox::information(this, "Mise à jour", "Votre base de données a été mise à jour !");
}  
//SUPPRIMER ITEM
void ListeStockUI::onClicked2() {
	medicaments = sys->FetchMedicament();
	QTableWidgetItem* item = ui.tableWidget->currentItem();
	if (item) {
		int row = item->row();
		ui.tableWidget->removeRow(row);
		sys->SupprimerMedicament(medicaments[row]->get_quantite(), medicaments[row]->get_date_expiration());
		QMessageBox::information(this, "Suppression", "Votre élément a été supprimé de la base de données ! ");
	}
	else {
		QMessageBox::information(this, "Erreur de suppression", "Vous n'avez séletionné aucun médicament ! ");
	}
}  
//AJOUTER ITEM
void ListeStockUI::onClicked3() {
	int row = ui.tableWidget->rowCount();
	ui.tableWidget->insertRow(row);
} 
//REVENIR EN ARRIERE
void ListeStockUI::onClicked4() { 
	close();deleteLater(); } 

//Envoyer alerte
void ListeStockUI::onClicked5() {
	medicaments = sys->FetchMedicament();
	QTableWidgetItem* item = ui.tableWidget->currentItem();
	
	if (item) {
		int row = item->row();
		std::string message = "L'utilisateur " + ActualUser->get_nom() + " " + ActualUser->get_prenom() + " vous a alerté sur le stock du médicament ' " + medicaments[row]->get_name() +
			"'. Veuillez le constuler dans les plus brefs délais !";
		std::string nom = "Personnel";
		std::string prenom = " A";
		sys->SendAlert(ActualUser, message);
		QMessageBox::information(this, "Envoi d'alerte", "Votre alerte a bien été envoyée !");
	}
	else {
		QMessageBox::information(this, "Erreur de suppression", "Vous n'avez séletionné aucun médicament ! ");
	}
}

void ListeStockUI::onClicked6() {
	medicaments = sys->FetchMedicament();
	std::sort(medicaments.begin(), medicaments.end(),compare_dates);
	ui.tableWidget->clearContents();
	for (int row = 0; row < medicaments.size(); ++row) {

		QString limite = QString::fromStdString(to_string(medicaments[row]->get_limite()));
		QString quantite = QString::fromStdString(to_string(medicaments[row]->get_quantite()));
		QString date = QString::fromStdString(medicaments[row]->get_date_expiration());
		QString nom = QString::fromStdString(medicaments[row]->get_name());

		std::vector<QString> list = { nom,quantite,limite,date };
		ui.tableWidget->setRowCount(medicaments.size());
		//ON COMPTE LES COLONNES
		int columns = ui.tableWidget->columnCount();
		for (int column = 0;column < columns; ++column) {
			ui.tableWidget->setItem(row, column, new QTableWidgetItem(QString(list[column])));
		}
	}
}

vector<Medicament*> ListeStockUI::medoc() {
	vector<Medicament*> medocs;
	int rows = ui.tableWidget->rowCount();
	int columns = ui.tableWidget->columnCount();
	for (int i = 0; i < rows;i++) {
		Medicament* m = new Medicament();
		QTableWidgetItem* nom = ui.tableWidget->item(i, 0);
		QTableWidgetItem* quantite  = ui.tableWidget->item(i, 1);
		QTableWidgetItem* limite  = ui.tableWidget->item(i, 2);
		QTableWidgetItem* date = ui.tableWidget->item(i, 3);
		m->set_ID(i);
		m->set_name(nom->text().toStdString());
		m->set_quantite(quantite->text().toInt());
		m->set_limite(limite->text().toInt());
		m->set_date_expiration(date->text().toStdString());
		medocs.push_back(m);
	}
	return medocs;
}



#include "ListeStockUI2.h"
#include "QMessageBox"

ListeStockUI2::ListeStockUI2(Personnel* user,QWidget *parent)
	: QMainWindow(parent)
{
	//INITIALIASTION DU NIVEAU ET DE L'UI
	ActualUser = user;
	ui.setupUi(this);
	//BOUTONS
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &ListeStockUI2::onClicked);
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &ListeStockUI2::onClicked2);
	QObject::connect(ui.pushButton_3, &QPushButton::clicked, this, &ListeStockUI2::onClicked3);
	QObject::connect(ui.pushButton_5, &QPushButton::clicked, this, &ListeStockUI2::onClicked5);
	QObject::connect(ui.pushButton_4, &QPushButton::clicked, this, &ListeStockUI2::onClicked4);
	//QObject::connect(ui.pushButton_4, &QPushButton::clicked, this, &ListeStockUI2::onClicked6);
	//ICONE
	QPixmap pixmap("icon.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton_4->setIcon(ButtonIcon);
	ui.pushButton_4->setIconSize(pixmap.rect().size());
	//VERIFICATION DU NIVEAU D'ACCES
	if (ActualUser->get_niveau() != 1) {
		ui.pushButton->hide();
		ui.pushButton_2->hide();
		ui.pushButton_3->hide();
	}
	else { ui.pushButton_5->hide(); }
	//FETCH MATERIEL
	sys = new SystemeAuthentification();
	vector<Materiel*> materiels = sys->FetchMateriel();
	//ON CHOISIT LE NOMBBRE DE LIGNES A PARTIR DE LA BDD
	ui.tableWidget->setRowCount(materiels.size());
	//ON COMPTE LES COLONNES
	int columns = ui.tableWidget->columnCount();
	//ON REMPLIT LE TABLEAU
	for (int row = 0; row < materiels.size(); ++row) {

		QString limite = QString::fromStdString(to_string(materiels[row]->get_limite()));
		QString quantite = QString::fromStdString(to_string(materiels[row]->get_quantite()));
		QString date_achat = QString::fromStdString(to_string(materiels[row]->get_duree_de_vie()));
		QString duree_garantie = QString::fromStdString(to_string(materiels[row]->get_duree_de_garantie()));
		QString nom = QString::fromStdString(materiels[row]->get_name());

		std::vector<QString> list = { nom,quantite,limite,date_achat,duree_garantie };

		for (int column = 0;column < columns; ++column) {
			ui.tableWidget->setItem(row, column, new QTableWidgetItem(QString(list[column])));
		}
	}
}

ListeStockUI2::~ListeStockUI2()
{}
//AJOUTER ITEM
void ListeStockUI2::onClicked3() {
	int row = ui.tableWidget->rowCount();
	ui.tableWidget->insertRow(row);
}
//SUPPRIMER ITEM
void ListeStockUI2::onClicked2() {
	materiels = sys->FetchMateriel();
	QTableWidgetItem* item = ui.tableWidget->currentItem();
	if (item) {
		int row = item->row();
		ui.tableWidget->removeRow(row);
		sys->SupprimerMateriel(materiels[row]->get_name());
		QMessageBox::information(this, "Suppression", "Votre matériel a été supprimé de la base de données ! ");
	}
	else {
		QMessageBox::information(this, "Erreur de suppression", "Vous n'avez séletionné aucun médicament ! ");
	}
}
//bouton retour
void ListeStockUI2::onClicked4() {
	close();deleteLater();
}
//MODIFIER ITEM
void ListeStockUI2::onClicked() {
	int a = sys->FetchMateriel().size();
	
	vector<Materiel*> mat = materiel();
	//QMessageBox::information(this, "Erreur de suppression", QString::number(mat.size()));
	for (int i = 0;i < mat.size();i++) {
		if (i <= a - 1) {

			sys->ModifierMateriel(mat[i]->get_name(), mat[i]);
		}
		else {
			/*QMessageBox::information(this, "name", QString::fromStdString(mat[i]->get_name()));
			QMessageBox::information(this, "ID", QString::fromStdString(to_string(mat[i]->get_ID())));
			QMessageBox::information(this, "limite", QString::fromStdString(to_string(mat[i]->get_limite())));
			QMessageBox::information(this, "quantite", QString::fromStdString(to_string(mat[i]->get_quantite())));
			QMessageBox::information(this, "duree vie", QString::fromStdString(to_string(mat[i]->get_duree_de_vie())));
			QMessageBox::information(this, "duree garantie", QString::fromStdString(to_string(mat[i]->get_duree_de_garantie())));*/
			sys->AjouterMateriel(mat[i]);
		}
	}
	QMessageBox::information(this, "Mise à jour", "Votre base de données a été mise à jour !");

}


//envoyer alerte
void ListeStockUI2::onClicked5() {
	materiels = sys->FetchMateriel();
	QTableWidgetItem* item = ui.tableWidget->currentItem();
	if (item) {
		int row = item->row();
		std::string message = "L'utilisateur "+ActualUser->get_nom() + " " + ActualUser->get_prenom()+ " vous a alerté sur le stock du matériel ' " + materiels[row]->get_name() +
			"'. Veuillez le constuler dans les plus brefs délais !";
		std::string nom = ActualUser->get_nom();
		std::string prenom = ActualUser->get_prenom();
		sys->SendAlert(ActualUser, message);
		QMessageBox::information(this, "Envoi d'alerte", "Votre alerte a bien été envoyée !");
	}
	else {
		QMessageBox::information(this, "Erreur de suppression", "Vous n'avez séletionné aucun médicament ! ");
	}
}

vector<Materiel*> ListeStockUI2::materiel() {
	vector<Materiel*> mat;
	int rows = ui.tableWidget->rowCount();
	int columns = ui.tableWidget->columnCount();
	for (int i = 0; i < rows;i++) {
		Materiel* m = new Materiel();
		QTableWidgetItem* nom = ui.tableWidget->item(i, 0);
		QTableWidgetItem* quantite = ui.tableWidget->item(i, 1);
		QTableWidgetItem* limite = ui.tableWidget->item(i, 2);
		QTableWidgetItem* date_achat = ui.tableWidget->item(i, 3);
		QTableWidgetItem* duree = ui.tableWidget->item(i, 4);
		m->set_ID(i+1);
		m->set_name(nom->text().toStdString());
		m->set_quantite(quantite->text().toInt());
		m->set_limite(limite->text().toInt());
		m->set_duree_de_vie(date_achat->text().toInt());
		m->set_duree_de_garantie(duree->text().toInt());
		mat.push_back(m);
	}
	return mat;
}
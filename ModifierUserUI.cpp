#include "ModifierUserUI.h"
#include <QMessageBox>

ModifierUserUI::ModifierUserUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	admin = Admin::getInstance();
	sys = new SystemeAuthentification();
	users = sys->FetchUsers();
	ui.lineEdit_3->setEchoMode(QLineEdit::Password);
	QPixmap pixmap("icon.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton_2->setIcon(ButtonIcon);
	ui.pushButton_2->setIconSize(pixmap.rect().size());
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &ModifierUserUI::onClicked);
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &ModifierUserUI::onClicked2);
	connect(ui.listWidget, &QListWidget::clicked, this, &ModifierUserUI::onListItemClicked);
	for (int i = 0; i < users.size(); i++) {
		std::string nom_complet = users[i]->get_nom() + " " + users[i]->get_prenom();
		ui.listWidget->addItem(QString::fromStdString(nom_complet));
	}
}

ModifierUserUI::~ModifierUserUI()
{}

void ModifierUserUI::onClicked() 
{
	//ENTREES DE L'ADMIN SUR CLAVIER
	nom = ui.lineEdit->text().toStdString();
	prenom = ui.lineEdit_2->text().toStdString();
	mdp = ui.lineEdit_3->text().toStdString();
	niveau_acces = ui.comboBox->currentIndex();
	QListWidgetItem* itm = ui.listWidget->currentItem();
	if (itm == nullptr) {
		QMessageBox::information(this, "Erreur de modification", "Vous n'avez séletionné aucun utilisateur ! ");
	}
	else {
		int currentIndex = ui.listWidget->currentRow();
		Personnel* p = users[currentIndex]; // PERSONNE IDENTIFIEE
		std::string nombdd = p->get_nom(); // ON RECUPERE SON NOM
		std::string prenombdd = p->get_prenom() ; // ON RECUPERE SON PRENOM

		if (!mdp.empty()) { p->set_mdp(mdp); }

		if (!std::to_string(niveau_acces).empty()) { p->set_niveau(niveau_acces); }

		if (!nom.empty()) {p->set_nom(nom);}

		if (!prenom.empty()) { p->set_prenom(prenom); }

		
		admin->ModifierUtilisateur(nombdd,prenombdd,p); 
		users[currentIndex] = p;
		update_list();
		QMessageBox::information(this, "Succès", "Votre utilisateur a été modifié avec succès");
	}
}

void ModifierUserUI::update_list() {	
	// VIDER LA LISTE
	ui.listWidget->clear();
	// REMPLIR LA LISTE
	for (int i = 0; i < users.size(); i++)
	{
		std::string nom_complet = users[i]->get_nom() + " " + users[i]->get_prenom();
		ui.listWidget->addItem(QString::fromStdString(nom_complet));
	}
}
void ModifierUserUI::onListItemClicked() {
	QListWidgetItem* itm = ui.listWidget->currentItem();
	int currentIndex = ui.listWidget->currentRow();
	Personnel* p = users[currentIndex];
	ui.lineEdit->setText(QString::fromStdString(p->get_nom()));  //nom
	ui.lineEdit_2->setText(QString::fromStdString(p->get_prenom()));
	ui.lineEdit_3->setText(QString::fromStdString(p->get_mdp()));//prenom
	ui.comboBox->setCurrentIndex(p->get_niveau());
	

}
void ModifierUserUI:: onClicked2() {
	this->close();
	this->deleteLater();
}
#include "AddUserUI.h"
#include <QMessageBox>

AddUserUI::AddUserUI(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	admin =Admin::getInstance();
	ui.lineEdit_3->setEchoMode(QLineEdit::Password);
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &AddUserUI::onClicked);
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &AddUserUI::onClicked2);
	QPixmap pixmap("icon.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton_2->setIcon(ButtonIcon);
	ui.pushButton_2->setIconSize(pixmap.rect().size());
}

AddUserUI::~AddUserUI()
{}

void AddUserUI::onClicked() {
	nom = ui.lineEdit->text().toStdString();
	prenom = ui.lineEdit_2->text().toStdString();
	mdp = ui.lineEdit_3->text().toStdString();
	niveau_acces = ui.comboBox->currentIndex();
	if (nom.empty() || prenom.empty() || mdp.empty())
	{
		QMessageBox::information(this, "Erreur", "Veuillez remplir tous les champs !");
	}
	else if (niveau_acces == 0)
	{
		QMessageBox::information(this, "Erreur", "Vous n'avez pas le droit de créer un nouvel administrateur !");
	}
	else {
		admin->AjouterUtilisateur(nom, prenom, niveau_acces, mdp); // nom,prenom,niveau,mdp
		QMessageBox::information(this, "Succès", "Votre utilisateur a été créé avec succès !");
	}

}
void AddUserUI::onClicked2() { 
	close();deleteLater(); }
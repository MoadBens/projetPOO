#include "DeleteUserUI.h"
#include <QMessageBox>


DeleteUserUI::DeleteUserUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	admin = Admin::getInstance();
	sys = new SystemeAuthentification();
	users = sys->FetchUsers();
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &DeleteUserUI::onClicked);
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &DeleteUserUI::onClicked2);
	QPixmap pixmap("icon.png");
	QIcon ButtonIcon(pixmap);
	ui.pushButton_2->setIcon(ButtonIcon);
	ui.pushButton_2->setIconSize(pixmap.rect().size());
	for (int i = 0; i < users.size(); i++) {
		std::string nom_complet = users[i]->get_nom() + " " + users[i]->get_prenom();
		ui.listWidget->addItem(QString::fromStdString(nom_complet));
	}
}

DeleteUserUI::~DeleteUserUI()
{}
void DeleteUserUI::onClicked() {
	QListWidgetItem* itm = ui.listWidget->currentItem();
	if (itm == nullptr) {
		QMessageBox::information(this, "Erreur de suppression", "Vous n'avez séletionné aucun utilisateur ! ");

	}
	else {
		int currentIndex = ui.listWidget->currentRow();
		Personnel* p = users[currentIndex];
		admin->SupprimerUtilisateur(p->get_nom(), p->get_prenom());  // nom,prenom
		delete users[currentIndex];
		itm->~QListWidgetItem();
		QMessageBox::information(this, "Suppression", "Votre utilisateur a été nettoyé de la base de données ! ");

	}
}
void DeleteUserUI::onClicked2() {
	close();
	deleteLater();
}
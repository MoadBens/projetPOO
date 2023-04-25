#include "test.h"
#include "SystemeAuthentification.h"
#include "Personnel.h"
#include <string>
#include <QMessageBox>
#include <QStackedWidget>
#include <QTimer>

test::test(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    sys = new SystemeAuthentification();
    vector<Personnel*> users;
    users = sys->FetchUsers();
    ui.lineEdit_3->setEchoMode(QLineEdit::Password);
    QObject::connect(ui.pushButton, &QPushButton::clicked, this, &test::onClicked);
    //QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &test::onClicked2);
    QWidget* widget = new QWidget();
    QObject::connect(ui.lineEdit_3, &QLineEdit::returnPressed, ui.pushButton, &QPushButton::click);
}
void test::onClicked()//bouton connexion
{
    nom = ui.lineEdit->text().toStdString();
    prenom = ui.lineEdit_2->text().toStdString();
    mdp = ui.lineEdit_3->text().toStdString();
    bool isSuccessfulConnexion = sys->VerifierConnexion(nom,prenom,mdp);
    std::string message ="Mot de passe : "+mdp;
    if (nom == "admin" && prenom == "admin" && mdp == "admin") {
        hide();
        interface2 = new AdminInterface(new Personnel(0, nom, prenom, mdp, 0),this);
        interface2->show();
    } //CONNEXION ADMIN
    else if (isSuccessfulConnexion && mdp !="") {

        int niveau = sys->getLevel(nom,prenom,mdp);
      //  QMessageBox::information(this, "Connexion", "Connexion réussie");
        ui.lineEdit_3->clear();
        ActualUser = sys->ActualUser(nom,prenom,mdp);
        ActualUser->set_niveau(niveau);
        UserLevel = niveau;
        if (ActualUser->get_niveau() == 1) {
            hide();
            interface3 = new TechnicienUI(ActualUser,this);
            interface3->ActualUser = ActualUser;
            interface3->show();
        }
        if (ActualUser->get_niveau() == 2) {
            hide();
            interface1 = new ChefDashboard(ActualUser,this);
            interface1->ActualUser = ActualUser;
            interface1->show();
        }

        if (ActualUser->get_niveau() == 3) {
            hide();
            interface4 = new PersonnelUI(ActualUser,this);
            interface4->ActualUser = ActualUser;
            interface4->show();
        }
    } // CONNEXION PERSONNEL/CHEF DE BLOC
    else {
        QMessageBox::information(this, "Connexion", "Connexion échouée");
    }//ECHEC CONNEXION
} 
void test::onClicked2()  //bouton switch
{
    hide();
    ActualUser = new Personnel();
    ActualUser->set_niveau(3);
    interface4 = new PersonnelUI(ActualUser,this);
    interface4->show();
}
test::~test()
{}

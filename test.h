#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test.h"
#include "SystemeAuthentification.h"
#include "ChefDashboard.h"
#include "AdminInterface.h"
#include "TechnicienUI.h"
#include "PersonnelUI.h"

class test : public QMainWindow
{
    Q_OBJECT

public:
    test(QWidget *parent = nullptr);
    ~test();
    void onClicked();
    void onClicked2();
    int UserLevel;
    Personnel* ActualUser;
private:
    Ui::testClass ui;
    SystemeAuthentification* sys;
    std::string nom;
    std::string prenom;
    std::string mdp;
    ChefDashboard* interface1;
    AdminInterface* interface2;
    TechnicienUI* interface3;
    PersonnelUI* interface4;


};

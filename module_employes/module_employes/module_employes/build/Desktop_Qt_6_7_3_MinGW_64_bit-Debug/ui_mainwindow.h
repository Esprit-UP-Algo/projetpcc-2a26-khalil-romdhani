/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *barre_nav;
    QPushButton *candidat_btn;
    QPushButton *vehicule_btn;
    QPushButton *pushButton_3;
    QPushButton *moniteur_btn;
    QPushButton *seance_btn;
    QPushButton *emp_btn;
    QPushButton *fermer_btn;
    QLabel *img;
    QFrame *frame_gest;
    QTabWidget *tab_widget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_9;
    QLineEdit *matricule;
    QLineEdit *marque;
    QLineEdit *modele;
    QLineEdit *annee;
    QLineEdit *km;
    QDateEdit *date_rev;
    QPushButton *pushButton;
    QPushButton *bon;
    QLabel *label;
    QPushButton *panne;
    QComboBox *type;
    QLineEdit *taper;
    QPushButton *conf_tab;
    QPushButton *entretien;
    QTableView *tab_vehicule;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QTabWidget *tab_widget2;
    QWidget *tab_3;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1312, 715);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        barre_nav = new QFrame(centralwidget);
        barre_nav->setObjectName("barre_nav");
        barre_nav->setGeometry(QRect(10, 20, 181, 641));
        barre_nav->setStyleSheet(QString::fromUtf8("#barre_nav {\n"
"    background-color: #0F2434;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"#candidat_btn,\n"
"#vehicule_btn,\n"
"#moniteur_btn,\n"
"#seance_btn,\n"
"#emp_btn,\n"
"#fermer_btn {\n"
"    color: #FBFAF5;\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    padding: 8px 15px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#candidat_btn:hover,\n"
"#vehicule_btn:hover,\n"
"#moniteur_btn:hover,\n"
"#seance_btn:hover,\n"
"#emp_btn:hover,\n"
"#fermer_btn:hover {\n"
"    color: #1D9E3A;\n"
"}\n"
""));
        barre_nav->setFrameShape(QFrame::Shape::StyledPanel);
        barre_nav->setFrameShadow(QFrame::Shadow::Raised);
        candidat_btn = new QPushButton(barre_nav);
        candidat_btn->setObjectName("candidat_btn");
        candidat_btn->setGeometry(QRect(0, 170, 181, 41));
        vehicule_btn = new QPushButton(barre_nav);
        vehicule_btn->setObjectName("vehicule_btn");
        vehicule_btn->setGeometry(QRect(0, 220, 181, 41));
        pushButton_3 = new QPushButton(barre_nav);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(180, 190, 161, 41));
        moniteur_btn = new QPushButton(barre_nav);
        moniteur_btn->setObjectName("moniteur_btn");
        moniteur_btn->setGeometry(QRect(0, 270, 191, 41));
        seance_btn = new QPushButton(barre_nav);
        seance_btn->setObjectName("seance_btn");
        seance_btn->setGeometry(QRect(10, 320, 171, 41));
        emp_btn = new QPushButton(barre_nav);
        emp_btn->setObjectName("emp_btn");
        emp_btn->setGeometry(QRect(0, 370, 191, 41));
        fermer_btn = new QPushButton(barre_nav);
        fermer_btn->setObjectName("fermer_btn");
        fermer_btn->setGeometry(QRect(10, 520, 161, 41));
        img = new QLabel(barre_nav);
        img->setObjectName("img");
        img->setGeometry(QRect(20, 80, 141, 20));
        frame_gest = new QFrame(centralwidget);
        frame_gest->setObjectName("frame_gest");
        frame_gest->setGeometry(QRect(200, 20, 1101, 641));
        frame_gest->setStyleSheet(QString::fromUtf8("#frame_gest {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
""));
        frame_gest->setFrameShape(QFrame::Shape::StyledPanel);
        frame_gest->setFrameShadow(QFrame::Shadow::Raised);
        tab_widget = new QTabWidget(frame_gest);
        tab_widget->setObjectName("tab_widget");
        tab_widget->setGeometry(QRect(10, 30, 1071, 581));
        tab_widget->setStyleSheet(QString::fromUtf8("#tab_widget {\n"
"    background-color: #FBFAF5;\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"#tab_widget::pane {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    background-color: #FBFAF5;\n"
"}\n"
"\n"
"#tab_widget QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px 20px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    margin-right: 2px;\n"
"}\n"
"\n"
"#tab_widget QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"}\n"
"\n"
"#tab_widget QTabBar::tab:hover {\n"
"    background-color: #30AA2C;\n"
"    color: #FBFAF5;\n"
"}\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 50, 301, 421));
        groupBox->setStyleSheet(QString::fromUtf8("#matricule,\n"
"#marque,\n"
"#modele,\n"
"#annee,\n"
"#km {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#matricule:focus,\n"
"#marque:focus,\n"
"#modele:focus,\n"
"#annee:focus,\n"
"#km:focus {\n"
"    border: 2px solid #1D9E3A; /* Pigment green on focus */\n"
"}\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 30, 71, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 80, 61, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 250, 61, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 140, 61, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 190, 81, 20));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 310, 121, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        matricule = new QLineEdit(groupBox);
        matricule->setObjectName("matricule");
        matricule->setGeometry(QRect(130, 30, 113, 31));
        matricule->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        marque = new QLineEdit(groupBox);
        marque->setObjectName("marque");
        marque->setGeometry(QRect(130, 80, 113, 31));
        marque->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        modele = new QLineEdit(groupBox);
        modele->setObjectName("modele");
        modele->setGeometry(QRect(130, 130, 113, 31));
        modele->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        annee = new QLineEdit(groupBox);
        annee->setObjectName("annee");
        annee->setGeometry(QRect(130, 190, 113, 31));
        annee->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        km = new QLineEdit(groupBox);
        km->setObjectName("km");
        km->setGeometry(QRect(130, 250, 113, 31));
        km->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        date_rev = new QDateEdit(groupBox);
        date_rev->setObjectName("date_rev");
        date_rev->setGeometry(QRect(130, 310, 121, 26));
        date_rev->setStyleSheet(QString::fromUtf8("#date_rev {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#date_rev:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#date_rev QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
""));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 370, 131, 29));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(29, 158, 58); /* couleur normale */\n"
"    color: white;                       /* couleur du texte */\n"
"    border: none;\n"
"    padding: 5px 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #239539; /* couleur quand le bouton est cliqu\303\251 */\n"
"}\n"
"\n"
""));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        pushButton->setIcon(icon);
        bon = new QPushButton(groupBox);
        bon->setObjectName("bon");
        bon->setGeometry(QRect(150, 370, 131, 29));
        bon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(29, 158, 58); /* couleur normale */\n"
"    color: white;                       /* couleur du texte */\n"
"    border: none;\n"
"    padding: 5px 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #239539; /* couleur quand le bouton est cliqu\303\251 */\n"
"}\n"
""));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        bon->setIcon(icon1);
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 161, 20));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        panne = new QPushButton(tab);
        panne->setObjectName("panne");
        panne->setGeometry(QRect(850, 480, 121, 29));
        panne->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(29, 158, 58); /* couleur normale */\n"
"    color: white;                       /* couleur du texte */\n"
"    border: none;\n"
"    padding: 5px 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #239539; /* couleur quand le bouton est cliqu\303\251 */\n"
"}\n"
""));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSend));
        panne->setIcon(icon2);
        type = new QComboBox(tab);
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName("type");
        type->setGeometry(QRect(405, 20, 81, 31));
        type->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"/* Effet focus (bordure verte) */\n"
"QComboBox:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"/* Zone du bouton de fl\303\250che */\n"
"QComboBox::drop-down {\n"
"    background-color: #FBFAF5;\n"
"    border-left: 1px solid #0F2434;\n"
"    width: 24px;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"}\n"
"\n"
"/* Fl\303\250che noire (dessin\303\251e par Qt) */\n"
"QComboBox::down-arrow {\n"
"    image: none; /* on laisse Qt dessiner la fl\303\250che par d\303\251faut */\n"
"    border: none;\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: center;\n"
"}\n"
"\n"
"/* Si tu veux forcer une fl\303\250che noire personnalis\303\251e (option) */\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/arrow-black.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"/* Men"
                        "u d\303\251roulant */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
""));
        taper = new QLineEdit(tab);
        taper->setObjectName("taper");
        taper->setGeometry(QRect(740, 20, 141, 31));
        taper->setStyleSheet(QString::fromUtf8("#taper {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#taper:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        conf_tab = new QPushButton(tab);
        conf_tab->setObjectName("conf_tab");
        conf_tab->setGeometry(QRect(890, 20, 131, 29));
        conf_tab->setStyleSheet(QString::fromUtf8("#conf_tab {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_tab:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#conf_tab:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        conf_tab->setIcon(icon3);
        entretien = new QPushButton(tab);
        entretien->setObjectName("entretien");
        entretien->setGeometry(QRect(450, 480, 121, 29));
        entretien->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(29, 158, 58); /* couleur normale */\n"
"    color: white;                       /* couleur du texte */\n"
"    border: none;\n"
"    padding: 5px 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #239539; /* couleur quand le bouton est cliqu\303\251 */\n"
"}\n"
""));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        entretien->setIcon(icon4);
        tab_vehicule = new QTableView(tab);
        tab_vehicule->setObjectName("tab_vehicule");
        tab_vehicule->setGeometry(QRect(320, 60, 701, 401));
        tab_vehicule->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(510, 20, 211, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(340, 480, 93, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(29, 158, 58); /* couleur normale */\n"
"    color: white;                       /* couleur du texte */\n"
"    border: none;\n"
"    padding: 5px 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #239539; /* couleur quand le bouton est cliqu\303\251 */\n"
"}\n"
""));
        tab_widget->addTab(tab, QString());
        groupBox->raise();
        label->raise();
        panne->raise();
        type->raise();
        taper->raise();
        conf_tab->raise();
        entretien->raise();
        label_7->raise();
        tab_vehicule->raise();
        pushButton_2->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tab_widget2 = new QTabWidget(tab_2);
        tab_widget2->setObjectName("tab_widget2");
        tab_widget2->setGeometry(QRect(10, 20, 1021, 471));
        tab_widget2->setStyleSheet(QString::fromUtf8("#tab_widget2 {\n"
"    background-color: #FBFAF5;\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"#tab_widget2::pane {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    background-color: #FBFAF5;\n"
"}\n"
"\n"
"#tab_widget2 QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px 20px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    margin-right: 2px;\n"
"}\n"
"\n"
"#tab_widget2 QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"}\n"
"\n"
"#tab_widget2 QTabBar::tab:hover {\n"
"    background-color: #30AA2C;\n"
"    color: #FBFAF5;\n"
"}\n"
""));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        label_8 = new QLabel(tab_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(90, 30, 621, 351));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/image/images/Statstiques.jpg")));
        tab_widget2->addTab(tab_3, QString());
        tab_widget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1312, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tab_widget->setCurrentIndex(0);
        tab_widget2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        candidat_btn->setText(QCoreApplication::translate("MainWindow", "Gestion des candidats", nullptr));
        vehicule_btn->setText(QCoreApplication::translate("MainWindow", "Gestion des v\303\251hicules", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Gestion des v\303\251hicules", nullptr));
        moniteur_btn->setText(QCoreApplication::translate("MainWindow", "Gestion des moniteurs", nullptr));
        seance_btn->setText(QCoreApplication::translate("MainWindow", "Gestion des s\303\251ances", nullptr));
        emp_btn->setText(QCoreApplication::translate("MainWindow", "Gestion des employ\303\251es", nullptr));
        fermer_btn->setText(QCoreApplication::translate("MainWindow", "Fermer", nullptr));
        img->setText(QCoreApplication::translate("MainWindow", "Logo", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Date d'embauche", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        bon->setText(QCoreApplication::translate("MainWindow", "R\303\251installer", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Gestion des employes", nullptr));
        panne->setText(QCoreApplication::translate("MainWindow", "Exporter", nullptr));
        type->setItemText(0, QCoreApplication::translate("MainWindow", "Trier", nullptr));
        type->setItemText(1, QCoreApplication::translate("MainWindow", "A", nullptr));
        type->setItemText(2, QCoreApplication::translate("MainWindow", "B", nullptr));
        type->setItemText(3, QCoreApplication::translate("MainWindow", "C", nullptr));
        type->setItemText(4, QCoreApplication::translate("MainWindow", "D", nullptr));
        type->setItemText(5, QCoreApplication::translate("MainWindow", "E", nullptr));
        type->setItemText(6, QCoreApplication::translate("MainWindow", "F", nullptr));
        type->setItemText(7, QCoreApplication::translate("MainWindow", "G", nullptr));
        type->setItemText(8, QCoreApplication::translate("MainWindow", "H", nullptr));
        type->setItemText(9, QCoreApplication::translate("MainWindow", "I", nullptr));
        type->setItemText(10, QCoreApplication::translate("MainWindow", "J", nullptr));
        type->setItemText(11, QCoreApplication::translate("MainWindow", "K", nullptr));
        type->setItemText(12, QCoreApplication::translate("MainWindow", "L", nullptr));
        type->setItemText(13, QCoreApplication::translate("MainWindow", "M", nullptr));
        type->setItemText(14, QCoreApplication::translate("MainWindow", "N", nullptr));
        type->setItemText(15, QCoreApplication::translate("MainWindow", "O", nullptr));
        type->setItemText(16, QCoreApplication::translate("MainWindow", "P", nullptr));
        type->setItemText(17, QCoreApplication::translate("MainWindow", "Q", nullptr));
        type->setItemText(18, QCoreApplication::translate("MainWindow", "R", nullptr));
        type->setItemText(19, QCoreApplication::translate("MainWindow", "S", nullptr));
        type->setItemText(20, QCoreApplication::translate("MainWindow", "T", nullptr));
        type->setItemText(21, QCoreApplication::translate("MainWindow", "U", nullptr));
        type->setItemText(22, QCoreApplication::translate("MainWindow", "V", nullptr));
        type->setItemText(23, QCoreApplication::translate("MainWindow", "W", nullptr));
        type->setItemText(24, QCoreApplication::translate("MainWindow", "X", nullptr));
        type->setItemText(25, QCoreApplication::translate("MainWindow", "Y", nullptr));
        type->setItemText(26, QCoreApplication::translate("MainWindow", "Z", nullptr));

        taper->setPlaceholderText(QCoreApplication::translate("MainWindow", "Taper...", nullptr));
        conf_tab->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        entretien->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Rechercher par Identifiant/Nom", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        tab_widget->setTabText(tab_widget->indexOf(tab), QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        label_8->setText(QString());
        tab_widget2->setTabText(tab_widget2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        tab_widget->setTabText(tab_widget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Fonctionnalit\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

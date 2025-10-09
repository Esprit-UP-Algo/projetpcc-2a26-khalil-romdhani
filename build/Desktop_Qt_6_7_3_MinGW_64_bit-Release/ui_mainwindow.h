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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *barre_nav;
    QPushButton *fermer_btn;
    QPushButton *seance_btn;
    QPushButton *vehicule_btn;
    QPushButton *emp_btn;
    QPushButton *moniteur_btn;
    QPushButton *candidat_btn;
    QGroupBox *frame_gest;
    QTabWidget *tab_widget;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *ID;
    QLabel *label_2;
    QLineEdit *Nom;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *conf_ajout;
    QPushButton *conf_ajout2;
    QDateEdit *Datenaissance;
    QComboBox *Niveaupermis;
    QLineEdit *Prenom;
    QLineEdit *Adresse;
    QLineEdit *Telephone;
    QLineEdit *Email;
    QLineEdit *Progression;
    QLineEdit *taper;
    QComboBox *filtrer;
    QComboBox *trier;
    QTableWidget *tableWidget;
    QPushButton *modifier;
    QPushButton *ajouter;
    QPushButton *expo_tab;
    QPushButton *conf_tab;
    QPushButton *supp;
    QWidget *tab_2;
    QTabWidget *tab_widget2;
    QWidget *tab_3;
    QComboBox *selon;
    QWidget *tab_4;
    QGroupBox *groupBox;
    QLineEdit *ia_proposition;
    QLineEdit *ia_nomcandidat;
    QLabel *label_13;
    QLineEdit *ia_sonprogression;
    QLabel *label_12;
    QLabel *label_11;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1293, 918);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        barre_nav = new QGroupBox(centralwidget);
        barre_nav->setObjectName("barre_nav");
        barre_nav->setGeometry(QRect(10, 10, 200, 560));
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
        fermer_btn = new QPushButton(barre_nav);
        fermer_btn->setObjectName("fermer_btn");
        fermer_btn->setGeometry(QRect(23, 490, 150, 40));
        fermer_btn->setStyleSheet(QString::fromUtf8(""));
        seance_btn = new QPushButton(barre_nav);
        seance_btn->setObjectName("seance_btn");
        seance_btn->setGeometry(QRect(15, 360, 170, 40));
        seance_btn->setStyleSheet(QString::fromUtf8(""));
        vehicule_btn = new QPushButton(barre_nav);
        vehicule_btn->setObjectName("vehicule_btn");
        vehicule_btn->setGeometry(QRect(15, 310, 170, 40));
        vehicule_btn->setStyleSheet(QString::fromUtf8(""));
        emp_btn = new QPushButton(barre_nav);
        emp_btn->setObjectName("emp_btn");
        emp_btn->setGeometry(QRect(15, 260, 170, 40));
        emp_btn->setStyleSheet(QString::fromUtf8(""));
        moniteur_btn = new QPushButton(barre_nav);
        moniteur_btn->setObjectName("moniteur_btn");
        moniteur_btn->setGeometry(QRect(15, 180, 170, 40));
        moniteur_btn->setStyleSheet(QString::fromUtf8(""));
        candidat_btn = new QPushButton(barre_nav);
        candidat_btn->setObjectName("candidat_btn");
        candidat_btn->setGeometry(QRect(10, 120, 170, 40));
        candidat_btn->setStyleSheet(QString::fromUtf8(""));
        frame_gest = new QGroupBox(centralwidget);
        frame_gest->setObjectName("frame_gest");
        frame_gest->setGeometry(QRect(210, 10, 1050, 560));
        frame_gest->setStyleSheet(QString::fromUtf8("#frame_gest {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
""));
        tab_widget = new QTabWidget(frame_gest);
        tab_widget->setObjectName("tab_widget");
        tab_widget->setGeometry(QRect(10, 10, 1030, 540));
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
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 10, 300, 470));
        groupBox_2->setStyleSheet(QString::fromUtf8("#ID,\n"
"#Nom,\n"
"#Prenom,\n"
"#Date naissance,\n"
"#Telephone,\n"
"#Email,\n"
"#Niveau permis,\n"
"#Progression,\n"
"#Adresse {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#ID:focus,\n"
"#Nom:focus,\n"
"#Prenom:focus,\n"
"#Date naissance:focus,\n"
"#Telephone:focus,\n"
"#Email:focus,\n"
"#Niveau permis:focus,\n"
"#Progression:focus,\n"
"#Adresse:focus {\n"
"    border: 2px solid #1D9E3A; /* Pigment green on focus */\n"
"}\n"
""));
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 30, 30));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        ID = new QLineEdit(groupBox_2);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(120, 40, 113, 28));
        ID->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 40, 30));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        Nom = new QLineEdit(groupBox_2);
        Nom->setObjectName("Nom");
        Nom->setGeometry(QRect(120, 80, 113, 28));
        Nom->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 120, 60, 30));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 160, 110, 30));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 200, 60, 30));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 240, 100, 30));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 285, 100, 30));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 320, 110, 30));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 360, 100, 30));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        conf_ajout = new QPushButton(groupBox_2);
        conf_ajout->setObjectName("conf_ajout");
        conf_ajout->setGeometry(QRect(18, 420, 130, 40));
        conf_ajout->setStyleSheet(QString::fromUtf8("#conf_ajout {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_ajout:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#conf_ajout:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        conf_ajout->setIcon(icon);
        conf_ajout2 = new QPushButton(groupBox_2);
        conf_ajout2->setObjectName("conf_ajout2");
        conf_ajout2->setGeometry(QRect(163, 420, 130, 40));
        conf_ajout2->setStyleSheet(QString::fromUtf8("#conf_ajout2 {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_ajout2:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#conf_ajout2:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSaveAs));
        conf_ajout2->setIcon(icon1);
        Datenaissance = new QDateEdit(groupBox_2);
        Datenaissance->setObjectName("Datenaissance");
        Datenaissance->setGeometry(QRect(121, 154, 110, 40));
        Datenaissance->setStyleSheet(QString::fromUtf8(""));
        Niveaupermis = new QComboBox(groupBox_2);
        Niveaupermis->addItem(QString());
        Niveaupermis->addItem(QString());
        Niveaupermis->addItem(QString());
        Niveaupermis->addItem(QString());
        Niveaupermis->addItem(QString());
        Niveaupermis->setObjectName("Niveaupermis");
        Niveaupermis->setGeometry(QRect(130, 314, 100, 40));
        Niveaupermis->setStyleSheet(QString::fromUtf8(""));
        Prenom = new QLineEdit(groupBox_2);
        Prenom->setObjectName("Prenom");
        Prenom->setGeometry(QRect(120, 120, 113, 28));
        Prenom->setStyleSheet(QString::fromUtf8(""));
        Adresse = new QLineEdit(groupBox_2);
        Adresse->setObjectName("Adresse");
        Adresse->setGeometry(QRect(120, 200, 113, 28));
        Adresse->setStyleSheet(QString::fromUtf8(""));
        Telephone = new QLineEdit(groupBox_2);
        Telephone->setObjectName("Telephone");
        Telephone->setGeometry(QRect(120, 240, 113, 28));
        Telephone->setStyleSheet(QString::fromUtf8(""));
        Email = new QLineEdit(groupBox_2);
        Email->setObjectName("Email");
        Email->setGeometry(QRect(120, 280, 113, 28));
        Email->setStyleSheet(QString::fromUtf8(""));
        Progression = new QLineEdit(groupBox_2);
        Progression->setObjectName("Progression");
        Progression->setGeometry(QRect(120, 360, 113, 28));
        Progression->setStyleSheet(QString::fromUtf8(""));
        taper = new QLineEdit(tab);
        taper->setObjectName("taper");
        taper->setGeometry(QRect(370, 10, 190, 40));
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
        filtrer = new QComboBox(tab);
        filtrer->addItem(QString());
        filtrer->addItem(QString());
        filtrer->setObjectName("filtrer");
        filtrer->setGeometry(QRect(710, 8, 144, 40));
        filtrer->setStyleSheet(QString::fromUtf8("#filtrer {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"\n"
"#filtrer QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"	selection-color: rgb(0, 0, 0);\n"
"\n"
"}\n"
"\n"
"#filtrer:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        trier = new QComboBox(tab);
        trier->addItem(QString());
        trier->addItem(QString());
        trier->addItem(QString());
        trier->setObjectName("trier");
        trier->setGeometry(QRect(876, 10, 120, 40));
        trier->setStyleSheet(QString::fromUtf8("#trier {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#trier QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#trier:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (tableWidget->rowCount() < 9)
            tableWidget->setRowCount(9);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(330, 60, 640, 330));
        modifier = new QPushButton(tab);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(340, 450, 110, 30));
        modifier->setStyleSheet(QString::fromUtf8("#modifier {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#modifier:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#modifier:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        modifier->setIcon(icon2);
        ajouter = new QPushButton(tab);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(480, 450, 120, 30));
        ajouter->setStyleSheet(QString::fromUtf8("#ajouter {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#ajouter:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#ajouter:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        ajouter->setIcon(icon3);
        expo_tab = new QPushButton(tab);
        expo_tab->setObjectName("expo_tab");
        expo_tab->setGeometry(QRect(830, 450, 121, 29));
        expo_tab->setStyleSheet(QString::fromUtf8("#expo_tab {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#expo_tab:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#expo_tab:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSend));
        expo_tab->setIcon(icon4);
        conf_tab = new QPushButton(tab);
        conf_tab->setObjectName("conf_tab");
        conf_tab->setGeometry(QRect(570, 16, 131, 29));
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
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        conf_tab->setIcon(icon5);
        supp = new QPushButton(tab);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(670, 450, 121, 29));
        supp->setStyleSheet(QString::fromUtf8("#supp {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#supp:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#supp:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        supp->setIcon(icon6);
        tab_widget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tab_widget2 = new QTabWidget(tab_2);
        tab_widget2->setObjectName("tab_widget2");
        tab_widget2->setGeometry(QRect(10, 10, 990, 480));
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
        selon = new QComboBox(tab_3);
        selon->addItem(QString());
        selon->addItem(QString());
        selon->addItem(QString());
        selon->setObjectName("selon");
        selon->setGeometry(QRect(850, 20, 100, 40));
        selon->setStyleSheet(QString::fromUtf8(""));
        tab_widget2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 910, 390));
        groupBox->setStyleSheet(QString::fromUtf8("\n"
"#ia_nomcandidat,\n"
"#ia_sonprogression,\n"
"#ia_proposition {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"\n"
"#ia_nomcandidat:focus,\n"
"#ia_sonprogression:focus,\n"
"#ia_proposition:focus {\n"
"    border: 2px solid #1D9E3A; /* Pigment green on focus */\n"
"}\n"
""));
        ia_proposition = new QLineEdit(groupBox);
        ia_proposition->setObjectName("ia_proposition");
        ia_proposition->setGeometry(QRect(50, 110, 840, 270));
        ia_proposition->setStyleSheet(QString::fromUtf8(""));
        ia_nomcandidat = new QLineEdit(groupBox);
        ia_nomcandidat->setObjectName("ia_nomcandidat");
        ia_nomcandidat->setGeometry(QRect(180, 10, 113, 28));
        ia_nomcandidat->setStyleSheet(QString::fromUtf8(""));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(0, 80, 130, 30));
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        ia_sonprogression = new QLineEdit(groupBox);
        ia_sonprogression->setObjectName("ia_sonprogression");
        ia_sonprogression->setGeometry(QRect(180, 50, 113, 28));
        ia_sonprogression->setStyleSheet(QString::fromUtf8(""));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 40, 130, 30));
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 10, 130, 30));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"\n"
"    padding: 6px 0px;\n"
"	color: rgb(0, 0, 0);\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    color: #3498db;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    background-color: rgba(236, 240, 241, 0.1);\n"
"    border-radius: 8px;\n"
"}"));
        tab_widget2->addTab(tab_4, QString());
        tab_widget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tab_widget->setCurrentIndex(0);
        tab_widget2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        barre_nav->setTitle(QString());
        fermer_btn->setText(QCoreApplication::translate("MainWindow", "Fermer", nullptr));
        seance_btn->setText(QCoreApplication::translate("MainWindow", "Gestion S\303\251ances", nullptr));
        vehicule_btn->setText(QCoreApplication::translate("MainWindow", "Gestion V\303\251hicules", nullptr));
        emp_btn->setText(QCoreApplication::translate("MainWindow", "Gestion Employ\303\251s", nullptr));
        moniteur_btn->setText(QCoreApplication::translate("MainWindow", "Gestion Moniteurs ", nullptr));
        candidat_btn->setText(QCoreApplication::translate("MainWindow", "Gestion Candidats", nullptr));
        frame_gest->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Date naissance :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Adresse :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Email :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Niveau permis :", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Progression :", nullptr));
        conf_ajout->setText(QCoreApplication::translate("MainWindow", "Enregistrer ", nullptr));
        conf_ajout2->setText(QCoreApplication::translate("MainWindow", "Enregistrer ", nullptr));
        Niveaupermis->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir", nullptr));
        Niveaupermis->setItemText(1, QCoreApplication::translate("MainWindow", "A", nullptr));
        Niveaupermis->setItemText(2, QCoreApplication::translate("MainWindow", "B", nullptr));
        Niveaupermis->setItemText(3, QCoreApplication::translate("MainWindow", "C", nullptr));
        Niveaupermis->setItemText(4, QCoreApplication::translate("MainWindow", "D", nullptr));

        taper->setInputMask(QString());
        taper->setPlaceholderText(QCoreApplication::translate("MainWindow", "  Recherche", nullptr));
        filtrer->setItemText(0, QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        filtrer->setItemText(1, QCoreApplication::translate("MainWindow", "ID", nullptr));

        trier->setItemText(0, QCoreApplication::translate("MainWindow", "Trier", nullptr));
        trier->setItemText(1, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        trier->setItemText(2, QCoreApplication::translate("MainWindow", "Date naissance", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Date naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Niveau permis", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Progression", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        expo_tab->setText(QCoreApplication::translate("MainWindow", "Exporter", nullptr));
        conf_tab->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        supp->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tab_widget->setTabText(tab_widget->indexOf(tab), QCoreApplication::translate("MainWindow", "Ajout Candidats", nullptr));
        selon->setItemText(0, QCoreApplication::translate("MainWindow", "Selon", nullptr));
        selon->setItemText(1, QCoreApplication::translate("MainWindow", "Age", nullptr));
        selon->setItemText(2, QCoreApplication::translate("MainWindow", "Nivaeu permis", nullptr));

        tab_widget2->setTabText(tab_widget2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        groupBox->setTitle(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Les proposition :", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Son progression :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Nom de candidat :", nullptr));
        tab_widget2->setTabText(tab_widget2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "IA", nullptr));
        tab_widget->setTabText(tab_widget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Fonctionnalit\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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

class Ui_MainWindowC
{
public:
    QWidget *centralwidget;
    QGroupBox *frame_gest;
    QTabWidget *tab_widget_c;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *id_c;
    QLabel *label_2;
    QLineEdit *nom_c;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *enregistrer_c;
    QDateEdit *dateN_c;
    QComboBox *nvpermis_c;
    QLineEdit *prenom_c;
    QLineEdit *adr_c;
    QLineEdit *tel_c;
    QLineEdit *email_c;
    QLineEdit *prog_c;
    QLineEdit *taper_c;
    QComboBox *filtrer_c;
    QComboBox *trier_c;
    QTableWidget *tableWidget;
    QPushButton *modifier_c;
    QPushButton *ajouter_c;
    QPushButton *expo_tab_c;
    QPushButton *conf_rech_c;
    QPushButton *supp_c;
    QWidget *tab_2;
    QTabWidget *tab_widget2_c;
    QWidget *tab_3;
    QComboBox *selon_stat_c;
    QWidget *tab_4;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *ia_nomcandidat;
    QLineEdit *ia_sonprogression;
    QLabel *label_13;
    QLineEdit *ia_proposition;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowC)
    {
        if (MainWindowC->objectName().isEmpty())
            MainWindowC->setObjectName("MainWindowC");
        MainWindowC->resize(1293, 918);
        MainWindowC->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindowC);
        centralwidget->setObjectName("centralwidget");
        frame_gest = new QGroupBox(centralwidget);
        frame_gest->setObjectName("frame_gest");
        frame_gest->setGeometry(QRect(39, 10, 1131, 611));
        frame_gest->setStyleSheet(QString::fromUtf8("#frame_gest {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
""));
        tab_widget_c = new QTabWidget(frame_gest);
        tab_widget_c->setObjectName("tab_widget_c");
        tab_widget_c->setGeometry(QRect(10, 10, 1101, 581));
        tab_widget_c->setStyleSheet(QString::fromUtf8("QTabWidget#tab_widget_c {\n"
"    background-color: #FBFAF5;\n"
"    border: 3px solid #0F2434;\n"
"    border-top: 5px solid #1E90FF;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_c::pane {\n"
"    border: 1px solid #0F2434;\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_c QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px 16px;\n"
"    margin: 2px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_c QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border-bottom: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_c QTabBar::tab:hover {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 20, 300, 470));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
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
        id_c = new QLineEdit(groupBox_2);
        id_c->setObjectName("id_c");
        id_c->setGeometry(QRect(120, 40, 113, 28));
        id_c->setStyleSheet(QString::fromUtf8("#id_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#id_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
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
        nom_c = new QLineEdit(groupBox_2);
        nom_c->setObjectName("nom_c");
        nom_c->setGeometry(QRect(120, 80, 113, 28));
        nom_c->setStyleSheet(QString::fromUtf8("#nom_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#nom_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
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
        enregistrer_c = new QPushButton(groupBox_2);
        enregistrer_c->setObjectName("enregistrer_c");
        enregistrer_c->setGeometry(QRect(18, 420, 130, 40));
        enregistrer_c->setStyleSheet(QString::fromUtf8("#enregistrer_c {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#enregistrer_c:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#enregistrer_c:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        enregistrer_c->setIcon(icon);
        dateN_c = new QDateEdit(groupBox_2);
        dateN_c->setObjectName("dateN_c");
        dateN_c->setGeometry(QRect(121, 154, 110, 40));
        dateN_c->setStyleSheet(QString::fromUtf8("#Datenaissance {\n"
"    background-color: #FFFFFF;\n"
"    color: #0F2434; /* Dark text for visibility */\n"
"    border: 1px solid #0F2434;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FFFFFF;\n"
"}\n"
"\n"
"#Datenaissance::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #0F2434;\n"
"    background-color: #0F2434;\n"
"}\n"
"\n"
"#Datenaissance::down-arrow {\n"
"    image: none;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-top: 4px solid #FFFFFF;\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}\n"
"\n"
"#Datenaissance:hover {\n"
"    border: 1px solid #1D9E3A;\n"
"}\n"
"\n"
"#Datenaissance:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        nvpermis_c = new QComboBox(groupBox_2);
        nvpermis_c->addItem(QString());
        nvpermis_c->addItem(QString());
        nvpermis_c->addItem(QString());
        nvpermis_c->addItem(QString());
        nvpermis_c->addItem(QString());
        nvpermis_c->setObjectName("nvpermis_c");
        nvpermis_c->setGeometry(QRect(130, 314, 100, 40));
        nvpermis_c->setStyleSheet(QString::fromUtf8("#Niveaupermis {\n"
"    background-color: #FFFFFF;\n"
"    color: #0F2434;\n"
"    border: 1px solid #0F2434;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"    font-weight: bold;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FFFFFF;\n"
"}\n"
"\n"
"\n"
"\n"
"#Niveaupermis::down-arrow {\n"
"    image: none;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #FFFFFF;\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}\n"
"\n"
"#Niveaupermis:hover {\n"
"    border: 1px solid #1D9E3A;\n"
"}\n"
"\n"
"#Niveaupermis:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#Niveaupermis QAbstractItemView {\n"
"    background-color: #FFFFFF;\n"
"    color: #0F2434;\n"
"    border: 1px solid #0F2434;\n"
"    border-radius: 4px;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FFFFFF;\n"
"    outline: none;\n"
"}\n"
"\n"
"#Niveaupermis QAbstractItemView::item {\n"
"    padding: 5px;\n"
"    border-bottom:"
                        " 1px solid #F0F0F0;\n"
"}\n"
"\n"
"#Niveaupermis QAbstractItemView::item:hover {\n"
"    background-color: #E8E8E8;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#Niveaupermis QAbstractItemView::item:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FFFFFF;\n"
"}"));
        prenom_c = new QLineEdit(groupBox_2);
        prenom_c->setObjectName("prenom_c");
        prenom_c->setGeometry(QRect(120, 120, 113, 28));
        prenom_c->setStyleSheet(QString::fromUtf8("#prenom_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#prenom_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        adr_c = new QLineEdit(groupBox_2);
        adr_c->setObjectName("adr_c");
        adr_c->setGeometry(QRect(120, 200, 113, 28));
        adr_c->setStyleSheet(QString::fromUtf8("#adr_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#adr_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        tel_c = new QLineEdit(groupBox_2);
        tel_c->setObjectName("tel_c");
        tel_c->setGeometry(QRect(120, 240, 113, 28));
        tel_c->setStyleSheet(QString::fromUtf8("#tel_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#tel_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        email_c = new QLineEdit(groupBox_2);
        email_c->setObjectName("email_c");
        email_c->setGeometry(QRect(120, 280, 113, 28));
        email_c->setStyleSheet(QString::fromUtf8("#email_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#email_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        prog_c = new QLineEdit(groupBox_2);
        prog_c->setObjectName("prog_c");
        prog_c->setGeometry(QRect(120, 360, 113, 28));
        prog_c->setStyleSheet(QString::fromUtf8("#prog_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#prog_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        taper_c = new QLineEdit(tab);
        taper_c->setObjectName("taper_c");
        taper_c->setGeometry(QRect(370, 10, 190, 40));
        taper_c->setStyleSheet(QString::fromUtf8("#taper {\n"
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
        filtrer_c = new QComboBox(tab);
        filtrer_c->addItem(QString());
        filtrer_c->addItem(QString());
        filtrer_c->setObjectName("filtrer_c");
        filtrer_c->setGeometry(QRect(710, 8, 144, 40));
        filtrer_c->setStyleSheet(QString::fromUtf8("#filtrer {\n"
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
        trier_c = new QComboBox(tab);
        trier_c->addItem(QString());
        trier_c->addItem(QString());
        trier_c->addItem(QString());
        trier_c->setObjectName("trier_c");
        trier_c->setGeometry(QRect(876, 10, 120, 40));
        trier_c->setStyleSheet(QString::fromUtf8("#trier {\n"
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
        tableWidget->setGeometry(QRect(330, 60, 681, 381));
        tableWidget->setStyleSheet(QString::fromUtf8("/* Main table styling */\n"
"#tableWidget {\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #0F2434;\n"
"    gridline-color: #0F2434;\n"
"    alternate-background-color: #E8E8E8;\n"
"}\n"
"\n"
"/* Table header styling - make columns visible */\n"
"#tableWidget QHeaderView::section {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px;\n"
"    border: 1px solid #1D9E3A;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"/* Table items/cells styling */\n"
"#tableWidget::item {\n"
"    border: 1px solid #0F2434;\n"
"    padding: 8px;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"/* Make sure text is visible in cells */\n"
"#tableWidget::item {\n"
"    color: #0F2434;\n"
"    background-color: #FBFAF5;\n"
"}\n"
"\n"
"/* Alternate row coloring */\n"
"#tableWidget::item:alternate {\n"
"    background-color: #F0F0F0;\n"
"}\n"
"\n"
"/* Hover effect on rows */\n"
"#tableWidget::item:hover {\n"
"    background-color: #E0E0E0;\n"
"    color: #0"
                        "F2434;\n"
"}\n"
"\n"
"/* Selected row styling */\n"
"#tableWidget::item:selected {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"}\n"
"\n"
"/* Ensure the table view itself has proper borders */\n"
"#tableWidget QTableView {\n"
"    gridline-color: #0F2434;\n"
"    border: 2px solid #0F2434;\n"
"}\n"
"\n"
"/* Corner button styling */\n"
"#tableWidget QTableCornerButton::section {\n"
"    background-color: #0F2434;\n"
"    border: 1px solid #0F2434;\n"
"}"));
        modifier_c = new QPushButton(tab);
        modifier_c->setObjectName("modifier_c");
        modifier_c->setGeometry(QRect(320, 460, 110, 30));
        modifier_c->setStyleSheet(QString::fromUtf8("#modifier_c {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#modifier_c:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#modifier_c:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        modifier_c->setIcon(icon1);
        ajouter_c = new QPushButton(tab);
        ajouter_c->setObjectName("ajouter_c");
        ajouter_c->setGeometry(QRect(440, 460, 120, 30));
        ajouter_c->setStyleSheet(QString::fromUtf8("#ajouter_c {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#ajouter_c:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#ajouter_c:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        ajouter_c->setIcon(icon2);
        expo_tab_c = new QPushButton(tab);
        expo_tab_c->setObjectName("expo_tab_c");
        expo_tab_c->setGeometry(QRect(700, 460, 121, 29));
        expo_tab_c->setStyleSheet(QString::fromUtf8("#expo_tab_c {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#expo_tab_c:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#expo_tab_c:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSend));
        expo_tab_c->setIcon(icon3);
        conf_rech_c = new QPushButton(tab);
        conf_rech_c->setObjectName("conf_rech_c");
        conf_rech_c->setGeometry(QRect(570, 16, 131, 31));
        conf_rech_c->setStyleSheet(QString::fromUtf8("#conf_rech_c {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_rech_c:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#conf_rech_c:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        conf_rech_c->setIcon(icon4);
        supp_c = new QPushButton(tab);
        supp_c->setObjectName("supp_c");
        supp_c->setGeometry(QRect(570, 460, 121, 29));
        supp_c->setStyleSheet(QString::fromUtf8("#supp_c {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#supp_c:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#supp_c:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        supp_c->setIcon(icon5);
        tab_widget_c->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tab_widget2_c = new QTabWidget(tab_2);
        tab_widget2_c->setObjectName("tab_widget2_c");
        tab_widget2_c->setGeometry(QRect(10, 10, 990, 480));
        tab_widget2_c->setStyleSheet(QString::fromUtf8("#tab_widget2_c {\n"
"    background-color: #FBFAF5;\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"#tab_widget2_c::pane {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    background-color: #FBFAF5;\n"
"}\n"
"\n"
"#tab_widget2_c QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px 20px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    margin-right: 2px;\n"
"}\n"
"\n"
"#tab_widget2_c QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"}\n"
"\n"
"#tab_widget2_c QTabBar::tab:hover {\n"
"    background-color: #30AA2C;\n"
"    color: #FBFAF5;\n"
"}\n"
""));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        selon_stat_c = new QComboBox(tab_3);
        selon_stat_c->addItem(QString());
        selon_stat_c->addItem(QString());
        selon_stat_c->addItem(QString());
        selon_stat_c->setObjectName("selon_stat_c");
        selon_stat_c->setGeometry(QRect(850, 20, 100, 40));
        selon_stat_c->setStyleSheet(QString::fromUtf8(""));
        tab_widget2_c->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        label_11 = new QLabel(tab_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(290, 30, 130, 30));
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
        label_12 = new QLabel(tab_4);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 30, 130, 30));
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
        ia_nomcandidat = new QLineEdit(tab_4);
        ia_nomcandidat->setObjectName("ia_nomcandidat");
        ia_nomcandidat->setGeometry(QRect(420, 30, 113, 28));
        ia_nomcandidat->setStyleSheet(QString::fromUtf8(""));
        ia_sonprogression = new QLineEdit(tab_4);
        ia_sonprogression->setObjectName("ia_sonprogression");
        ia_sonprogression->setGeometry(QRect(160, 30, 113, 28));
        ia_sonprogression->setStyleSheet(QString::fromUtf8(""));
        label_13 = new QLabel(tab_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 100, 130, 30));
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
        ia_proposition = new QLineEdit(tab_4);
        ia_proposition->setObjectName("ia_proposition");
        ia_proposition->setGeometry(QRect(40, 140, 840, 270));
        ia_proposition->setStyleSheet(QString::fromUtf8(""));
        ia_proposition->setReadOnly(true);
        tab_widget2_c->addTab(tab_4, QString());
        tab_widget_c->addTab(tab_2, QString());
        MainWindowC->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindowC);
        statusbar->setObjectName("statusbar");
        MainWindowC->setStatusBar(statusbar);

        retranslateUi(MainWindowC);

        tab_widget_c->setCurrentIndex(1);
        tab_widget2_c->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindowC);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowC)
    {
        MainWindowC->setWindowTitle(QCoreApplication::translate("MainWindowC", "MainWindow", nullptr));
        frame_gest->setTitle(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindowC", "Ajout", nullptr));
        label->setText(QCoreApplication::translate("MainWindowC", "ID :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowC", "Nom :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowC", "Pr\303\251nom :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindowC", "Date naissance :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindowC", "Adresse :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindowC", "T\303\251l\303\251phone :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindowC", "Email :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindowC", "Niveau permis :", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindowC", "Progression :", nullptr));
        enregistrer_c->setText(QCoreApplication::translate("MainWindowC", "Enregistrer ", nullptr));
        nvpermis_c->setItemText(0, QCoreApplication::translate("MainWindowC", "Choisir", nullptr));
        nvpermis_c->setItemText(1, QCoreApplication::translate("MainWindowC", "A", nullptr));
        nvpermis_c->setItemText(2, QCoreApplication::translate("MainWindowC", "B", nullptr));
        nvpermis_c->setItemText(3, QCoreApplication::translate("MainWindowC", "C", nullptr));
        nvpermis_c->setItemText(4, QCoreApplication::translate("MainWindowC", "D", nullptr));

        taper_c->setInputMask(QString());
        taper_c->setPlaceholderText(QCoreApplication::translate("MainWindowC", "  Recherche", nullptr));
        filtrer_c->setItemText(0, QCoreApplication::translate("MainWindowC", "Filtrer", nullptr));
        filtrer_c->setItemText(1, QCoreApplication::translate("MainWindowC", "ID", nullptr));

        trier_c->setItemText(0, QCoreApplication::translate("MainWindowC", "Trier", nullptr));
        trier_c->setItemText(1, QCoreApplication::translate("MainWindowC", "Nom", nullptr));
        trier_c->setItemText(2, QCoreApplication::translate("MainWindowC", "Date naissance", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindowC", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindowC", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindowC", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindowC", "Date naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindowC", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindowC", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindowC", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindowC", "Niveau permis", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindowC", "Progression", nullptr));
        modifier_c->setText(QCoreApplication::translate("MainWindowC", "Modifier", nullptr));
        ajouter_c->setText(QCoreApplication::translate("MainWindowC", "Ajouter", nullptr));
        expo_tab_c->setText(QCoreApplication::translate("MainWindowC", "Exporter", nullptr));
        conf_rech_c->setText(QCoreApplication::translate("MainWindowC", "Confirmer", nullptr));
        supp_c->setText(QCoreApplication::translate("MainWindowC", "Supprimer", nullptr));
        tab_widget_c->setTabText(tab_widget_c->indexOf(tab), QCoreApplication::translate("MainWindowC", "Ajout Candidats", nullptr));
        selon_stat_c->setItemText(0, QCoreApplication::translate("MainWindowC", "Selon", nullptr));
        selon_stat_c->setItemText(1, QCoreApplication::translate("MainWindowC", "Age", nullptr));
        selon_stat_c->setItemText(2, QCoreApplication::translate("MainWindowC", "Nivaeu permis", nullptr));

        tab_widget2_c->setTabText(tab_widget2_c->indexOf(tab_3), QCoreApplication::translate("MainWindowC", "Statistiques", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindowC", "Nom de candidat :", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindowC", "Son progression :", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindowC", "Les proposition :", nullptr));
        tab_widget2_c->setTabText(tab_widget2_c->indexOf(tab_4), QCoreApplication::translate("MainWindowC", "IA", nullptr));
        tab_widget_c->setTabText(tab_widget_c->indexOf(tab_2), QCoreApplication::translate("MainWindowC", "Fonctionnalit\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowC: public Ui_MainWindowC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

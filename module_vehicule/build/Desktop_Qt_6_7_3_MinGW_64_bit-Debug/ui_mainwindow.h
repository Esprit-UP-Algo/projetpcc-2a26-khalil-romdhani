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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
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
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *matricule;
    QComboBox *type;
    QLineEdit *marque;
    QLineEdit *modele;
    QLineEdit *annee;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLineEdit *km;
    QDateEdit *date_rev;
    QPushButton *conf_ajout;
    QPushButton *reinstaller_vehc;
    QLabel *label;
    QTableWidget *tab_vehicule;
    QPushButton *expo_tab;
    QComboBox *filtrer;
    QComboBox *trier;
    QLineEdit *taper;
    QPushButton *conf_tab;
    QWidget *tab_2;
    QTabWidget *tab_widget2;
    QWidget *tab_3;
    QPushButton *expo_stat;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QWidget *tab_4;
    QWidget *widget;
    QLabel *label_10;
    QPushButton *conf_ai;
    QPushButton *reins_ai;
    QLineEdit *mat_ai;
    QPushButton *expo_ai;
    QWidget *widget_4;
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
        candidat_btn->setGeometry(QRect(10, 170, 161, 41));
        vehicule_btn = new QPushButton(barre_nav);
        vehicule_btn->setObjectName("vehicule_btn");
        vehicule_btn->setGeometry(QRect(10, 220, 161, 41));
        pushButton_3 = new QPushButton(barre_nav);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(180, 190, 161, 41));
        moniteur_btn = new QPushButton(barre_nav);
        moniteur_btn->setObjectName("moniteur_btn");
        moniteur_btn->setGeometry(QRect(10, 270, 161, 41));
        seance_btn = new QPushButton(barre_nav);
        seance_btn->setObjectName("seance_btn");
        seance_btn->setGeometry(QRect(10, 320, 161, 41));
        emp_btn = new QPushButton(barre_nav);
        emp_btn->setObjectName("emp_btn");
        emp_btn->setGeometry(QRect(10, 370, 161, 41));
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
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 60, 61, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 100, 61, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 140, 61, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 190, 61, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 230, 61, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 290, 91, 20));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 330, 111, 20));
        matricule = new QLineEdit(groupBox);
        matricule->setObjectName("matricule");
        matricule->setGeometry(QRect(130, 20, 113, 31));
        type = new QComboBox(groupBox);
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName("type");
        type->setGeometry(QRect(130, 60, 111, 26));
        type->setStyleSheet(QString::fromUtf8("#type {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#type QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#type:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        marque = new QLineEdit(groupBox);
        marque->setObjectName("marque");
        marque->setGeometry(QRect(130, 100, 113, 31));
        modele = new QLineEdit(groupBox);
        modele->setObjectName("modele");
        modele->setGeometry(QRect(130, 140, 113, 31));
        annee = new QLineEdit(groupBox);
        annee->setObjectName("annee");
        annee->setGeometry(QRect(130, 190, 113, 31));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(50, 230, 110, 24));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(140, 230, 110, 24));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(50, 260, 110, 24));
        km = new QLineEdit(groupBox);
        km->setObjectName("km");
        km->setGeometry(QRect(130, 290, 113, 31));
        date_rev = new QDateEdit(groupBox);
        date_rev->setObjectName("date_rev");
        date_rev->setGeometry(QRect(130, 330, 110, 26));
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
        conf_ajout = new QPushButton(groupBox);
        conf_ajout->setObjectName("conf_ajout");
        conf_ajout->setGeometry(QRect(10, 370, 131, 29));
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
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        conf_ajout->setIcon(icon);
        reinstaller_vehc = new QPushButton(groupBox);
        reinstaller_vehc->setObjectName("reinstaller_vehc");
        reinstaller_vehc->setGeometry(QRect(150, 370, 131, 29));
        reinstaller_vehc->setStyleSheet(QString::fromUtf8("#reinstaller_vehc {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#reinstaller_vehc:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#reinstaller_vehc:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        reinstaller_vehc->setIcon(icon1);
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 141, 20));
        tab_vehicule = new QTableWidget(tab);
        if (tab_vehicule->columnCount() < 8)
            tab_vehicule->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tab_vehicule->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tab_vehicule->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tab_vehicule->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tab_vehicule->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tab_vehicule->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tab_vehicule->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tab_vehicule->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tab_vehicule->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tab_vehicule->setObjectName("tab_vehicule");
        tab_vehicule->setGeometry(QRect(320, 60, 731, 411));
        tab_vehicule->setStyleSheet(QString::fromUtf8("#tab_vehicule {\n"
"    background-color: #FBFAF5;\n"
"    alternate-background-color: #ded6ad;\n"
"    gridline-color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#tab_vehicule::item {\n"
"    padding: 6px;\n"
"}\n"
"\n"
"#tab_vehicule QHeaderView::section {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 6px;\n"
"    border: 1px solid #0F2434;\n"
"    font-weight: bold;\n"
"}\n"
""));
        expo_tab = new QPushButton(tab);
        expo_tab->setObjectName("expo_tab");
        expo_tab->setGeometry(QRect(320, 480, 121, 29));
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
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSend));
        expo_tab->setIcon(icon2);
        filtrer = new QComboBox(tab);
        filtrer->addItem(QString());
        filtrer->addItem(QString());
        filtrer->addItem(QString());
        filtrer->addItem(QString());
        filtrer->setObjectName("filtrer");
        filtrer->setGeometry(QRect(320, 20, 76, 26));
        filtrer->setStyleSheet(QString::fromUtf8("#filtrer {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#filtrer QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
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
        trier->setGeometry(QRect(410, 20, 76, 26));
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
        tab_widget->addTab(tab, QString());
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
        expo_stat = new QPushButton(tab_3);
        expo_stat->setObjectName("expo_stat");
        expo_stat->setGeometry(QRect(20, 390, 121, 29));
        expo_stat->setStyleSheet(QString::fromUtf8("#expo_stat {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#expo_stat:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#expo_stat:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        expo_stat->setIcon(icon2);
        radioButton_4 = new QRadioButton(tab_3);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(200, 390, 110, 24));
        radioButton_5 = new QRadioButton(tab_3);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(290, 390, 110, 24));
        tab_widget2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        widget = new QWidget(tab_4);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 90, 301, 121));
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 20, 71, 20));
        conf_ai = new QPushButton(widget);
        conf_ai->setObjectName("conf_ai");
        conf_ai->setGeometry(QRect(10, 80, 131, 29));
        conf_ai->setStyleSheet(QString::fromUtf8("#conf_ai {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_ai:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#conf_ai:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        conf_ai->setIcon(icon);
        reins_ai = new QPushButton(widget);
        reins_ai->setObjectName("reins_ai");
        reins_ai->setGeometry(QRect(150, 80, 131, 29));
        reins_ai->setStyleSheet(QString::fromUtf8("#reins_ai {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#reins_ai:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#reins_ai:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        reins_ai->setIcon(icon1);
        mat_ai = new QLineEdit(widget);
        mat_ai->setObjectName("mat_ai");
        mat_ai->setGeometry(QRect(100, 20, 113, 31));
        mat_ai->setStyleSheet(QString::fromUtf8("#mat_ai {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#mat_ai:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        expo_ai = new QPushButton(tab_4);
        expo_ai->setObjectName("expo_ai");
        expo_ai->setGeometry(QRect(20, 390, 121, 29));
        expo_ai->setStyleSheet(QString::fromUtf8("#expo_ai {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#expo_ai:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#expo_ai:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        expo_ai->setIcon(icon2);
        widget_4 = new QWidget(tab_4);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(320, 90, 531, 201));
        tab_widget2->addTab(tab_4, QString());
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
        label_2->setText(QCoreApplication::translate("MainWindow", "Matricule", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Marque", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Mod\303\250le", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ann\303\251e", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Kilom\303\251trage", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Date de r\303\251vision", nullptr));
        type->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir", nullptr));
        type->setItemText(1, QCoreApplication::translate("MainWindow", "Voiture", nullptr));
        type->setItemText(2, QCoreApplication::translate("MainWindow", "Moto", nullptr));
        type->setItemText(3, QCoreApplication::translate("MainWindow", "AutoBus", nullptr));
        type->setItemText(4, QCoreApplication::translate("MainWindow", "Camion poids lourd", nullptr));

        radioButton->setText(QCoreApplication::translate("MainWindow", "Bon", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "En panne", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Entretien", nullptr));
        conf_ajout->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        reinstaller_vehc->setText(QCoreApplication::translate("MainWindow", "R\303\251installer", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Gestion des v\303\251hicules", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab_vehicule->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Matricule", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab_vehicule->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab_vehicule->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Marque", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab_vehicule->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Mod\303\250le", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab_vehicule->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Ann\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab_vehicule->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tab_vehicule->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Kilom\303\251trage", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tab_vehicule->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Date de r\303\251vision", nullptr));
        expo_tab->setText(QCoreApplication::translate("MainWindow", "Exporter", nullptr));
        filtrer->setItemText(0, QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        filtrer->setItemText(1, QCoreApplication::translate("MainWindow", "Type", nullptr));
        filtrer->setItemText(2, QCoreApplication::translate("MainWindow", "Marque", nullptr));
        filtrer->setItemText(3, QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));

        trier->setItemText(0, QCoreApplication::translate("MainWindow", "Trier", nullptr));
        trier->setItemText(1, QCoreApplication::translate("MainWindow", "Ann\303\251e", nullptr));
        trier->setItemText(2, QCoreApplication::translate("MainWindow", "Kilom\303\251trage", nullptr));

        taper->setPlaceholderText(QCoreApplication::translate("MainWindow", "Taper...", nullptr));
        conf_tab->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        tab_widget->setTabText(tab_widget->indexOf(tab), QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        expo_stat->setText(QCoreApplication::translate("MainWindow", "Exporter", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "Masquer", nullptr));
        tab_widget2->setTabText(tab_widget2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Matricule", nullptr));
        conf_ai->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        reins_ai->setText(QCoreApplication::translate("MainWindow", "R\303\251installer", nullptr));
        expo_ai->setText(QCoreApplication::translate("MainWindow", "Exporter", nullptr));
        tab_widget2->setTabText(tab_widget2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Prediction AI", nullptr));
        tab_widget->setTabText(tab_widget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Fonctionnalit\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

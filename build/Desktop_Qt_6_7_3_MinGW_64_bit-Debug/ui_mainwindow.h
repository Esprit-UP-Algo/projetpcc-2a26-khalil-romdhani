/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_v;
    QFrame *frame_v;
    QTabWidget *widget_v;
    QWidget *tab;
    QGroupBox *groupBoxv;
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
    QRadioButton *bon;
    QRadioButton *panne;
    QRadioButton *entretien;
    QLineEdit *km;
    QDateEdit *date_rev;
    QPushButton *conf_v;
    QPushButton *reins_v;
    QLabel *label;
    QPushButton *expo_v;
    QComboBox *filtrer_v;
    QComboBox *trier_v;
    QLineEdit *taper_v;
    QPushButton *conf_rv;
    QPushButton *supp_v;
    QTableWidget *table_ajout_v;
    QWidget *tab_2;
    QTabWidget *tab_fonc_v;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *widget_ai;
    QLabel *label_10;
    QPushButton *conf_ai_v;
    QPushButton *reins_ai_v;
    QLineEdit *mat_ai;
    QWidget *page_s;
    QGroupBox *frame_sea;
    QTabWidget *tabWidget_s;
    QWidget *tab_9;
    QGroupBox *groupBoxs;
    QLineEdit *ID_s;
    QLabel *label_24;
    QComboBox *type_s;
    QDateEdit *date_s;
    QTimeEdit *deb_s;
    QTimeEdit *fin_s;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QPushButton *confirm_ajout_s;
    QLabel *label_28;
    QTableWidget *tab_s;
    QPushButton *confirm_s;
    QPushButton *exp_s;
    QPushButton *filtre_s;
    QComboBox *tri_s;
    QLineEdit *recherche_s;
    QLabel *label_29;
    QWidget *tab_10;
    QGroupBox *groupBox_stats;
    QLabel *label_totalSessions;
    QLabel *label_totalHours;
    QTableWidget *stats_s;
    QPushButton *refresh_s;
    QWidget *tab_11;
    QCalendarWidget *calendar_s;
    QGroupBox *Details_s;
    QListWidget *listWidget_sessions;
    QWidget *tab_12;
    QGroupBox *groupBox_map;
    QLabel *label_mapView;
    QLabel *label_routePreview;
    QGroupBox *groupBox_route;
    QLineEdit *departure_s;
    QLineEdit *destination_s;
    QPushButton *calculateRoute_s;
    QLabel *label_distance;
    QLabel *label_duration;
    QPushButton *saveRoute_s;
    QPushButton *clearRoute_s;
    QLabel *label_routeStatus;
    QLabel *label_mapTitle;
    QComboBox *mapType_s;
    QPushButton *centerMap_s;
    QWidget *page_c;
    QGroupBox *frame_gest;
    QTabWidget *tab_widget_c;
    QWidget *tab_5;
    QGroupBox *groupBoxc;
    QLabel *label_11;
    QLineEdit *id_c;
    QLabel *label_12;
    QLineEdit *nom_c;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
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
    QLabel *label_23;
    QWidget *tab_6;
    QTabWidget *tab_widget2_c;
    QWidget *tab_7;
    QComboBox *selon_stat_c;
    QLabel *label_31;
    QWidget *tab_8;
    QLabel *label_20;
    QLineEdit *ia_nomcandidat;
    QLabel *label_21;
    QLabel *label_22;
    QGroupBox *barre_nav;
    QPushButton *fermer_btn;
    QPushButton *seance_btn;
    QPushButton *vehicule_btn;
    QPushButton *emp_btn;
    QPushButton *moniteur_btn;
    QPushButton *candidat_btn;
    QLabel *label_30;
    QGroupBox *barre;
    QLabel *titre;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1508, 859);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(200, 70, 1301, 701));
        page_v = new QWidget();
        page_v->setObjectName("page_v");
        frame_v = new QFrame(page_v);
        frame_v->setObjectName("frame_v");
        frame_v->setGeometry(QRect(20, 20, 1271, 641));
        frame_v->setStyleSheet(QString::fromUtf8("#frame_v {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
""));
        frame_v->setFrameShape(QFrame::Shape::StyledPanel);
        frame_v->setFrameShadow(QFrame::Shadow::Raised);
        widget_v = new QTabWidget(frame_v);
        widget_v->setObjectName("widget_v");
        widget_v->setGeometry(QRect(10, 20, 1241, 591));
        widget_v->setStyleSheet(QString::fromUtf8("QTabWidget#widget_v {\n"
"    background-color: #FBFAF5;\n"
"    border: 3px solid #0F2434;\n"
"    border-top: 5px solid #1E90FF;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabWidget#widget_v::pane {\n"
"    border: 1px solid #0F2434;\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QTabWidget#widget_v QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px 16px;\n"
"    margin: 2px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabWidget#widget_v QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border-bottom: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"QTabWidget#widget_v QTabBar::tab:hover {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBoxv = new QGroupBox(tab);
        groupBoxv->setObjectName("groupBoxv");
        groupBoxv->setGeometry(QRect(10, 70, 301, 411));
        groupBoxv->setStyleSheet(QString::fromUtf8("#groupBoxv{\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
"#groupBoxv::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 5px 10px;\n"
"    border-radius: 3px;\n"
"}"));
        label_2 = new QLabel(groupBoxv);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 30, 71, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        label_3 = new QLabel(groupBoxv);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 60, 61, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        label_4 = new QLabel(groupBoxv);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 100, 61, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_5 = new QLabel(groupBoxv);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 140, 61, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_6 = new QLabel(groupBoxv);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 190, 61, 20));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_7 = new QLabel(groupBoxv);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 230, 61, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_8 = new QLabel(groupBoxv);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 290, 91, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_9 = new QLabel(groupBoxv);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 330, 111, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        matricule = new QLineEdit(groupBoxv);
        matricule->setObjectName("matricule");
        matricule->setGeometry(QRect(130, 20, 113, 31));
        matricule->setStyleSheet(QString::fromUtf8("#matricule {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#matricule:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        type = new QComboBox(groupBoxv);
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
        marque = new QLineEdit(groupBoxv);
        marque->setObjectName("marque");
        marque->setGeometry(QRect(130, 100, 113, 31));
        marque->setStyleSheet(QString::fromUtf8("#marque {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#marque:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        modele = new QLineEdit(groupBoxv);
        modele->setObjectName("modele");
        modele->setGeometry(QRect(130, 140, 113, 31));
        modele->setStyleSheet(QString::fromUtf8("#modele {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#modele:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        annee = new QLineEdit(groupBoxv);
        annee->setObjectName("annee");
        annee->setGeometry(QRect(130, 190, 113, 31));
        annee->setStyleSheet(QString::fromUtf8("#annee {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#annee:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        bon = new QRadioButton(groupBoxv);
        bon->setObjectName("bon");
        bon->setGeometry(QRect(50, 230, 110, 24));
        bon->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        panne = new QRadioButton(groupBoxv);
        panne->setObjectName("panne");
        panne->setGeometry(QRect(140, 230, 110, 24));
        panne->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        entretien = new QRadioButton(groupBoxv);
        entretien->setObjectName("entretien");
        entretien->setGeometry(QRect(50, 260, 110, 24));
        entretien->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        km = new QLineEdit(groupBoxv);
        km->setObjectName("km");
        km->setGeometry(QRect(130, 290, 113, 31));
        km->setStyleSheet(QString::fromUtf8("#km {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#km:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        date_rev = new QDateEdit(groupBoxv);
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
        conf_v = new QPushButton(groupBoxv);
        conf_v->setObjectName("conf_v");
        conf_v->setGeometry(QRect(10, 370, 131, 29));
        conf_v->setStyleSheet(QString::fromUtf8("#conf_v {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_v:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#conf_v:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        reins_v = new QPushButton(groupBoxv);
        reins_v->setObjectName("reins_v");
        reins_v->setGeometry(QRect(150, 370, 131, 29));
        reins_v->setStyleSheet(QString::fromUtf8("#reins_v {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#reins_v:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#reins_v:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 261, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        expo_v = new QPushButton(tab);
        expo_v->setObjectName("expo_v");
        expo_v->setGeometry(QRect(320, 480, 121, 31));
        expo_v->setStyleSheet(QString::fromUtf8("#expo_v {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#expo_v:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#expo_v:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pdf/img/pdf.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        expo_v->setIcon(icon);
        filtrer_v = new QComboBox(tab);
        filtrer_v->addItem(QString());
        filtrer_v->addItem(QString());
        filtrer_v->addItem(QString());
        filtrer_v->addItem(QString());
        filtrer_v->setObjectName("filtrer_v");
        filtrer_v->setGeometry(QRect(320, 20, 91, 26));
        filtrer_v->setStyleSheet(QString::fromUtf8("#filtrer_v {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#filtrer_v:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#filtrer_v QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        trier_v = new QComboBox(tab);
        trier_v->addItem(QString());
        trier_v->addItem(QString());
        trier_v->addItem(QString());
        trier_v->setObjectName("trier_v");
        trier_v->setGeometry(QRect(430, 20, 76, 26));
        trier_v->setStyleSheet(QString::fromUtf8("#trier_v {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#trier_v:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#trier_v QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        taper_v = new QLineEdit(tab);
        taper_v->setObjectName("taper_v");
        taper_v->setGeometry(QRect(690, 10, 141, 41));
        taper_v->setStyleSheet(QString::fromUtf8("#taper_v {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#taper_v:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        conf_rv = new QPushButton(tab);
        conf_rv->setObjectName("conf_rv");
        conf_rv->setGeometry(QRect(870, 10, 141, 41));
        conf_rv->setStyleSheet(QString::fromUtf8("#conf_rv {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_rv:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#conf_rv:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        supp_v = new QPushButton(tab);
        supp_v->setObjectName("supp_v");
        supp_v->setGeometry(QRect(450, 480, 121, 31));
        supp_v->setStyleSheet(QString::fromUtf8("#supp_v {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#supp_v:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#supp_v:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        table_ajout_v = new QTableWidget(tab);
        if (table_ajout_v->columnCount() < 8)
            table_ajout_v->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_ajout_v->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_ajout_v->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_ajout_v->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_ajout_v->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_ajout_v->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_ajout_v->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_ajout_v->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_ajout_v->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        table_ajout_v->setObjectName("table_ajout_v");
        table_ajout_v->setGeometry(QRect(325, 60, 871, 411));
        table_ajout_v->setStyleSheet(QString::fromUtf8("#table_ajout_v {\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #0F2434;\n"
"    gridline-color: #0F2434;\n"
"    alternate-background-color: #E8E8E8;\n"
"}\n"
"\n"
"#table_ajout_v QHeaderView::section {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px;\n"
"    border: 1px solid #1D9E3A;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"#table_ajout_v::item {\n"
"    border: 1px solid #0F2434;\n"
"    padding: 8px;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#table_ajout_v::item {\n"
"    color: #0F2434;\n"
"    background-color: #FBFAF5;\n"
"}\n"
"\n"
"/* Alternate row coloring */\n"
"#table_ajout_v::item:alternate {\n"
"    background-color: #F0F0F0;\n"
"}\n"
"\n"
"#table_ajout_v::item:hover {\n"
"    background-color: #E0E0E0;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#table_ajout_v::item:selected {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"}\n"
"\n"
"#table_ajout_v QTableView {\n"
"    gridline-color: #0F"
                        "2434;\n"
"    border: 2px solid #0F2434;\n"
"}\n"
"\n"
"*#table_ajout_v QTableCornerButton::section {\n"
"    background-color: #0F2434;\n"
"    border: 1px solid #0F2434;\n"
"}"));
        widget_v->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tab_fonc_v = new QTabWidget(tab_2);
        tab_fonc_v->setObjectName("tab_fonc_v");
        tab_fonc_v->setGeometry(QRect(10, 20, 1021, 471));
        tab_fonc_v->setStyleSheet(QString::fromUtf8("#tab_fonc_v {\n"
"    background-color: #FBFAF5;\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"#tab_fonc_v::pane {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    background-color: #FBFAF5;\n"
"}\n"
"\n"
"#tab_fonc_v QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px 20px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    margin-right: 2px;\n"
"}\n"
"\n"
"#tab_fonc_v QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"}\n"
"\n"
"#tab_fonc_v QTabBar::tab:hover {\n"
"    background-color: #30AA2C;\n"
"    color: #FBFAF5;\n"
"}\n"
""));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tab_fonc_v->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        widget_ai = new QWidget(tab_4);
        widget_ai->setObjectName("widget_ai");
        widget_ai->setGeometry(QRect(10, 90, 301, 121));
        widget_ai->setStyleSheet(QString::fromUtf8("#widget_ai {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
""));
        label_10 = new QLabel(widget_ai);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 30, 71, 21));
        conf_ai_v = new QPushButton(widget_ai);
        conf_ai_v->setObjectName("conf_ai_v");
        conf_ai_v->setGeometry(QRect(10, 80, 131, 29));
        conf_ai_v->setStyleSheet(QString::fromUtf8("#conf_ai_v {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_ai_v:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#conf_ai_v:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        reins_ai_v = new QPushButton(widget_ai);
        reins_ai_v->setObjectName("reins_ai_v");
        reins_ai_v->setGeometry(QRect(150, 80, 131, 29));
        reins_ai_v->setStyleSheet(QString::fromUtf8("#reins_ai_v {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#reins_ai_v:hover {\n"
"    background-color: #30AA2C;\n"
"}\n"
"\n"
"#reins_ai_v:pressed {\n"
"    background-color: #239539;\n"
"}\n"
""));
        mat_ai = new QLineEdit(widget_ai);
        mat_ai->setObjectName("mat_ai");
        mat_ai->setGeometry(QRect(100, 20, 141, 41));
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
        tab_fonc_v->addTab(tab_4, QString());
        widget_v->addTab(tab_2, QString());
        stackedWidget->addWidget(page_v);
        page_s = new QWidget();
        page_s->setObjectName("page_s");
        frame_sea = new QGroupBox(page_s);
        frame_sea->setObjectName("frame_sea");
        frame_sea->setGeometry(QRect(20, 20, 1281, 641));
        frame_sea->setStyleSheet(QString::fromUtf8("#frame_sea {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
""));
        tabWidget_s = new QTabWidget(frame_sea);
        tabWidget_s->setObjectName("tabWidget_s");
        tabWidget_s->setGeometry(QRect(10, 20, 1131, 581));
        tabWidget_s->setStyleSheet(QString::fromUtf8("QTabWidget#tabWidget_s {\n"
"    background-color: #FBFAF5;\n"
"    border: 3px solid #0F2434;\n"
"    border-top: 5px solid #1E90FF;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabWidget#tabWidget_s::pane {\n"
"    border: 1px solid #0F2434;\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QTabWidget#tabWidget_s QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px 16px;\n"
"    margin: 2px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabWidget#tabWidget_s QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"    border-bottom: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"QTabWidget#tabWidget_s QTabBar::tab:hover {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"}"));
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        groupBoxs = new QGroupBox(tab_9);
        groupBoxs->setObjectName("groupBoxs");
        groupBoxs->setGeometry(QRect(20, 70, 331, 401));
        groupBoxs->setStyleSheet(QString::fromUtf8("#groupBoxs {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
"#groupBoxs::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 5px 10px;\n"
"    border-radius: 3px;\n"
"}"));
        ID_s = new QLineEdit(groupBoxs);
        ID_s->setObjectName("ID_s");
        ID_s->setGeometry(QRect(80, 20, 151, 41));
        ID_s->setStyleSheet(QString::fromUtf8("#ID_s {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#ID_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        label_24 = new QLabel(groupBoxs);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 30, 63, 20));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        type_s = new QComboBox(groupBoxs);
        type_s->addItem(QString());
        type_s->addItem(QString());
        type_s->addItem(QString());
        type_s->setObjectName("type_s");
        type_s->setGeometry(QRect(80, 80, 151, 41));
        type_s->setStyleSheet(QString::fromUtf8("#type_s {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#type_s QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#type_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        date_s = new QDateEdit(groupBoxs);
        date_s->setObjectName("date_s");
        date_s->setGeometry(QRect(80, 140, 151, 41));
        date_s->setStyleSheet(QString::fromUtf8("#date_s {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#date_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#date_s QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
""));
        deb_s = new QTimeEdit(groupBoxs);
        deb_s->setObjectName("deb_s");
        deb_s->setGeometry(QRect(80, 210, 151, 41));
        deb_s->setStyleSheet(QString::fromUtf8("#deb_s {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#deb_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#deb_s QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        fin_s = new QTimeEdit(groupBoxs);
        fin_s->setObjectName("fin_s");
        fin_s->setGeometry(QRect(80, 280, 151, 41));
        fin_s->setStyleSheet(QString::fromUtf8("#fin_s {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#fin_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#fin_s QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        label_25 = new QLabel(groupBoxs);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(10, 150, 63, 20));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_26 = new QLabel(groupBoxs);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 220, 63, 20));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_27 = new QLabel(groupBoxs);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 290, 63, 20));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        confirm_ajout_s = new QPushButton(groupBoxs);
        confirm_ajout_s->setObjectName("confirm_ajout_s");
        confirm_ajout_s->setGeometry(QRect(10, 350, 121, 29));
        confirm_ajout_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #28A745;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34CE57;\n"
"    transform: scale(1.05);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1E7E34;\n"
"    transform: scale(0.98);\n"
"}"));
        label_28 = new QLabel(groupBoxs);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(10, 90, 63, 20));
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        tab_s = new QTableWidget(tab_9);
        if (tab_s->columnCount() < 12)
            tab_s->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(8, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(9, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(10, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(11, __qtablewidgetitem19);
        tab_s->setObjectName("tab_s");
        tab_s->setGeometry(QRect(380, 100, 611, 311));
        tab_s->setStyleSheet(QString::fromUtf8("/* Main table styling */\n"
"#tab_s {\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #0F2434;\n"
"    gridline-color: #0F2434;\n"
"    alternate-background-color: #E8E8E8;\n"
"}\n"
"\n"
"/* Table header styling - make columns visible */\n"
"#tab_s QHeaderView::section {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px;\n"
"    border: 1px solid #1D9E3A;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"/* Table items/cells styling */\n"
"#tab_s::item {\n"
"    border: 1px solid #0F2434;\n"
"    padding: 8px;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"/* Make sure text is visible in cells */\n"
"#tab_s::item {\n"
"    color: #0F2434;\n"
"    background-color: #FBFAF5;\n"
"}\n"
"\n"
"/* Alternate row coloring */\n"
"#tab_s::item:alternate {\n"
"    background-color: #F0F0F0;\n"
"}\n"
"\n"
"/* Hover effect on rows */\n"
"#tab_s::item:hover {\n"
"    background-color: #E0E0E0;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"/* Selected ro"
                        "w styling */\n"
"#tab_s::item:selected {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"}\n"
"\n"
"/* Ensure the table view itself has proper borders */\n"
"#tab_s QTableView {\n"
"    gridline-color: #0F2434;\n"
"    border: 2px solid #0F2434;\n"
"}\n"
"\n"
"/* Corner button styling */\n"
"#tab_s QTableCornerButton::section {\n"
"    background-color: #0F2434;\n"
"    border: 1px solid #0F2434;\n"
"}"));
        tab_s->horizontalHeader()->setStretchLastSection(false);
        confirm_s = new QPushButton(tab_9);
        confirm_s->setObjectName("confirm_s");
        confirm_s->setGeometry(QRect(860, 60, 121, 31));
        confirm_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #28A745;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34CE57;\n"
"    transform: scale(1.05);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1E7E34;\n"
"    transform: scale(0.98);\n"
"}"));
        exp_s = new QPushButton(tab_9);
        exp_s->setObjectName("exp_s");
        exp_s->setGeometry(QRect(380, 430, 141, 35));
        exp_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #28A745;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34CE57;\n"
"    transform: scale(1.05);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1E7E34;\n"
"    transform: scale(0.98);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res2/img/excel.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exp_s->setIcon(icon1);
        filtre_s = new QPushButton(tab_9);
        filtre_s->setObjectName("filtre_s");
        filtre_s->setGeometry(QRect(500, 60, 90, 29));
        filtre_s->setStyleSheet(QString::fromUtf8("#filtre_s {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"\n"
"#filtre_s QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"	selection-color: rgb(0, 0, 0);\n"
"\n"
"}\n"
"\n"
"#filtre_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        tri_s = new QComboBox(tab_9);
        tri_s->addItem(QString());
        tri_s->addItem(QString());
        tri_s->addItem(QString());
        tri_s->setObjectName("tri_s");
        tri_s->setGeometry(QRect(380, 60, 111, 28));
        tri_s->setStyleSheet(QString::fromUtf8("#tri_s {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#tri_s QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#tri_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        recherche_s = new QLineEdit(tab_9);
        recherche_s->setObjectName("recherche_s");
        recherche_s->setGeometry(QRect(680, 60, 121, 31));
        recherche_s->setAutoFillBackground(false);
        recherche_s->setStyleSheet(QString::fromUtf8("#recherche_s {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#recherche_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        label_29 = new QLabel(tab_9);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(20, 20, 251, 31));
        label_29->setFont(font);
        tabWidget_s->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        groupBox_stats = new QGroupBox(tab_10);
        groupBox_stats->setObjectName("groupBox_stats");
        groupBox_stats->setGeometry(QRect(10, 10, 450, 300));
        groupBox_stats->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #0074D9;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    background-color: #001F3F;\n"
"    color: #FFFFFF;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 5px 0 5px;\n"
"    color: #FFFFFF;\n"
"    background-color: #00C851;\n"
"    border-radius: 3px;\n"
"}"));
        label_totalSessions = new QLabel(groupBox_stats);
        label_totalSessions->setObjectName("label_totalSessions");
        label_totalSessions->setGeometry(QRect(20, 30, 200, 30));
        label_totalSessions->setStyleSheet(QString::fromUtf8("font-size: 14px; font-weight: bold;\n"
"color: rgb(255, 255, 255);"));
        label_totalHours = new QLabel(groupBox_stats);
        label_totalHours->setObjectName("label_totalHours");
        label_totalHours->setGeometry(QRect(20, 70, 200, 30));
        label_totalHours->setStyleSheet(QString::fromUtf8("font-size: 14px; font-weight: bold;\n"
"color: rgb(255, 255, 255);"));
        stats_s = new QTableWidget(groupBox_stats);
        if (stats_s->columnCount() < 4)
            stats_s->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(3, __qtablewidgetitem23);
        stats_s->setObjectName("stats_s");
        stats_s->setGeometry(QRect(20, 110, 410, 170));
        stats_s->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: white;\n"
"    alternate-background-color: #002B5C;\n"
"    gridline-color: black;\n"
"    color: #000000;\n"
"    border: 1px solid white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #00C851;\n"
"    color: #FFFFFF;\n"
"    padding: 4px;\n"
"    border: 1px solid black;\n"
"    min-width: 80px;\n"
"}"));
        stats_s->horizontalHeader()->setStretchLastSection(true);
        refresh_s = new QPushButton(tab_10);
        refresh_s->setObjectName("refresh_s");
        refresh_s->setGeometry(QRect(480, 30, 120, 40));
        refresh_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #28A745;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34CE57;\n"
"    transform: scale(1.05);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1E7E34;\n"
"    transform: scale(0.98);\n"
"}"));
        tabWidget_s->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName("tab_11");
        calendar_s = new QCalendarWidget(tab_11);
        calendar_s->setObjectName("calendar_s");
        calendar_s->setGeometry(QRect(10, 10, 500, 400));
        calendar_s->setStyleSheet(QString::fromUtf8("/* Main Calendar Widget */\n"
"QCalendarWidget {\n"
"    background-color: #001F3F;\n"
"    color: #FFFFFF;\n"
"    border: 2px solid #0074D9;\n"
"    border-radius: 8px;\n"
"    font-family: Arial, sans-serif;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"/* Calendar Grid (Days) */\n"
"QCalendarWidget QAbstractItemView {\n"
"    background-color: #002B5C;\n"
"    color: #FFFFFF;\n"
"    selection-background-color: #00C851;\n"
"    selection-color: #FFFFFF;\n"
"    border: none;\n"
"    outline: none;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView:enabled {\n"
"    color: #FFFFFF;\n"
"    background-color: #002B5C;\n"
"}\n"
"\n"
"/* Navigation Bar (Month/Year) */\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar {\n"
"    background-color: #001F3F;\n"
"    color: #FFFFFF;\n"
"    border-bottom: 1px solid #0074D9;\n"
"}\n"
"\n"
"/* Navigation Buttons (Previous/Next Month) */\n"
"QCalendarWidget QToolButton {\n"
"    background-color: #00C851;\n"
"    color: #FFFFFF;\n"
"    border: 1p"
                        "x solid #0074D9;\n"
"    border-radius: 4px;\n"
"    margin: 2px;\n"
"    padding: 4px;\n"
"    font-weight: bold;\n"
"    min-width: 20px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:hover {\n"
"    background-color: #00E676;\n"
"    color: #000000;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:pressed {\n"
"    background-color: #00B140;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"/* Month/Year Labels */\n"
"QCalendarWidget QLabel {\n"
"    color: #FFFFFF;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* Spinbox for year */\n"
"QCalendarWidget QSpinBox {\n"
"    background-color: #002B5C;\n"
"    color: #FFFFFF;\n"
"    border: 1px solid #0074D9;\n"
"    border-radius: 3px;\n"
"    padding: 2px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox:focus {\n"
"    border: 2px solid #00C851;\n"
"}\n"
"\n"
"/* Day names header */\n"
"QCalendarWidget QWidget#qt_calendar_calendarview {\n"
"    background-color: #002B5C;\n"
"    bo"
                        "rder: 1px solid #0074D9;\n"
"}\n"
"\n"
"/* Weekend days styling */\n"
"QCalendarWidget QAbstractItemView:item {\n"
"    padding: 4px;\n"
"    border: none;\n"
"}\n"
"\n"
"/* Today's date highlighting */\n"
"QCalendarWidget QAbstractItemView:item:selected {\n"
"    background-color: #00C851;\n"
"    color: #FFFFFF;\n"
"    font-weight: bold;\n"
"    border: 2px solid #FFFFFF;\n"
"    border-radius: 4px;\n"
"}"));
        calendar_s->setLocale(QLocale(QLocale::French, QLocale::France));
        calendar_s->setFirstDayOfWeek(Qt::DayOfWeek::Monday);
        calendar_s->setGridVisible(true);
        calendar_s->setSelectionMode(QCalendarWidget::SelectionMode::SingleSelection);
        calendar_s->setHorizontalHeaderFormat(QCalendarWidget::HorizontalHeaderFormat::ShortDayNames);
        calendar_s->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);
        calendar_s->setNavigationBarVisible(true);
        calendar_s->setDateEditEnabled(true);
        Details_s = new QGroupBox(tab_11);
        Details_s->setObjectName("Details_s");
        Details_s->setGeometry(QRect(520, 10, 450, 400));
        Details_s->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #0074D9;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    background-color: #001F3F;\n"
"    color: #FFFFFF;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 5px 0 5px;\n"
"    color: #FFFFFF;\n"
"    background-color: #00C851;\n"
"    border-radius: 3px;\n"
"}"));
        listWidget_sessions = new QListWidget(Details_s);
        listWidget_sessions->setObjectName("listWidget_sessions");
        listWidget_sessions->setGeometry(QRect(20, 30, 410, 350));
        listWidget_sessions->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background-color: white;\n"
"    color: #000000;\n"
"    border: 1px solid #0074D9;\n"
"    border-radius: 3px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    padding: 8px;\n"
"    border-bottom: 1px solid #E0E0E0;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #00C851;\n"
"    color: #FFFFFF;\n"
"}"));
        tabWidget_s->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName("tab_12");
        groupBox_map = new QGroupBox(tab_12);
        groupBox_map->setObjectName("groupBox_map");
        groupBox_map->setGeometry(QRect(10, 10, 970, 500));
        groupBox_map->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #0074D9;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    background-color: #001F3F;\n"
"    color: #FFFFFF;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 5px 0 5px;\n"
"    color: #FFFFFF;\n"
"    background-color: #00C851;\n"
"    border-radius: 3px;\n"
"}"));
        label_mapView = new QLabel(groupBox_map);
        label_mapView->setObjectName("label_mapView");
        label_mapView->setGeometry(QRect(20, 80, 700, 400));
        label_mapView->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #E8F4FD;\n"
"    border: 2px solid #0074D9;\n"
"    border-radius: 5px;\n"
"    color: #0074D9;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}"));
        label_mapView->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_mapView->setWordWrap(true);
        label_routePreview = new QLabel(groupBox_map);
        label_routePreview->setObjectName("label_routePreview");
        label_routePreview->setGeometry(QRect(50, 120, 640, 300));
        label_routePreview->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(0, 200, 81, 0.1);\n"
"    border: 2px dashed #00C851;\n"
"    border-radius: 8px;\n"
"    color: #00C851;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}"));
        label_routePreview->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_routePreview->setWordWrap(true);
        groupBox_route = new QGroupBox(groupBox_map);
        groupBox_route->setObjectName("groupBox_route");
        groupBox_route->setGeometry(QRect(740, 80, 210, 400));
        groupBox_route->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #0074D9;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"    background-color: #002B5C;\n"
"    color: #FFFFFF;\n"
"}"));
        departure_s = new QLineEdit(groupBox_route);
        departure_s->setObjectName("departure_s");
        departure_s->setGeometry(QRect(10, 40, 180, 30));
        departure_s->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 1px solid #0074D9;\n"
"    border-radius: 3px;\n"
"    padding: 6px;\n"
"    color: #000000;\n"
"}"));
        destination_s = new QLineEdit(groupBox_route);
        destination_s->setObjectName("destination_s");
        destination_s->setGeometry(QRect(10, 80, 180, 30));
        destination_s->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 1px solid #0074D9;\n"
"    border-radius: 3px;\n"
"    padding: 6px;\n"
"    color: #000000;\n"
"}"));
        calculateRoute_s = new QPushButton(groupBox_route);
        calculateRoute_s->setObjectName("calculateRoute_s");
        calculateRoute_s->setGeometry(QRect(10, 120, 180, 35));
        calculateRoute_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00C851;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #00E676;\n"
"}"));
        label_distance = new QLabel(groupBox_route);
        label_distance->setObjectName("label_distance");
        label_distance->setGeometry(QRect(10, 170, 180, 25));
        label_distance->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: rgb(255, 255, 255);"));
        label_duration = new QLabel(groupBox_route);
        label_duration->setObjectName("label_duration");
        label_duration->setGeometry(QRect(10, 200, 180, 25));
        label_duration->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: rgb(255, 255, 255);"));
        saveRoute_s = new QPushButton(groupBox_route);
        saveRoute_s->setObjectName("saveRoute_s");
        saveRoute_s->setGeometry(QRect(10, 240, 180, 35));
        saveRoute_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007BFF;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0056B3;\n"
"}"));
        clearRoute_s = new QPushButton(groupBox_route);
        clearRoute_s->setObjectName("clearRoute_s");
        clearRoute_s->setGeometry(QRect(10, 285, 180, 35));
        clearRoute_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #DC3545;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #C82333;\n"
"}"));
        label_routeStatus = new QLabel(groupBox_route);
        label_routeStatus->setObjectName("label_routeStatus");
        label_routeStatus->setGeometry(QRect(10, 330, 180, 50));
        label_routeStatus->setStyleSheet(QString::fromUtf8("font-size: 12px; color: #00C851; font-weight: bold;"));
        label_routeStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_routeStatus->setWordWrap(true);
        label_mapTitle = new QLabel(groupBox_map);
        label_mapTitle->setObjectName("label_mapTitle");
        label_mapTitle->setGeometry(QRect(20, 30, 400, 30));
        label_mapTitle->setStyleSheet(QString::fromUtf8("font-size: 14px; font-weight: bold;\n"
"color: rgb(255, 255, 255);"));
        mapType_s = new QComboBox(groupBox_map);
        mapType_s->addItem(QString());
        mapType_s->addItem(QString());
        mapType_s->addItem(QString());
        mapType_s->setObjectName("mapType_s");
        mapType_s->setGeometry(QRect(500, 30, 150, 30));
        mapType_s->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #001F3F;\n"
"    border: 1px solid #0074D9;\n"
"    color: #FFFFFF;\n"
"    padding: 5px;\n"
"    border-radius: 3px;\n"
"}\n"
"QComboBox:hover { \n"
"    border: 1px solid #00C851; \n"
"}"));
        centerMap_s = new QPushButton(groupBox_map);
        centerMap_s->setObjectName("centerMap_s");
        centerMap_s->setGeometry(QRect(670, 30, 100, 30));
        centerMap_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FFC107;\n"
"    border: none;\n"
"    color: #000000;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #E0A800;\n"
"}"));
        tabWidget_s->addTab(tab_12, QString());
        stackedWidget->addWidget(page_s);
        page_c = new QWidget();
        page_c->setObjectName("page_c");
        frame_gest = new QGroupBox(page_c);
        frame_gest->setObjectName("frame_gest");
        frame_gest->setGeometry(QRect(20, 20, 1271, 641));
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
        tab_widget_c->setGeometry(QRect(10, 20, 1241, 591));
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
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        groupBoxc = new QGroupBox(tab_5);
        groupBoxc->setObjectName("groupBoxc");
        groupBoxc->setGeometry(QRect(10, 60, 300, 461));
        groupBoxc->setStyleSheet(QString::fromUtf8("#groupBoxc {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
"#groupBoxc::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 5px 10px;\n"
"    border-radius: 3px;\n"
"}"));
        label_11 = new QLabel(groupBoxc);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 40, 30, 30));
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
        id_c = new QLineEdit(groupBoxc);
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
        label_12 = new QLabel(groupBoxc);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 80, 40, 30));
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
        nom_c = new QLineEdit(groupBoxc);
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
        label_13 = new QLabel(groupBoxc);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 120, 60, 30));
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
        label_14 = new QLabel(groupBoxc);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 160, 110, 30));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        label_15 = new QLabel(groupBoxc);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 200, 60, 30));
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        label_16 = new QLabel(groupBoxc);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 240, 100, 30));
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        label_17 = new QLabel(groupBoxc);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 285, 100, 30));
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        label_18 = new QLabel(groupBoxc);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 320, 110, 30));
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        label_19 = new QLabel(groupBoxc);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 360, 100, 30));
        label_19->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        enregistrer_c = new QPushButton(groupBoxc);
        enregistrer_c->setObjectName("enregistrer_c");
        enregistrer_c->setGeometry(QRect(10, 410, 130, 40));
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
        dateN_c = new QDateEdit(groupBoxc);
        dateN_c->setObjectName("dateN_c");
        dateN_c->setGeometry(QRect(121, 154, 110, 40));
        dateN_c->setStyleSheet(QString::fromUtf8("#dateN_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#dateN_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#dateN_c QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
""));
        nvpermis_c = new QComboBox(groupBoxc);
        nvpermis_c->addItem(QString());
        nvpermis_c->addItem(QString());
        nvpermis_c->addItem(QString());
        nvpermis_c->addItem(QString());
        nvpermis_c->addItem(QString());
        nvpermis_c->setObjectName("nvpermis_c");
        nvpermis_c->setGeometry(QRect(119, 314, 111, 40));
        nvpermis_c->setStyleSheet(QString::fromUtf8("#nvpermis_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#nvpermis_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#nvpermis_c QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        prenom_c = new QLineEdit(groupBoxc);
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
        adr_c = new QLineEdit(groupBoxc);
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
        tel_c = new QLineEdit(groupBoxc);
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
        email_c = new QLineEdit(groupBoxc);
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
        prog_c = new QLineEdit(groupBoxc);
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
        taper_c = new QLineEdit(tab_5);
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
        filtrer_c = new QComboBox(tab_5);
        filtrer_c->addItem(QString());
        filtrer_c->addItem(QString());
        filtrer_c->setObjectName("filtrer_c");
        filtrer_c->setGeometry(QRect(710, 8, 144, 40));
        filtrer_c->setStyleSheet(QString::fromUtf8("#filtrer_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#filtrer_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#filtrer_c QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        trier_c = new QComboBox(tab_5);
        trier_c->addItem(QString());
        trier_c->addItem(QString());
        trier_c->addItem(QString());
        trier_c->setObjectName("trier_c");
        trier_c->setGeometry(QRect(876, 10, 120, 40));
        trier_c->setStyleSheet(QString::fromUtf8("#trier_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#trier_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#trier_c QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        tableWidget = new QTableWidget(tab_5);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem32);
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
        modifier_c = new QPushButton(tab_5);
        modifier_c->setObjectName("modifier_c");
        modifier_c->setGeometry(QRect(320, 470, 110, 31));
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
        ajouter_c = new QPushButton(tab_5);
        ajouter_c->setObjectName("ajouter_c");
        ajouter_c->setGeometry(QRect(440, 470, 120, 31));
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
        expo_tab_c = new QPushButton(tab_5);
        expo_tab_c->setObjectName("expo_tab_c");
        expo_tab_c->setGeometry(QRect(700, 470, 121, 31));
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
        expo_tab_c->setIcon(icon1);
        conf_rech_c = new QPushButton(tab_5);
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
        supp_c = new QPushButton(tab_5);
        supp_c->setObjectName("supp_c");
        supp_c->setGeometry(QRect(570, 470, 121, 31));
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
        label_23 = new QLabel(tab_5);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(10, 20, 301, 31));
        label_23->setFont(font);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        tab_widget_c->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tab_widget2_c = new QTabWidget(tab_6);
        tab_widget2_c->setObjectName("tab_widget2_c");
        tab_widget2_c->setGeometry(QRect(10, 10, 990, 511));
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
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        selon_stat_c = new QComboBox(tab_7);
        selon_stat_c->addItem(QString());
        selon_stat_c->addItem(QString());
        selon_stat_c->addItem(QString());
        selon_stat_c->setObjectName("selon_stat_c");
        selon_stat_c->setGeometry(QRect(850, 20, 100, 40));
        selon_stat_c->setStyleSheet(QString::fromUtf8("#selon_stat_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#selon_stat_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#selon_stat_c QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        label_31 = new QLabel(tab_7);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(20, 30, 540, 370));
        label_31->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix2/img/Un diagramme en barr.png);"));
        tab_widget2_c->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        label_20 = new QLabel(tab_8);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(10, 30, 130, 30));
        label_20->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        ia_nomcandidat = new QLineEdit(tab_8);
        ia_nomcandidat->setObjectName("ia_nomcandidat");
        ia_nomcandidat->setGeometry(QRect(140, 30, 113, 28));
        ia_nomcandidat->setStyleSheet(QString::fromUtf8("#ia_nomcandidat {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#ia_nomcandidat:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        label_21 = new QLabel(tab_8);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(30, 80, 130, 30));
        label_21->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        label_22 = new QLabel(tab_8);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(170, 120, 540, 260));
        label_22->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/Barre de progression.png);"));
        tab_widget2_c->addTab(tab_8, QString());
        tab_widget_c->addTab(tab_6, QString());
        stackedWidget->addWidget(page_c);
        barre_nav = new QGroupBox(centralwidget);
        barre_nav->setObjectName("barre_nav");
        barre_nav->setGeometry(QRect(10, 90, 200, 641));
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
        fermer_btn->setGeometry(QRect(20, 580, 150, 40));
        fermer_btn->setStyleSheet(QString::fromUtf8(""));
        seance_btn = new QPushButton(barre_nav);
        seance_btn->setObjectName("seance_btn");
        seance_btn->setGeometry(QRect(10, 390, 170, 40));
        seance_btn->setStyleSheet(QString::fromUtf8(""));
        vehicule_btn = new QPushButton(barre_nav);
        vehicule_btn->setObjectName("vehicule_btn");
        vehicule_btn->setGeometry(QRect(10, 350, 170, 40));
        vehicule_btn->setStyleSheet(QString::fromUtf8(""));
        emp_btn = new QPushButton(barre_nav);
        emp_btn->setObjectName("emp_btn");
        emp_btn->setGeometry(QRect(10, 300, 170, 40));
        emp_btn->setStyleSheet(QString::fromUtf8(""));
        moniteur_btn = new QPushButton(barre_nav);
        moniteur_btn->setObjectName("moniteur_btn");
        moniteur_btn->setGeometry(QRect(10, 250, 170, 40));
        moniteur_btn->setStyleSheet(QString::fromUtf8(""));
        candidat_btn = new QPushButton(barre_nav);
        candidat_btn->setObjectName("candidat_btn");
        candidat_btn->setGeometry(QRect(10, 210, 170, 40));
        candidat_btn->setStyleSheet(QString::fromUtf8(""));
        label_30 = new QLabel(barre_nav);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(10, 10, 181, 191));
        label_30->setStyleSheet(QString::fromUtf8("image: url(:/ res/img/logo.png);"));
        barre = new QGroupBox(centralwidget);
        barre->setObjectName("barre");
        barre->setGeometry(QRect(10, 10, 1481, 71));
        barre->setStyleSheet(QString::fromUtf8("#barre {\n"
"    background-color: #0F2434;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"}"));
        titre = new QLabel(barre);
        titre->setObjectName("titre");
        titre->setGeometry(QRect(20, 10, 301, 51));
        QFont font1;
        font1.setPointSize(34);
        titre->setFont(font1);
        titre->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1508, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        widget_v->setCurrentIndex(0);
        tab_fonc_v->setCurrentIndex(0);
        tabWidget_s->setCurrentIndex(0);
        tab_widget_c->setCurrentIndex(1);
        tab_widget2_c->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBoxv->setTitle(QCoreApplication::translate("MainWindow", "Ajout", nullptr));
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

        bon->setText(QCoreApplication::translate("MainWindow", "Bon", nullptr));
        panne->setText(QCoreApplication::translate("MainWindow", "En panne", nullptr));
        entretien->setText(QCoreApplication::translate("MainWindow", "Entretien", nullptr));
        conf_v->setText(QCoreApplication::translate("MainWindow", "Confirmer \342\234\224\357\270\217", nullptr));
        reins_v->setText(QCoreApplication::translate("MainWindow", "R\303\251installer \360\237\224\204", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\360\237\232\227 Gestion des v\303\251hicules", nullptr));
        expo_v->setText(QCoreApplication::translate("MainWindow", "Exporter", nullptr));
        filtrer_v->setItemText(0, QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        filtrer_v->setItemText(1, QCoreApplication::translate("MainWindow", "Type", nullptr));
        filtrer_v->setItemText(2, QCoreApplication::translate("MainWindow", "Marque", nullptr));
        filtrer_v->setItemText(3, QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));

        trier_v->setItemText(0, QCoreApplication::translate("MainWindow", "Trier", nullptr));
        trier_v->setItemText(1, QCoreApplication::translate("MainWindow", "Ann\303\251e", nullptr));
        trier_v->setItemText(2, QCoreApplication::translate("MainWindow", "Kilom\303\251trage", nullptr));

        taper_v->setPlaceholderText(QCoreApplication::translate("MainWindow", "Taper...", nullptr));
        conf_rv->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Confirmer", nullptr));
        supp_v->setText(QCoreApplication::translate("MainWindow", "Supprimer \360\237\227\221\357\270\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_ajout_v->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Matricule", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_ajout_v->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_ajout_v->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Marque", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_ajout_v->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Mod\303\250le", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_ajout_v->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Ann\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_ajout_v->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_ajout_v->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Kilom\303\251trage", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_ajout_v->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Date de r\303\251vision", nullptr));
        widget_v->setTabText(widget_v->indexOf(tab), QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        tab_fonc_v->setTabText(tab_fonc_v->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Matricule", nullptr));
        conf_ai_v->setText(QCoreApplication::translate("MainWindow", "Confirmer \342\234\224\357\270\217", nullptr));
        reins_ai_v->setText(QCoreApplication::translate("MainWindow", "R\303\251installer \360\237\224\204", nullptr));
        tab_fonc_v->setTabText(tab_fonc_v->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Maintenance pr\303\251dictive", nullptr));
        widget_v->setTabText(widget_v->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Fonctionnalit\303\251", nullptr));
        frame_sea->setTitle(QString());
#if QT_CONFIG(whatsthis)
        tabWidget_s->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>autre</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBoxs->setTitle(QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        type_s->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir", nullptr));
        type_s->setItemText(1, QCoreApplication::translate("MainWindow", "Conduite", nullptr));
        type_s->setItemText(2, QCoreApplication::translate("MainWindow", "Code", nullptr));

        label_25->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "D\303\251but_H", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Fin_H", nullptr));
        confirm_ajout_s->setText(QCoreApplication::translate("MainWindow", "Confirmer \342\234\224\357\270\217", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tab_s->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "ID_S\303\251ance", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tab_s->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tab_s->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tab_s->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Heure d\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tab_s->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Heure fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tab_s->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Salle", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tab_s->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Long. d\303\251part", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tab_s->horizontalHeaderItem(7);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Lat. d\303\251part", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tab_s->horizontalHeaderItem(8);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Long. arriv\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tab_s->horizontalHeaderItem(9);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Lat. arriv\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tab_s->horizontalHeaderItem(10);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tab_s->horizontalHeaderItem(11);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        confirm_s->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Confirmer", nullptr));
        exp_s->setText(QCoreApplication::translate("MainWindow", " Exporter", nullptr));
        filtre_s->setText(QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        tri_s->setItemText(0, QCoreApplication::translate("MainWindow", "Trier par", nullptr));
        tri_s->setItemText(1, QCoreApplication::translate("MainWindow", "Date", nullptr));
        tri_s->setItemText(2, QCoreApplication::translate("MainWindow", "Type", nullptr));

        recherche_s->setPlaceholderText(QCoreApplication::translate("MainWindow", "     ID_S\303\251ance", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\360\237\247\221\342\200\215\360\237\217\253 Gestion des s\303\251ances", nullptr));
        tabWidget_s->setTabText(tabWidget_s->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        groupBox_stats->setTitle(QCoreApplication::translate("MainWindow", "Statistiques des S\303\251ances", nullptr));
        label_totalSessions->setText(QCoreApplication::translate("MainWindow", "Total des s\303\251ances: 0", nullptr));
        label_totalHours->setText(QCoreApplication::translate("MainWindow", "Heures totales: 0h", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = stats_s->horizontalHeaderItem(0);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "\303\211l\303\250ve/Moniteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = stats_s->horizontalHeaderItem(1);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Nb s\303\251ances", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = stats_s->horizontalHeaderItem(2);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Heures totales", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = stats_s->horizontalHeaderItem(3);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Type dominant", nullptr));
        refresh_s->setText(QCoreApplication::translate("MainWindow", "Actualiser \360\237\224\201", nullptr));
        tabWidget_s->setTabText(tabWidget_s->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        Details_s->setTitle(QCoreApplication::translate("MainWindow", "D\303\251tails des S\303\251ances", nullptr));
        tabWidget_s->setTabText(tabWidget_s->indexOf(tab_11), QCoreApplication::translate("MainWindow", "Calendrier", nullptr));
        groupBox_map->setTitle(QCoreApplication::translate("MainWindow", "Planification des Trajets", nullptr));
        label_mapView->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        label_routePreview->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        groupBox_route->setTitle(QCoreApplication::translate("MainWindow", "Contr\303\264les de Route", nullptr));
        departure_s->setPlaceholderText(QCoreApplication::translate("MainWindow", "Point de d\303\251part", nullptr));
        destination_s->setPlaceholderText(QCoreApplication::translate("MainWindow", "Destination", nullptr));
        calculateRoute_s->setText(QCoreApplication::translate("MainWindow", "Calculer trajet \360\237\247\255", nullptr));
        label_distance->setText(QCoreApplication::translate("MainWindow", "Distance: -- km", nullptr));
        label_duration->setText(QCoreApplication::translate("MainWindow", "Dur\303\251e: -- min", nullptr));
        saveRoute_s->setText(QCoreApplication::translate("MainWindow", "Sauvegarder trajet \360\237\222\276", nullptr));
        clearRoute_s->setText(QCoreApplication::translate("MainWindow", "Effacer trajet \360\237\227\221\357\270\217", nullptr));
        label_routeStatus->setText(QCoreApplication::translate("MainWindow", "\360\237\223\215 Statut: En attente\\n\360\237\227\272\357\270\217 Pr\303\252t \303\240 calculer", nullptr));
        label_mapTitle->setText(QCoreApplication::translate("MainWindow", "\360\237\227\272\357\270\217 Carte Interactive - Planification des S\303\251ances de Conduite", nullptr));
        mapType_s->setItemText(0, QCoreApplication::translate("MainWindow", "\360\237\214\215 Vue Satellite", nullptr));
        mapType_s->setItemText(1, QCoreApplication::translate("MainWindow", "\360\237\227\272\357\270\217 Vue Carte", nullptr));
        mapType_s->setItemText(2, QCoreApplication::translate("MainWindow", "\360\237\232\227 Vue Trafic", nullptr));

        centerMap_s->setText(QCoreApplication::translate("MainWindow", "\360\237\223\215 Localiser", nullptr));
        tabWidget_s->setTabText(tabWidget_s->indexOf(tab_12), QCoreApplication::translate("MainWindow", "Carte", nullptr));
        frame_gest->setTitle(QString());
        groupBoxc->setTitle(QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom :", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Date naissance :", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Adresse :", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone :", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Email :", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Niveau permis :", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Progression :", nullptr));
        enregistrer_c->setText(QCoreApplication::translate("MainWindow", "Enregistrer \360\237\222\276", nullptr));
        nvpermis_c->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir", nullptr));
        nvpermis_c->setItemText(1, QCoreApplication::translate("MainWindow", "A", nullptr));
        nvpermis_c->setItemText(2, QCoreApplication::translate("MainWindow", "B", nullptr));
        nvpermis_c->setItemText(3, QCoreApplication::translate("MainWindow", "C", nullptr));
        nvpermis_c->setItemText(4, QCoreApplication::translate("MainWindow", "D", nullptr));

        taper_c->setInputMask(QString());
        taper_c->setPlaceholderText(QCoreApplication::translate("MainWindow", "  Recherche", nullptr));
        filtrer_c->setItemText(0, QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        filtrer_c->setItemText(1, QCoreApplication::translate("MainWindow", "ID", nullptr));

        trier_c->setItemText(0, QCoreApplication::translate("MainWindow", "Trier", nullptr));
        trier_c->setItemText(1, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        trier_c->setItemText(2, QCoreApplication::translate("MainWindow", "Date naissance", nullptr));

        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Date naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Niveau permis", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "Progression", nullptr));
        modifier_c->setText(QCoreApplication::translate("MainWindow", "Modifier \342\234\217\357\270\217", nullptr));
        ajouter_c->setText(QCoreApplication::translate("MainWindow", "Ajouter \342\236\225", nullptr));
        expo_tab_c->setText(QCoreApplication::translate("MainWindow", " Exporter", nullptr));
        conf_rech_c->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Confirmer", nullptr));
        supp_c->setText(QCoreApplication::translate("MainWindow", "Supprimer \360\237\227\221\357\270\217", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213Gestion des candidats", nullptr));
        tab_widget_c->setTabText(tab_widget_c->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Ajout Candidats", nullptr));
        selon_stat_c->setItemText(0, QCoreApplication::translate("MainWindow", "Selon", nullptr));
        selon_stat_c->setItemText(1, QCoreApplication::translate("MainWindow", "Age", nullptr));
        selon_stat_c->setItemText(2, QCoreApplication::translate("MainWindow", "Nivaeu permis", nullptr));

        label_31->setText(QString());
        tab_widget2_c->setTabText(tab_widget2_c->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Nom de candidat :", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Progress bar :", nullptr));
        label_22->setText(QString());
        tab_widget2_c->setTabText(tab_widget2_c->indexOf(tab_8), QCoreApplication::translate("MainWindow", "Progression", nullptr));
        tab_widget_c->setTabText(tab_widget_c->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Fonctionnalit\303\251", nullptr));
        barre_nav->setTitle(QString());
        fermer_btn->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Fermer", nullptr));
        seance_btn->setText(QCoreApplication::translate("MainWindow", "\360\237\247\221\342\200\215\360\237\217\253 Gestion S\303\251ances", nullptr));
        vehicule_btn->setText(QCoreApplication::translate("MainWindow", "\360\237\232\227 Gestion V\303\251hicules", nullptr));
        emp_btn->setText(QCoreApplication::translate("MainWindow", "\360\237\222\274 Gestion Employ\303\251s", nullptr));
        moniteur_btn->setText(QCoreApplication::translate("MainWindow", "\360\237\247\221\342\200\215\360\237\222\274Gestion Moniteurs ", nullptr));
        candidat_btn->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213 Gestion Candidats", nullptr));
        label_30->setText(QString());
        barre->setTitle(QString());
        titre->setText(QCoreApplication::translate("MainWindow", "Smart Drive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

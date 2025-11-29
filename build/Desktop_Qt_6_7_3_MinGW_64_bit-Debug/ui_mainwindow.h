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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
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
    QComboBox *type_v;
    QLineEdit *marque_v;
    QLineEdit *modele_v;
    QRadioButton *bon;
    QRadioButton *panne;
    QRadioButton *entretien;
    QLineEdit *kilometrage_v;
    QDateEdit *date_maint_v;
    QPushButton *conf_v;
    QPushButton *reins_v;
    QDateEdit *date_achat_v;
    QPushButton *modif_v;
    QPushButton *expo_v;
    QComboBox *filtrer_v;
    QComboBox *trier_v;
    QLineEdit *taper_v;
    QPushButton *conf_rv;
    QPushButton *supp_v;
    QTableWidget *table_ajout_v;
    QLabel *label_57;
    QLabel *label_63;
    QWidget *tab_2;
    QTabWidget *tab_fonc_v;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *widget_ai;
    QLabel *label_10;
    QPushButton *conf_ai_v;
    QPushButton *reins_ai_v;
    QLineEdit *mat_ai;
    QWidget *page_accueil;
    QGroupBox *frame_a;
    QLabel *bien;
    QLabel *label_37;
    QLabel *quantum;
    QLabel *label_67;
    QLabel *label_68;
    QPushButton *candidat;
    QPushButton *moniteur;
    QPushButton *emp;
    QPushButton *seance;
    QPushButton *vehicule;
    QLabel *label;
    QLabel *label_69;
    QLabel *label_70;
    QLabel *label_71;
    QLabel *label_72;
    QLabel *label_73;
    QWidget *page_emp;
    QGroupBox *frame_emp;
    QTabWidget *tab_widget_E;
    QWidget *tab_13;
    QComboBox *trier_E;
    QLineEdit *taper_E;
    QLabel *label_38;
    QPushButton *supp_E;
    QPushButton *expo_tab_E;
    QPushButton *conf_rech_E;
    QPushButton *modif_E;
    QTableWidget *tab_employes;
    QLabel *label_55;
    QLabel *label_64;
    QGroupBox *groupBoxE;
    QLineEdit *id;
    QLineEdit *prenom;
    QLineEdit *salaire;
    QLineEdit *telephone;
    QComboBox *poste_combo;
    QDateEdit *date_embauche;
    QLineEdit *email;
    QLineEdit *pass;
    QPushButton *conf_E;
    QPushButton *reins_E;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_58;
    QLabel *label_59;
    QLabel *label_60;
    QLabel *label_62;
    QLabel *label_35;
    QLineEdit *nom;
    QWidget *tab_14;
    QTabWidget *tab_widget2_E;
    QWidget *tab_15;
    QComboBox *selon_stat_E;
    QWidget *page_s;
    QGroupBox *frame_sea;
    QTabWidget *tabWidget_s;
    QWidget *tab_9;
    QTableWidget *tab_s;
    QPushButton *confirm_s;
    QPushButton *exp_s;
    QPushButton *filtre_s;
    QComboBox *tri_s;
    QLineEdit *recherche_s;
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
    QLabel *label_50;
    QLineEdit *salle_s;
    QLabel *label_51;
    QLineEdit *lon_dep;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *label_54;
    QLineEdit *lat_ar;
    QLineEdit *lon_ariv;
    QLineEdit *lat_arriv;
    QPushButton *supp_s;
    QLabel *label_36;
    QLabel *label_65;
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
    QPushButton *conf_rech_c;
    QGroupBox *groupBoxc;
    QLabel *label_14;
    QLineEdit *id_c;
    QLabel *label_15;
    QLineEdit *nom_c;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *enregistrer_c;
    QDateEdit *dateN_c;
    QComboBox *nvpermis_c;
    QLineEdit *prenom_c;
    QLineEdit *adr_c;
    QLineEdit *tel_c;
    QLineEdit *email_c;
    QCheckBox *code_c;
    QCheckBox *conduite_c;
    QCheckBox *parc_c;
    QPushButton *modifier_c;
    QComboBox *filtrer_c;
    QComboBox *trier_c;
    QPushButton *supp_c;
    QLineEdit *taper_c;
    QTableWidget *table_candidat;
    QPushButton *expo_tab_c;
    QLabel *label_56;
    QLabel *label_66;
    QWidget *tab_6;
    QTabWidget *tab_widget2_c;
    QWidget *tab_7;
    QComboBox *selon_stat_c;
    QLabel *label_49;
    QWidget *tab_8;
    QLabel *label_11;
    QLineEdit *prog_idcandidat;
    QLabel *label_13;
    QLabel *label_48;
    QWidget *page_m;
    QFrame *frame_m;
    QTabWidget *widget_m;
    QWidget *tab_16;
    QGroupBox *groupBoxm;
    QLabel *label_12;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLineEdit *nom_m;
    QComboBox *specialite;
    QLineEdit *prenom_m;
    QLineEdit *email_monituer;
    QLineEdit *telephone_m;
    QRadioButton *actif;
    QRadioButton *inactif;
    QLineEdit *experience_m;
    QPushButton *reinstaller_mon;
    QPushButton *enregistrer_m;
    QComboBox *filtrer_mon;
    QComboBox *trier_mon;
    QLineEdit *taper_mon;
    QLabel *label_45;
    QPushButton *supp_m;
    QPushButton *expo_tab_m;
    QPushButton *modifier_m;
    QPushButton *conf_rech_m;
    QTableWidget *tab_mon;
    QLabel *label_61;
    QWidget *tab_17;
    QTabWidget *tab_widget2;
    QWidget *tab_18;
    QLabel *label_46;
    QWidget *tab_19;
    QLabel *label_47;
    QPushButton *expo_ai_m;
    QGroupBox *barre_nav;
    QPushButton *fermer_btn;
    QPushButton *seance_btn;
    QPushButton *vehicule_btn;
    QPushButton *emp_btn;
    QPushButton *moniteur_btn;
    QLabel *label_30;
    QPushButton *candidat_btn;
    QPushButton *accueil;
    QGroupBox *barre;
    QLabel *titre;
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
        frame_v->setStyleSheet(QString::fromUtf8("#frame_vt {\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
""));
        frame_v->setFrameShape(QFrame::Shape::StyledPanel);
        frame_v->setFrameShadow(QFrame::Shadow::Raised);
        widget_v = new QTabWidget(frame_v);
        widget_v->setObjectName("widget_v");
        widget_v->setGeometry(QRect(0, 10, 1251, 611));
        widget_v->setStyleSheet(QString::fromUtf8("QTabWidget#widget_v {\n"
"    background-color: #FBFAF5;\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QTabWidget#widget_v::pane {\n"
"    border: 1px solid #C0C0C0;\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 8px;\n"
"    margin-top: -1px;\n"
"    padding: 15px;\n"
"}\n"
"\n"
"QTabWidget#widget_v QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 12px 24px;\n"
"    margin-right: 2px;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    border: 1px solid #0F2434;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget#widget_v QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FFFFFF;\n"
"    border: 1px solid #1D9E3A;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget#widget_v QTabBar::tab:hover:!selected {\n"
"    background-color: #2a4a6a;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QTabWidget#widget_v QTabBar::tab:firs"
                        "t {\n"
"    margin-left: 0px;\n"
"}\n"
"\n"
"QTabWidget#widget_v QTabBar::tab:last {\n"
"    margin-right: 0px;\n"
"}\n"
"\n"
"QTabWidget#widget_v QTabBar {\n"
"    qproperty-drawBase: 0;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBoxv = new QGroupBox(tab);
        groupBoxv->setObjectName("groupBoxv");
        groupBoxv->setGeometry(QRect(10, 70, 361, 461));
        groupBoxv->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
"}\n"
"#groupBoxv{\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
"#groupBoxv::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    background-color: #228B22;\n"
"    color: white;\n"
"    padding: 5px 10px;\n"
"    border-radius: 3px;\n"
"}"));
        label_2 = new QLabel(groupBoxv);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 71, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        label_3 = new QLabel(groupBoxv);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 80, 61, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        label_4 = new QLabel(groupBoxv);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 120, 61, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_5 = new QLabel(groupBoxv);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 170, 61, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_6 = new QLabel(groupBoxv);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 210, 101, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_7 = new QLabel(groupBoxv);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 240, 31, 41));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_8 = new QLabel(groupBoxv);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 290, 91, 31));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_9 = new QLabel(groupBoxv);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 330, 111, 31));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        matricule = new QLineEdit(groupBoxv);
        matricule->setObjectName("matricule");
        matricule->setGeometry(QRect(130, 40, 113, 31));
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
        type_v = new QComboBox(groupBoxv);
        type_v->addItem(QString());
        type_v->addItem(QString());
        type_v->addItem(QString());
        type_v->addItem(QString());
        type_v->addItem(QString());
        type_v->setObjectName("type_v");
        type_v->setGeometry(QRect(130, 90, 111, 26));
        type_v->setStyleSheet(QString::fromUtf8("#type_v {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#type_v QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#type_v:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        marque_v = new QLineEdit(groupBoxv);
        marque_v->setObjectName("marque_v");
        marque_v->setGeometry(QRect(130, 130, 113, 31));
        marque_v->setStyleSheet(QString::fromUtf8("#marque_v {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#marque_v:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        modele_v = new QLineEdit(groupBoxv);
        modele_v->setObjectName("modele_v");
        modele_v->setGeometry(QRect(130, 170, 113, 31));
        modele_v->setStyleSheet(QString::fromUtf8("#modele_v {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#modele_v:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        bon = new QRadioButton(groupBoxv);
        bon->setObjectName("bon");
        bon->setGeometry(QRect(50, 250, 51, 24));
        bon->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        panne = new QRadioButton(groupBoxv);
        panne->setObjectName("panne");
        panne->setGeometry(QRect(210, 250, 91, 24));
        panne->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        entretien = new QRadioButton(groupBoxv);
        entretien->setObjectName("entretien");
        entretien->setGeometry(QRect(110, 250, 91, 24));
        entretien->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        kilometrage_v = new QLineEdit(groupBoxv);
        kilometrage_v->setObjectName("kilometrage_v");
        kilometrage_v->setGeometry(QRect(130, 290, 113, 31));
        kilometrage_v->setStyleSheet(QString::fromUtf8("#kilometrage_v {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#kilometrage_v:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        date_maint_v = new QDateEdit(groupBoxv);
        date_maint_v->setObjectName("date_maint_v");
        date_maint_v->setGeometry(QRect(130, 330, 110, 26));
        date_maint_v->setStyleSheet(QString::fromUtf8("#date_maint_v {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#date_maint_v:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#date_maint_v QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
""));
        conf_v = new QPushButton(groupBoxv);
        conf_v->setObjectName("conf_v");
        conf_v->setGeometry(QRect(10, 370, 131, 29));
        conf_v->setStyleSheet(QString::fromUtf8("#conf_v {\n"
"    background-color: #228B22;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_v:hover {\n"
"    background-color: #28a428;\n"
"}\n"
"\n"
"#conf_v:pressed {\n"
"    background-color: #1c771c;\n"
"}"));
        reins_v = new QPushButton(groupBoxv);
        reins_v->setObjectName("reins_v");
        reins_v->setGeometry(QRect(10, 410, 131, 29));
        reins_v->setStyleSheet(QString::fromUtf8("#reins_v {\n"
"    background-color: #228B22;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#reins_v:hover {\n"
"    background-color: #28a428;\n"
"}\n"
"\n"
"#reins_v:pressed {\n"
"    background-color: #1c771c;\n"
"}"));
        date_achat_v = new QDateEdit(groupBoxv);
        date_achat_v->setObjectName("date_achat_v");
        date_achat_v->setGeometry(QRect(130, 210, 110, 26));
        date_achat_v->setStyleSheet(QString::fromUtf8("#date_achat_v {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#date_achat_v:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#date_achat_v QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
""));
        modif_v = new QPushButton(groupBoxv);
        modif_v->setObjectName("modif_v");
        modif_v->setGeometry(QRect(150, 370, 121, 31));
        modif_v->setStyleSheet(QString::fromUtf8("#modif_v {\n"
"    background-color: #228B22;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#modif_v:hover {\n"
"    background-color: #28a428;\n"
"}\n"
"\n"
"#modif_v:pressed {\n"
"    background-color: #1c771c;\n"
"}"));
        expo_v = new QPushButton(tab);
        expo_v->setObjectName("expo_v");
        expo_v->setGeometry(QRect(510, 500, 121, 31));
        expo_v->setStyleSheet(QString::fromUtf8("#expo_v {\n"
"    background-color: #007BFF;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#expo_v:hover {\n"
"    background-color: #0056B3;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pdf/img/pdf.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        expo_v->setIcon(icon);
        filtrer_v = new QComboBox(tab);
        filtrer_v->addItem(QString());
        filtrer_v->addItem(QString());
        filtrer_v->addItem(QString());
        filtrer_v->addItem(QString());
        filtrer_v->setObjectName("filtrer_v");
        filtrer_v->setGeometry(QRect(380, 50, 91, 31));
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
        trier_v->setGeometry(QRect(480, 50, 231, 31));
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
        taper_v->setGeometry(QRect(880, 40, 141, 41));
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
        conf_rv->setGeometry(QRect(1030, 40, 141, 41));
        conf_rv->setStyleSheet(QString::fromUtf8("#conf_rv {\n"
"    background-color: #6F42C1;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_rv:hover {\n"
"    background-color: #5A2D9C;\n"
"}"));
        supp_v = new QPushButton(tab);
        supp_v->setObjectName("supp_v");
        supp_v->setGeometry(QRect(380, 500, 121, 31));
        supp_v->setStyleSheet(QString::fromUtf8("#supp_v {\n"
"    background-color: #DC3545;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#supp_v:hover {\n"
"    background-color: #C82333;\n"
"}"));
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
        table_ajout_v->setGeometry(QRect(380, 90, 801, 401));
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
        label_57 = new QLabel(tab);
        label_57->setObjectName("label_57");
        label_57->setGeometry(QRect(20, 10, 61, 61));
        QFont font;
        font.setPointSize(14);
        label_57->setFont(font);
        label_57->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"image: url(:/img_veh/img/icons_prj_cpp/Screenshot_2025-11-15_103244-removebg-preview.png);"));
        label_63 = new QLabel(tab);
        label_63->setObjectName("label_63");
        label_63->setGeometry(QRect(70, 20, 201, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setBold(true);
        label_63->setFont(font1);
        label_63->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(0, 0, 0);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size:  20px;\n"
"    font-weight: bold;\n"
"    padding: 4px 6px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    margin: 2px;\n"
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
"    background-color: #228B22;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_ai_v:hover {\n"
"    background-color: #28a428;\n"
"}\n"
"\n"
"#conf_ai_v:pressed {\n"
"    background-color: #1c771c;\n"
"}"));
        reins_ai_v = new QPushButton(widget_ai);
        reins_ai_v->setObjectName("reins_ai_v");
        reins_ai_v->setGeometry(QRect(150, 80, 131, 29));
        reins_ai_v->setStyleSheet(QString::fromUtf8("#reins_ai_v {\n"
"    background-color: #228B22;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#reins_ai_v:hover {\n"
"    background-color: #28a428;\n"
"}\n"
"\n"
"#reins_ai_v:pressed {\n"
"    background-color: #1c771c;\n"
"}"));
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
        page_accueil = new QWidget();
        page_accueil->setObjectName("page_accueil");
        frame_a = new QGroupBox(page_accueil);
        frame_a->setObjectName("frame_a");
        frame_a->setGeometry(QRect(20, 30, 1271, 641));
        frame_a->setStyleSheet(QString::fromUtf8("#frame_a {\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
""));
        bien = new QLabel(frame_a);
        bien->setObjectName("bien");
        bien->setGeometry(QRect(10, 120, 741, 141));
        bien->setStyleSheet(QString::fromUtf8("#bien {\n"
"    color: #0F2434;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 15px;\n"
"    font-weight: 550;\n"
"    text-align: center;\n"
"    padding: 18px 25px;\n"
"    background-color: rgba(251, 250, 245, 0.8);\n"
"    border-left: 4px solid #1D9E3A;\n"
"    border-radius: 8px;\n"
"    margin: 15px;\n"
"    line-height: 1.6;\n"
"    letter-spacing: 0.2px;\n"
"    box-shadow: 0 2px 6px rgba(15, 36, 52, 0.1);\n"
"}"));
        label_37 = new QLabel(frame_a);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(810, 100, 181, 181));
        label_37->setStyleSheet(QString::fromUtf8("image: url(:/ res/img/logo.png);"));
        quantum = new QLabel(frame_a);
        quantum->setObjectName("quantum");
        quantum->setGeometry(QRect(10, 280, 741, 141));
        quantum->setStyleSheet(QString::fromUtf8("#quantum {\n"
"    color: #0F2434;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 15px;\n"
"    font-weight: 550;\n"
"    text-align: center;\n"
"    padding: 18px 25px;\n"
"    background-color: rgba(251, 250, 245, 0.8);\n"
"    border-left: 4px solid #1D9E3A;\n"
"    border-radius: 8px;\n"
"    margin: 15px;\n"
"    line-height: 1.6;\n"
"    letter-spacing: 0.2px;\n"
"    box-shadow: 0 2px 6px rgba(15, 36, 52, 0.1);\n"
"}"));
        label_67 = new QLabel(frame_a);
        label_67->setObjectName("label_67");
        label_67->setGeometry(QRect(100, 40, 101, 41));
        label_67->setFont(font1);
        label_67->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(0, 0, 0);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size:  20px;\n"
"    font-weight: bold;\n"
"    padding: 4px 6px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    margin: 2px;\n"
"}"));
        label_68 = new QLabel(frame_a);
        label_68->setObjectName("label_68");
        label_68->setGeometry(QRect(40, 30, 61, 61));
        label_68->setFont(font1);
        label_68->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/icons_prj_cpp/image-removebg-preview.png);"));
        candidat = new QPushButton(frame_a);
        candidat->setObjectName("candidat");
        candidat->setGeometry(QRect(30, 490, 141, 111));
        candidat->setStyleSheet(QString::fromUtf8("#vehicule,\n"
"#seance,\n"
"#emp,\n"
"#candidat,\n"
"#moniteur {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: color 0.3s, transform 0.1s;\n"
"    font-size: 11px;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 0.3px;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"#vehicule:hover,\n"
"#seance:hover,\n"
"#emp:hover,\n"
"#candidat:hover,\n"
"#moniteur:hover {\n"
"    color: #1D9E3A;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#vehicule:pressed,\n"
"#seance:pressed,\n"
"#emp:pressed,\n"
"#candidat:pressed,\n"
"#moniteur:pressed {\n"
"    color: #1D9E3A;\n"
"    transform: scale(0.98);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/candidat_icon/img/icons_prj_cpp/Screenshot_2025-11-15_103429-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        candidat->setIcon(icon1);
        candidat->setIconSize(QSize(100, 100));
        moniteur = new QPushButton(frame_a);
        moniteur->setObjectName("moniteur");
        moniteur->setGeometry(QRect(200, 490, 141, 111));
        moniteur->setStyleSheet(QString::fromUtf8("#vehicule,\n"
"#seance,\n"
"#emp,\n"
"#candidat,\n"
"#moniteur {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: color 0.3s, transform 0.1s;\n"
"    font-size: 11px;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 0.3px;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"#vehicule:hover,\n"
"#seance:hover,\n"
"#emp:hover,\n"
"#candidat:hover,\n"
"#moniteur:hover {\n"
"    color: #1D9E3A;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#vehicule:pressed,\n"
"#seance:pressed,\n"
"#emp:pressed,\n"
"#candidat:pressed,\n"
"#moniteur:pressed {\n"
"    color: #1D9E3A;\n"
"    transform: scale(0.98);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/img/icons_prj_cpp/Screenshot_2025-11-15_103718-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        moniteur->setIcon(icon2);
        moniteur->setIconSize(QSize(100, 100));
        emp = new QPushButton(frame_a);
        emp->setObjectName("emp");
        emp->setGeometry(QRect(380, 490, 141, 111));
        emp->setStyleSheet(QString::fromUtf8("#vehicule,\n"
"#seance,\n"
"#emp,\n"
"#candidat,\n"
"#moniteur {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: color 0.3s, transform 0.1s;\n"
"    font-size: 11px;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 0.3px;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"#vehicule:hover,\n"
"#seance:hover,\n"
"#emp:hover,\n"
"#candidat:hover,\n"
"#moniteur:hover {\n"
"    color: #1D9E3A;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#vehicule:pressed,\n"
"#seance:pressed,\n"
"#emp:pressed,\n"
"#candidat:pressed,\n"
"#moniteur:pressed {\n"
"    color: #1D9E3A;\n"
"    transform: scale(0.98);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/img/icons_prj_cpp/Screenshot_2025-11-15_103406-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        emp->setIcon(icon3);
        emp->setIconSize(QSize(100, 100));
        seance = new QPushButton(frame_a);
        seance->setObjectName("seance");
        seance->setGeometry(QRect(560, 490, 141, 111));
        seance->setStyleSheet(QString::fromUtf8("#vehicule,\n"
"#seance,\n"
"#emp,\n"
"#candidat,\n"
"#moniteur {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: color 0.3s, transform 0.1s;\n"
"    font-size: 11px;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 0.3px;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"#vehicule:hover,\n"
"#seance:hover,\n"
"#emp:hover,\n"
"#candidat:hover,\n"
"#moniteur:hover {\n"
"    color: #1D9E3A;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#vehicule:pressed,\n"
"#seance:pressed,\n"
"#emp:pressed,\n"
"#candidat:pressed,\n"
"#moniteur:pressed {\n"
"    color: #1D9E3A;\n"
"    transform: scale(0.98);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/img/icons_prj_cpp/Screenshot_2025-11-15_103822-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        seance->setIcon(icon4);
        seance->setIconSize(QSize(100, 100));
        vehicule = new QPushButton(frame_a);
        vehicule->setObjectName("vehicule");
        vehicule->setGeometry(QRect(740, 490, 141, 111));
        vehicule->setStyleSheet(QString::fromUtf8("#vehicule,\n"
"#seance,\n"
"#emp,\n"
"#candidat,\n"
"#moniteur {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: color 0.3s, transform 0.1s;\n"
"    font-size: 11px;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 0.3px;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"#vehicule:hover,\n"
"#seance:hover,\n"
"#emp:hover,\n"
"#candidat:hover,\n"
"#moniteur:hover {\n"
"    color: #1D9E3A;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#vehicule:pressed,\n"
"#seance:pressed,\n"
"#emp:pressed,\n"
"#candidat:pressed,\n"
"#moniteur:pressed {\n"
"    color: #1D9E3A;\n"
"    transform: scale(0.98);\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img_veh/img/icons_prj_cpp/Screenshot_2025-11-15_103244-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        vehicule->setIcon(icon5);
        vehicule->setIconSize(QSize(100, 100));
        label = new QLabel(frame_a);
        label->setObjectName("label");
        label->setGeometry(QRect(760, 280, 281, 161));
        label->setStyleSheet(QString::fromUtf8("image: url(:/logo/img/icons_prj_cpp/logo_eqp.png);"));
        label_69 = new QLabel(frame_a);
        label_69->setObjectName("label_69");
        label_69->setGeometry(QRect(40, 450, 121, 41));
        label_69->setFont(font1);
        label_69->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(0, 0, 0);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size:  20px;\n"
"    font-weight: bold;\n"
"    padding: 4px 6px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    margin: 2px;\n"
"}"));
        label_70 = new QLabel(frame_a);
        label_70->setObjectName("label_70");
        label_70->setGeometry(QRect(200, 450, 121, 41));
        label_70->setFont(font1);
        label_70->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(0, 0, 0);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size:  20px;\n"
"    font-weight: bold;\n"
"    padding: 4px 6px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    margin: 2px;\n"
"}"));
        label_71 = new QLabel(frame_a);
        label_71->setObjectName("label_71");
        label_71->setGeometry(QRect(390, 450, 121, 41));
        label_71->setFont(font1);
        label_71->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(0, 0, 0);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size:  20px;\n"
"    font-weight: bold;\n"
"    padding: 4px 6px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    margin: 2px;\n"
"}"));
        label_72 = new QLabel(frame_a);
        label_72->setObjectName("label_72");
        label_72->setGeometry(QRect(570, 450, 121, 41));
        label_72->setFont(font1);
        label_72->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(0, 0, 0);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size:  20px;\n"
"    font-weight: bold;\n"
"    padding: 4px 6px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    margin: 2px;\n"
"}"));
        label_73 = new QLabel(frame_a);
        label_73->setObjectName("label_73");
        label_73->setGeometry(QRect(750, 450, 121, 41));
        label_73->setFont(font1);
        label_73->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(0, 0, 0);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size:  20px;\n"
"    font-weight: bold;\n"
"    padding: 4px 6px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    margin: 2px;\n"
"}"));
        stackedWidget->addWidget(page_accueil);
        page_emp = new QWidget();
        page_emp->setObjectName("page_emp");
        frame_emp = new QGroupBox(page_emp);
        frame_emp->setObjectName("frame_emp");
        frame_emp->setGeometry(QRect(20, 20, 1271, 641));
        frame_emp->setStyleSheet(QString::fromUtf8("#frame_emp {\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
""));
        tab_widget_E = new QTabWidget(frame_emp);
        tab_widget_E->setObjectName("tab_widget_E");
        tab_widget_E->setGeometry(QRect(0, 10, 1251, 601));
        tab_widget_E->setStyleSheet(QString::fromUtf8("QTabWidget#tab_widget_E {\n"
"    background-color: #FBFAF5;\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_E::pane {\n"
"    border: 1px solid #C0C0C0;\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 8px;\n"
"    margin-top: -1px;\n"
"    padding: 15px;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_E QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 12px 24px;\n"
"    margin-right: 2px;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    border: 1px solid #0F2434;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_E QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FFFFFF;\n"
"    border: 1px solid #1D9E3A;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_E QTabBar::tab:hover:!selected {\n"
"    background-color: #2a4a6a;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QTabWidget#tab_wi"
                        "dget_E QTabBar::tab:first {\n"
"    margin-left: 0px;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_E QTabBar::tab:last {\n"
"    margin-right: 0px;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_E QTabBar {\n"
"    qproperty-drawBase: 0;\n"
"}"));
        tab_13 = new QWidget();
        tab_13->setObjectName("tab_13");
        trier_E = new QComboBox(tab_13);
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->addItem(QString());
        trier_E->setObjectName("trier_E");
        trier_E->setGeometry(QRect(310, 60, 81, 31));
        trier_E->setStyleSheet(QString::fromUtf8("#trier_E {\n"
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
"}"));
        taper_E = new QLineEdit(tab_13);
        taper_E->setObjectName("taper_E");
        taper_E->setGeometry(QRect(910, 60, 141, 31));
        taper_E->setStyleSheet(QString::fromUtf8("#taper_E {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#taper_E:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        label_38 = new QLabel(tab_13);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(690, 70, 211, 20));
        label_38->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        supp_E = new QPushButton(tab_13);
        supp_E->setObjectName("supp_E");
        supp_E->setGeometry(QRect(430, 490, 121, 31));
        supp_E->setStyleSheet(QString::fromUtf8("#supp_E {\n"
"    background-color: #DC3545;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#supp_E:hover {\n"
"    background-color: #C82333;\n"
"}"));
        expo_tab_E = new QPushButton(tab_13);
        expo_tab_E->setObjectName("expo_tab_E");
        expo_tab_E->setGeometry(QRect(1080, 490, 121, 31));
        expo_tab_E->setStyleSheet(QString::fromUtf8("#expo_tab_E {\n"
"    background-color: #007BFF;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#expo_tab_E:hover {\n"
"    background-color: #0056B3;\n"
"}"));
        expo_tab_E->setIcon(icon);
        conf_rech_E = new QPushButton(tab_13);
        conf_rech_E->setObjectName("conf_rech_E");
        conf_rech_E->setGeometry(QRect(1060, 60, 131, 31));
        conf_rech_E->setStyleSheet(QString::fromUtf8("#conf_rech_E {\n"
"    background-color: #6F42C1;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_rech_E:hover {\n"
"    background-color: #5A2D9C;\n"
"}"));
        modif_E = new QPushButton(tab_13);
        modif_E->setObjectName("modif_E");
        modif_E->setGeometry(QRect(310, 490, 110, 31));
        modif_E->setStyleSheet(QString::fromUtf8("#modif_E {\n"
"    background-color: #228B22;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"\n"
"#modifier_E:hover {\n"
"    background-color: #28a428;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#modifier_E:pressed {\n"
"    background-color: #1c771c;\n"
"    transform: scale(0.98);\n"
"}"));
        tab_employes = new QTableWidget(tab_13);
        if (tab_employes->columnCount() < 9)
            tab_employes->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tab_employes->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tab_employes->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tab_employes->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tab_employes->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tab_employes->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tab_employes->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tab_employes->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tab_employes->setHorizontalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tab_employes->setHorizontalHeaderItem(8, __qtablewidgetitem16);
        if (tab_employes->rowCount() < 9)
            tab_employes->setRowCount(9);
        tab_employes->setObjectName("tab_employes");
        tab_employes->setGeometry(QRect(310, 100, 891, 381));
        tab_employes->setStyleSheet(QString::fromUtf8("/* Main table styling */\n"
"#tab_employes {\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #0F2434;\n"
"    gridline-color: #0F2434;\n"
"    alternate-background-color: #E8E8E8;\n"
"}\n"
"\n"
"/* Table header styling - make columns visible */\n"
"#tab_employes QHeaderView::section {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px;\n"
"    border: 1px solid #1D9E3A;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"/* Table items/cells styling */\n"
"#tab_employes::item {\n"
"    border: 1px solid #0F2434;\n"
"    padding: 8px;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"/* Make sure text is visible in cells */\n"
"#tab_employes::item {\n"
"    color: #0F2434;\n"
"    background-color: #FBFAF5;\n"
"}\n"
"\n"
"/* Alternate row coloring */\n"
"#tab_employes::item:alternate {\n"
"    background-color: #F0F0F0;\n"
"}\n"
"\n"
"/* Hover effect on rows */\n"
"#tab_employes::item:hover {\n"
"    background-color: #E0E0E0;\n"
"    col"
                        "or: #0F2434;\n"
"}\n"
"\n"
"/* Selected row styling */\n"
"#tab_employes::item:selected {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"}\n"
"\n"
"/* Ensure the table view itself has proper borders */\n"
"#tab_employes QTableView {\n"
"    gridline-color: #0F2434;\n"
"    border: 2px solid #0F2434;\n"
"}\n"
"\n"
"/* Corner button styling */\n"
"#tab_employes QTableCornerButton::section {\n"
"    background-color: #0F2434;\n"
"    border: 1px solid #0F2434;\n"
"}"));
        tab_employes->setColumnCount(9);
        label_55 = new QLabel(tab_13);
        label_55->setObjectName("label_55");
        label_55->setGeometry(QRect(10, 0, 41, 41));
        label_55->setFont(font);
        label_55->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"image: url(:/new/prefix1/img/icons_prj_cpp/Screenshot_2025-11-15_103406-removebg-preview.png);"));
        label_64 = new QLabel(tab_13);
        label_64->setObjectName("label_64");
        label_64->setGeometry(QRect(50, 0, 201, 41));
        label_64->setFont(font1);
        label_64->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(0, 0, 0);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size:  20px;\n"
"    font-weight: bold;\n"
"    padding: 4px 6px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    margin: 2px;\n"
"}"));
        groupBoxE = new QGroupBox(tab_13);
        groupBoxE->setObjectName("groupBoxE");
        groupBoxE->setGeometry(QRect(0, 50, 291, 471));
        groupBoxE->setStyleSheet(QString::fromUtf8("#groupBoxE {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
"\n"
"#groupBoxE::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    background-color: #228B22;\n"
"    color: white;\n"
"    padding: 5px 10px;\n"
"    border-radius: 3px;\n"
"}"));
        id = new QLineEdit(groupBoxE);
        id->setObjectName("id");
        id->setGeometry(QRect(150, 40, 113, 31));
        id->setStyleSheet(QString::fromUtf8("#id {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}"));
        prenom = new QLineEdit(groupBoxE);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(150, 80, 113, 31));
        prenom->setStyleSheet(QString::fromUtf8("#prenom {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}"));
        salaire = new QLineEdit(groupBoxE);
        salaire->setObjectName("salaire");
        salaire->setGeometry(QRect(150, 130, 113, 31));
        salaire->setStyleSheet(QString::fromUtf8("#salaire {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}"));
        telephone = new QLineEdit(groupBoxE);
        telephone->setObjectName("telephone");
        telephone->setGeometry(QRect(150, 170, 113, 31));
        telephone->setStyleSheet(QString::fromUtf8("#telephone {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}"));
        poste_combo = new QComboBox(groupBoxE);
        poste_combo->addItem(QString());
        poste_combo->addItem(QString());
        poste_combo->addItem(QString());
        poste_combo->addItem(QString());
        poste_combo->addItem(QString());
        poste_combo->setObjectName("poste_combo");
        poste_combo->setGeometry(QRect(150, 250, 111, 31));
        poste_combo->setStyleSheet(QString::fromUtf8("#poste_combo{\n"
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
"}"));
        date_embauche = new QDateEdit(groupBoxE);
        date_embauche->setObjectName("date_embauche");
        date_embauche->setGeometry(QRect(150, 290, 110, 26));
        date_embauche->setStyleSheet(QString::fromUtf8("#date_embauche {\n"
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
        email = new QLineEdit(groupBoxE);
        email->setObjectName("email");
        email->setGeometry(QRect(150, 330, 113, 31));
        email->setStyleSheet(QString::fromUtf8("#email {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}"));
        pass = new QLineEdit(groupBoxE);
        pass->setObjectName("pass");
        pass->setGeometry(QRect(150, 370, 113, 31));
        pass->setStyleSheet(QString::fromUtf8("#pass {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}"));
        conf_E = new QPushButton(groupBoxE);
        conf_E->setObjectName("conf_E");
        conf_E->setGeometry(QRect(10, 420, 131, 29));
        conf_E->setStyleSheet(QString::fromUtf8("#conf_E {\n"
"    background-color: #228B22;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"\n"
"#confirmer_E:hover {\n"
"    background-color: #28a428;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#confirmer_E:pressed {\n"
"    background-color: #1c771c;\n"
"    transform: scale(0.98);\n"
"}"));
        conf_E->setAutoDefault(false);
        conf_E->setFlat(false);
        reins_E = new QPushButton(groupBoxE);
        reins_E->setObjectName("reins_E");
        reins_E->setGeometry(QRect(150, 420, 131, 29));
        reins_E->setStyleSheet(QString::fromUtf8("#reins_E {\n"
"    background-color: #228B22;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"\n"
"#reinstaller_E:hover {\n"
"    background-color: #28a428;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#reinstaller_E:pressed {\n"
"    background-color: #1c771c;\n"
"    transform: scale(0.98);\n"
"}"));
        label_31 = new QLabel(groupBoxE);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(10, 40, 71, 31));
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 9pt \"Segoe UI\";"));
        label_32 = new QLabel(groupBoxE);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(10, 80, 71, 31));
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 9pt \"Segoe UI\";"));
        label_33 = new QLabel(groupBoxE);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(10, 130, 61, 31));
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 9pt \"Segoe UI\";"));
        label_34 = new QLabel(groupBoxE);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(10, 170, 61, 31));
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 9pt \"Segoe UI\";"));
        label_58 = new QLabel(groupBoxE);
        label_58->setObjectName("label_58");
        label_58->setGeometry(QRect(10, 250, 61, 31));
        label_58->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 9pt \"Segoe UI\";"));
        label_59 = new QLabel(groupBoxE);
        label_59->setObjectName("label_59");
        label_59->setGeometry(QRect(10, 290, 131, 31));
        label_59->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 9pt \"Segoe UI\";"));
        label_60 = new QLabel(groupBoxE);
        label_60->setObjectName("label_60");
        label_60->setGeometry(QRect(10, 330, 71, 31));
        label_60->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 9pt \"Segoe UI\";"));
        label_62 = new QLabel(groupBoxE);
        label_62->setObjectName("label_62");
        label_62->setGeometry(QRect(10, 370, 101, 31));
        label_62->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 9pt \"Segoe UI\";"));
        label_35 = new QLabel(groupBoxE);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(10, 210, 81, 31));
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 9pt \"Segoe UI\";"));
        nom = new QLineEdit(groupBoxE);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(150, 210, 113, 31));
        nom->setStyleSheet(QString::fromUtf8("#nom{\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}"));
        tab_widget_E->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName("tab_14");
        tab_widget2_E = new QTabWidget(tab_14);
        tab_widget2_E->setObjectName("tab_widget2_E");
        tab_widget2_E->setGeometry(QRect(10, 20, 1021, 471));
        tab_widget2_E->setStyleSheet(QString::fromUtf8("#tab_widget2_E {\n"
"    background-color: #FBFAF5;\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"#tab_widget2_E::pane {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    background-color: #FBFAF5;\n"
"}\n"
"\n"
"#tab_widget2_E QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px 20px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    margin-right: 2px;\n"
"}\n"
"\n"
"#tab_widget2_E QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FBFAF5;\n"
"}\n"
"\n"
"#tab_widget2_E QTabBar::tab:hover {\n"
"    background-color: #30AA2C;\n"
"    color: #FBFAF5;\n"
"}\n"
""));
        tab_15 = new QWidget();
        tab_15->setObjectName("tab_15");
        selon_stat_E = new QComboBox(tab_15);
        selon_stat_E->addItem(QString());
        selon_stat_E->addItem(QString());
        selon_stat_E->addItem(QString());
        selon_stat_E->setObjectName("selon_stat_E");
        selon_stat_E->setGeometry(QRect(860, 40, 100, 40));
        selon_stat_E->setStyleSheet(QString::fromUtf8("#selon_stat_E {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#selon_stat_E:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#selon_stat_E QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        tab_widget2_E->addTab(tab_15, QString());
        tab_widget_E->addTab(tab_14, QString());
        stackedWidget->addWidget(page_emp);
        page_s = new QWidget();
        page_s->setObjectName("page_s");
        frame_sea = new QGroupBox(page_s);
        frame_sea->setObjectName("frame_sea");
        frame_sea->setGeometry(QRect(20, 20, 1271, 641));
        frame_sea->setStyleSheet(QString::fromUtf8("#frame_sea {\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}"));
        tabWidget_s = new QTabWidget(frame_sea);
        tabWidget_s->setObjectName("tabWidget_s");
        tabWidget_s->setGeometry(QRect(0, 10, 1251, 611));
        tabWidget_s->setStyleSheet(QString::fromUtf8("QTabWidget#tabWidget_s {\n"
"    background-color: #FBFAF5;\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QTabWidget#tabWidget_s::pane {\n"
"    border: 1px solid #C0C0C0;\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 8px;\n"
"    margin-top: -1px;\n"
"    padding: 15px;\n"
"}\n"
"\n"
"QTabWidget#tabWidget_s QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 12px 24px;\n"
"    margin-right: 2px;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    border: 1px solid #0F2434;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget#tabWidget_s QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FFFFFF;\n"
"    border: 1px solid #1D9E3A;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget#tabWidget_s QTabBar::tab:hover:!selected {\n"
"    background-color: #2a4a6a;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QTabWidget#tabWidget_s"
                        " QTabBar::tab:first {\n"
"    margin-left: 0px;\n"
"}\n"
"\n"
"QTabWidget#tabWidget_s QTabBar::tab:last {\n"
"    margin-right: 0px;\n"
"}\n"
"\n"
"QTabWidget#tabWidget_s QTabBar {\n"
"    qproperty-drawBase: 0;\n"
"}"));
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        tab_s = new QTableWidget(tab_9);
        if (tab_s->columnCount() < 12)
            tab_s->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(5, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(6, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(7, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(8, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(9, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(10, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(11, __qtablewidgetitem28);
        tab_s->setObjectName("tab_s");
        tab_s->setGeometry(QRect(320, 90, 891, 391));
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
        confirm_s->setGeometry(QRect(1080, 50, 121, 31));
        confirm_s->setStyleSheet(QString::fromUtf8("#confirm_s {\n"
"    background-color: #6F42C1;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#confirm_s:hover {\n"
"    background-color: #5A2D9C;\n"
"}"));
        exp_s = new QPushButton(tab_9);
        exp_s->setObjectName("exp_s");
        exp_s->setGeometry(QRect(500, 490, 141, 31));
        exp_s->setStyleSheet(QString::fromUtf8("#exp_s {\n"
"    background-color: #007BFF;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#exp_s:hover {\n"
"    background-color: #0056B3;\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/res2/img/excel.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exp_s->setIcon(icon6);
        filtre_s = new QPushButton(tab_9);
        filtre_s->setObjectName("filtre_s");
        filtre_s->setGeometry(QRect(440, 50, 90, 29));
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
        tri_s->setGeometry(QRect(320, 50, 111, 28));
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
        recherche_s->setGeometry(QRect(950, 50, 121, 31));
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
        groupBoxs = new QGroupBox(tab_9);
        groupBoxs->setObjectName("groupBoxs");
        groupBoxs->setGeometry(QRect(0, 50, 291, 481));
        groupBoxs->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
"}\n"
"#groupBoxs {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
"#groupBoxs::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    background-color: #228B22;\n"
"    color: white;\n"
"    padding: 5px 10px;\n"
"    border-radius: 3px;\n"
"}"));
        ID_s = new QLineEdit(groupBoxs);
        ID_s->setObjectName("ID_s");
        ID_s->setGeometry(QRect(100, 40, 151, 31));
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
        label_24->setGeometry(QRect(10, 40, 63, 41));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        type_s = new QComboBox(groupBoxs);
        type_s->addItem(QString());
        type_s->addItem(QString());
        type_s->addItem(QString());
        type_s->setObjectName("type_s");
        type_s->setGeometry(QRect(100, 80, 151, 31));
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
        date_s->setGeometry(QRect(100, 120, 151, 31));
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
        deb_s->setGeometry(QRect(100, 160, 151, 31));
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
        fin_s->setGeometry(QRect(100, 200, 151, 31));
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
        label_25->setGeometry(QRect(10, 120, 63, 31));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_26 = new QLabel(groupBoxs);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 160, 63, 31));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_27 = new QLabel(groupBoxs);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 200, 63, 31));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        confirm_ajout_s = new QPushButton(groupBoxs);
        confirm_ajout_s->setObjectName("confirm_ajout_s");
        confirm_ajout_s->setGeometry(QRect(10, 440, 131, 31));
        confirm_ajout_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #228B22;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #28a428;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1c771c;\n"
"    transform: scale(0.98);\n"
"}"));
        label_28 = new QLabel(groupBoxs);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(10, 80, 63, 31));
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_50 = new QLabel(groupBoxs);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(10, 240, 63, 31));
        label_50->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        salle_s = new QLineEdit(groupBoxs);
        salle_s->setObjectName("salle_s");
        salle_s->setGeometry(QRect(100, 240, 151, 31));
        salle_s->setStyleSheet(QString::fromUtf8("#salle_s {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#salle_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        label_51 = new QLabel(groupBoxs);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(10, 280, 91, 31));
        label_51->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        lon_dep = new QLineEdit(groupBoxs);
        lon_dep->setObjectName("lon_dep");
        lon_dep->setGeometry(QRect(100, 280, 151, 31));
        lon_dep->setStyleSheet(QString::fromUtf8("#lon_dep {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#salle_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        label_52 = new QLabel(groupBoxs);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(10, 320, 91, 31));
        label_52->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_53 = new QLabel(groupBoxs);
        label_53->setObjectName("label_53");
        label_53->setGeometry(QRect(10, 360, 91, 31));
        label_53->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_54 = new QLabel(groupBoxs);
        label_54->setObjectName("label_54");
        label_54->setGeometry(QRect(10, 400, 91, 31));
        label_54->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        lat_ar = new QLineEdit(groupBoxs);
        lat_ar->setObjectName("lat_ar");
        lat_ar->setGeometry(QRect(100, 320, 151, 31));
        lat_ar->setStyleSheet(QString::fromUtf8("#lat_ar {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#salle_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        lon_ariv = new QLineEdit(groupBoxs);
        lon_ariv->setObjectName("lon_ariv");
        lon_ariv->setGeometry(QRect(100, 360, 151, 31));
        lon_ariv->setStyleSheet(QString::fromUtf8("#lon_ariv {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#salle_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        lat_arriv = new QLineEdit(groupBoxs);
        lat_arriv->setObjectName("lat_arriv");
        lat_arriv->setGeometry(QRect(100, 400, 151, 31));
        lat_arriv->setStyleSheet(QString::fromUtf8("#lat_arriv {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#salle_s:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}"));
        supp_s = new QPushButton(tab_9);
        supp_s->setObjectName("supp_s");
        supp_s->setGeometry(QRect(320, 490, 171, 31));
        supp_s->setStyleSheet(QString::fromUtf8("#supp_s {\n"
"    background-color: #DC3545;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#supp_s:hover {\n"
"    background-color: #C82333;\n"
"}"));
        label_36 = new QLabel(tab_9);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(10, 0, 51, 41));
        label_36->setFont(font);
        label_36->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/icons_prj_cpp/Screenshot_2025-11-15_103822-removebg-preview.png);"));
        label_65 = new QLabel(tab_9);
        label_65->setObjectName("label_65");
        label_65->setGeometry(QRect(50, 0, 201, 41));
        label_65->setFont(font1);
        label_65->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(0, 0, 0);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size:  20px;\n"
"    font-weight: bold;\n"
"    padding: 4px 6px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    margin: 2px;\n"
"}"));
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
"    background-color: #228B22;\n"
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
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(1, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(2, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(3, __qtablewidgetitem32);
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
"    background-color: #228B22;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #28a428;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1c771c;\n"
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
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}"));
        tab_widget_c = new QTabWidget(frame_gest);
        tab_widget_c->setObjectName("tab_widget_c");
        tab_widget_c->setGeometry(QRect(0, 10, 1251, 631));
        tab_widget_c->setStyleSheet(QString::fromUtf8("QTabWidget#tab_widget_c {\n"
"    background-color: #FBFAF5;\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_c::pane {\n"
"    border: 1px solid #C0C0C0;\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 8px;\n"
"    margin-top: -1px;\n"
"    padding: 15px;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_c QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 12px 24px;\n"
"    margin-right: 2px;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    border: 1px solid #0F2434;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_c QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FFFFFF;\n"
"    border: 1px solid #1D9E3A;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_c QTabBar::tab:hover:!selected {\n"
"    background-color: #2a4a6a;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QTabWidget#tab_wi"
                        "dget_c QTabBar::tab:first {\n"
"    margin-left: 0px;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_c QTabBar::tab:last {\n"
"    margin-right: 0px;\n"
"}\n"
"\n"
"QTabWidget#tab_widget_c QTabBar {\n"
"    qproperty-drawBase: 0;\n"
"}"));
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        conf_rech_c = new QPushButton(tab_5);
        conf_rech_c->setObjectName("conf_rech_c");
        conf_rech_c->setGeometry(QRect(510, 50, 131, 41));
        conf_rech_c->setStyleSheet(QString::fromUtf8("#conf_rech_c {\n"
"    background-color: #6F42C1;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_rech_c:hover {\n"
"    background-color: #5A2D9C;\n"
"}"));
        groupBoxc = new QGroupBox(tab_5);
        groupBoxc->setObjectName("groupBoxc");
        groupBoxc->setGeometry(QRect(10, 70, 300, 480));
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
"    background-color: #228B22;\n"
"    color: white;\n"
"    padding: 5px 10px;\n"
"    border-radius: 3px;\n"
"}"));
        label_14 = new QLabel(groupBoxc);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 40, 30, 30));
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
        label_15 = new QLabel(groupBoxc);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 80, 40, 30));
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
        label_16 = new QLabel(groupBoxc);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 120, 60, 30));
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
        label_17->setGeometry(QRect(10, 160, 110, 30));
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
        label_18->setGeometry(QRect(10, 200, 60, 30));
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
        label_19->setGeometry(QRect(10, 240, 100, 30));
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
        label_20 = new QLabel(groupBoxc);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(10, 285, 100, 30));
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
        label_21 = new QLabel(groupBoxc);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(10, 320, 110, 30));
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
        label_22 = new QLabel(groupBoxc);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(10, 360, 100, 30));
        label_22->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        enregistrer_c->setGeometry(QRect(10, 428, 140, 40));
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
        code_c = new QCheckBox(groupBoxc);
        code_c->setObjectName("code_c");
        code_c->setGeometry(QRect(120, 360, 81, 30));
        code_c->setStyleSheet(QString::fromUtf8("#code_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#code_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#code_c QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        conduite_c = new QCheckBox(groupBoxc);
        conduite_c->setObjectName("conduite_c");
        conduite_c->setGeometry(QRect(120, 393, 111, 30));
        conduite_c->setStyleSheet(QString::fromUtf8("#conduite_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#conduite_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#conduite_c QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        parc_c = new QCheckBox(groupBoxc);
        parc_c->setObjectName("parc_c");
        parc_c->setGeometry(QRect(210, 360, 71, 30));
        parc_c->setStyleSheet(QString::fromUtf8("#parc_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#parc_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
"\n"
"#parc_c QAbstractItemView {\n"
"    background-color: #FBFAF5;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}"));
        modifier_c = new QPushButton(groupBoxc);
        modifier_c->setObjectName("modifier_c");
        modifier_c->setGeometry(QRect(160, 430, 120, 40));
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
        filtrer_c = new QComboBox(tab_5);
        filtrer_c->addItem(QString());
        filtrer_c->addItem(QString());
        filtrer_c->addItem(QString());
        filtrer_c->addItem(QString());
        filtrer_c->setObjectName("filtrer_c");
        filtrer_c->setGeometry(QRect(650, 50, 144, 40));
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
        trier_c->addItem(QString());
        trier_c->addItem(QString());
        trier_c->setObjectName("trier_c");
        trier_c->setGeometry(QRect(800, 50, 211, 40));
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
        supp_c = new QPushButton(tab_5);
        supp_c->setObjectName("supp_c");
        supp_c->setGeometry(QRect(320, 490, 141, 41));
        supp_c->setStyleSheet(QString::fromUtf8("#supp_c {\n"
"    background-color: #DC3545;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#supp_c:hover {\n"
"    background-color: #C82333;\n"
"}"));
        taper_c = new QLineEdit(tab_5);
        taper_c->setObjectName("taper_c");
        taper_c->setGeometry(QRect(330, 50, 171, 40));
        taper_c->setStyleSheet(QString::fromUtf8("#taper_c {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#taper_c:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        table_candidat = new QTableWidget(tab_5);
        if (table_candidat->columnCount() < 9)
            table_candidat->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        table_candidat->setHorizontalHeaderItem(0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        table_candidat->setHorizontalHeaderItem(1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        table_candidat->setHorizontalHeaderItem(2, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        table_candidat->setHorizontalHeaderItem(3, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        table_candidat->setHorizontalHeaderItem(4, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        table_candidat->setHorizontalHeaderItem(5, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        table_candidat->setHorizontalHeaderItem(6, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        table_candidat->setHorizontalHeaderItem(7, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        table_candidat->setHorizontalHeaderItem(8, __qtablewidgetitem41);
        if (table_candidat->rowCount() < 9)
            table_candidat->setRowCount(9);
        table_candidat->setObjectName("table_candidat");
        table_candidat->setGeometry(QRect(320, 100, 731, 381));
        table_candidat->setStyleSheet(QString::fromUtf8("/* Main table styling */\n"
"#table_candidat {\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #0F2434;\n"
"    gridline-color: #0F2434;\n"
"    alternate-background-color: #E8E8E8;\n"
"}\n"
"\n"
"/* Table header styling - make columns visible */\n"
"#table_candidat QHeaderView::section {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px;\n"
"    border: 1px solid #1D9E3A;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"/* Table items/cells styling */\n"
"#table_candidat::item {\n"
"    border: 1px solid #0F2434;\n"
"    padding: 8px;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"/* Make sure text is visible in cells */\n"
"#table_candidat::item {\n"
"    color: #0F2434;\n"
"    background-color: #FBFAF5;\n"
"}\n"
"\n"
"/* Alternate row coloring */\n"
"#table_candidat::item:alternate {\n"
"    background-color: #F0F0F0;\n"
"}\n"
"\n"
"/* Hover effect on rows */\n"
"#table_candidat::item:hover {\n"
"    background-color: #E0E0E0;"
                        "\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"/* Selected row styling */\n"
"#table_candidat::item:selected {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"}\n"
"\n"
"/* Ensure the table view itself has proper borders */\n"
"#table_candidat QTableView {\n"
"    gridline-color: #0F2434;\n"
"    border: 2px solid #0F2434;\n"
"}\n"
"\n"
"/* Corner button styling */\n"
"#table_candidat QTableCornerButton::section {\n"
"    background-color: #0F2434;\n"
"    border: 1px solid #0F2434;\n"
"}"));
        expo_tab_c = new QPushButton(tab_5);
        expo_tab_c->setObjectName("expo_tab_c");
        expo_tab_c->setGeometry(QRect(470, 490, 141, 41));
        expo_tab_c->setStyleSheet(QString::fromUtf8("#expo_tab_c {\n"
"    background-color: #007BFF;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#expo_tab_c:hover {\n"
"    background-color: #0056B3;\n"
"}\n"
""));
        expo_tab_c->setIcon(icon6);
        label_56 = new QLabel(tab_5);
        label_56->setObjectName("label_56");
        label_56->setGeometry(QRect(10, 20, 41, 41));
        label_56->setFont(font);
        label_56->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/candidat_icon/img/icons_prj_cpp/Screenshot_2025-11-15_103429-removebg-preview.png);"));
        label_66 = new QLabel(tab_5);
        label_66->setObjectName("label_66");
        label_66->setGeometry(QRect(40, 20, 201, 41));
        label_66->setFont(font1);
        label_66->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(0, 0, 0);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size:  20px;\n"
"    font-weight: bold;\n"
"    padding: 4px 6px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    margin: 2px;\n"
"}"));
        tab_widget_c->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tab_widget2_c = new QTabWidget(tab_6);
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
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        selon_stat_c = new QComboBox(tab_7);
        selon_stat_c->addItem(QString());
        selon_stat_c->addItem(QString());
        selon_stat_c->addItem(QString());
        selon_stat_c->setObjectName("selon_stat_c");
        selon_stat_c->setGeometry(QRect(850, 20, 100, 40));
        selon_stat_c->setStyleSheet(QString::fromUtf8(""));
        label_49 = new QLabel(tab_7);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(50, 10, 580, 390));
        label_49->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix2/img/Un diagramme en barr.png);"));
        tab_widget2_c->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        label_11 = new QLabel(tab_8);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 30, 130, 30));
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
        prog_idcandidat = new QLineEdit(tab_8);
        prog_idcandidat->setObjectName("prog_idcandidat");
        prog_idcandidat->setGeometry(QRect(160, 30, 113, 28));
        prog_idcandidat->setStyleSheet(QString::fromUtf8(""));
        label_13 = new QLabel(tab_8);
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
        label_48 = new QLabel(tab_8);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(190, 100, 620, 280));
        label_48->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/Barre de progression.png);"));
        tab_widget2_c->addTab(tab_8, QString());
        tab_widget_c->addTab(tab_6, QString());
        stackedWidget->addWidget(page_c);
        page_m = new QWidget();
        page_m->setObjectName("page_m");
        frame_m = new QFrame(page_m);
        frame_m->setObjectName("frame_m");
        frame_m->setGeometry(QRect(20, 20, 1271, 641));
        frame_m->setStyleSheet(QString::fromUtf8("#frame_m {\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
""));
        frame_m->setFrameShape(QFrame::Shape::StyledPanel);
        frame_m->setFrameShadow(QFrame::Shadow::Raised);
        widget_m = new QTabWidget(frame_m);
        widget_m->setObjectName("widget_m");
        widget_m->setGeometry(QRect(0, 10, 1251, 621));
        widget_m->setStyleSheet(QString::fromUtf8("QTabWidget#widget_m {\n"
"    background-color: #FBFAF5;\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QTabWidget#widget_m::pane {\n"
"    border: 1px solid #C0C0C0;\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 8px;\n"
"    margin-top: -1px;\n"
"    padding: 15px;\n"
"}\n"
"\n"
"QTabWidget#widget_m QTabBar::tab {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 12px 24px;\n"
"    margin-right: 2px;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    border: 1px solid #0F2434;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget#widget_m QTabBar::tab:selected {\n"
"    background-color: #1D9E3A;\n"
"    color: #FFFFFF;\n"
"    border: 1px solid #1D9E3A;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget#widget_m QTabBar::tab:hover:!selected {\n"
"    background-color: #2a4a6a;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QTabWidget#widget_m QTabBar::tab:firs"
                        "t {\n"
"    margin-left: 0px;\n"
"}\n"
"\n"
"QTabWidget#widget_m QTabBar::tab:last {\n"
"    margin-right: 0px;\n"
"}\n"
"\n"
"QTabWidget#widget_m QTabBar {\n"
"    qproperty-drawBase: 0;\n"
"}"));
        tab_16 = new QWidget();
        tab_16->setObjectName("tab_16");
        groupBoxm = new QGroupBox(tab_16);
        groupBoxm->setObjectName("groupBoxm");
        groupBoxm->setGeometry(QRect(10, 90, 301, 421));
        groupBoxm->setStyleSheet(QString::fromUtf8("#groupBoxm{\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    background-color: #FBFAF5;\n"
"    box-shadow: 2px 2px 6px rgba(0,0,0,0.25);\n"
"}\n"
"#groupBoxm::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    background-color: #228B22;\n"
"    color: white;\n"
"    padding: 5px 10px;\n"
"    border-radius: 3px;\n"
"}\n"
"QLabel {\n"
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
        label_12 = new QLabel(groupBoxm);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 40, 71, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_39 = new QLabel(groupBoxm);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(20, 210, 81, 31));
        label_39->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_40 = new QLabel(groupBoxm);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(20, 80, 61, 31));
        label_40->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_41 = new QLabel(groupBoxm);
        label_41->setObjectName("label_41");
        label_41->setGeometry(QRect(20, 120, 61, 31));
        label_41->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_42 = new QLabel(groupBoxm);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(20, 160, 81, 31));
        label_42->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_43 = new QLabel(groupBoxm);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(20, 260, 91, 31));
        label_43->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_44 = new QLabel(groupBoxm);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(20, 310, 91, 31));
        label_44->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        nom_m = new QLineEdit(groupBoxm);
        nom_m->setObjectName("nom_m");
        nom_m->setGeometry(QRect(130, 40, 113, 31));
        nom_m->setStyleSheet(QString::fromUtf8("#nom_m {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
""));
        specialite = new QComboBox(groupBoxm);
        specialite->addItem(QString());
        specialite->addItem(QString());
        specialite->addItem(QString());
        specialite->addItem(QString());
        specialite->addItem(QString());
        specialite->setObjectName("specialite");
        specialite->setGeometry(QRect(130, 210, 111, 26));
        specialite->setStyleSheet(QString::fromUtf8("#specialite {\n"
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
        prenom_m = new QLineEdit(groupBoxm);
        prenom_m->setObjectName("prenom_m");
        prenom_m->setGeometry(QRect(130, 80, 113, 31));
        prenom_m->setStyleSheet(QString::fromUtf8("#prenom_m{\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
""));
        email_monituer = new QLineEdit(groupBoxm);
        email_monituer->setObjectName("email_monituer");
        email_monituer->setGeometry(QRect(130, 120, 113, 31));
        email_monituer->setStyleSheet(QString::fromUtf8("#email_monituer{\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
""));
        telephone_m = new QLineEdit(groupBoxm);
        telephone_m->setObjectName("telephone_m");
        telephone_m->setGeometry(QRect(130, 160, 113, 31));
        telephone_m->setStyleSheet(QString::fromUtf8("#telephone_m{\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
""));
        actif = new QRadioButton(groupBoxm);
        actif->setObjectName("actif");
        actif->setGeometry(QRect(120, 260, 61, 24));
        actif->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);"));
        inactif = new QRadioButton(groupBoxm);
        inactif->setObjectName("inactif");
        inactif->setGeometry(QRect(190, 260, 81, 24));
        inactif->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        experience_m = new QLineEdit(groupBoxm);
        experience_m->setObjectName("experience_m");
        experience_m->setGeometry(QRect(130, 310, 113, 31));
        experience_m->setStyleSheet(QString::fromUtf8("#experience_m {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}"));
        reinstaller_mon = new QPushButton(groupBoxm);
        reinstaller_mon->setObjectName("reinstaller_mon");
        reinstaller_mon->setGeometry(QRect(150, 370, 131, 29));
        reinstaller_mon->setStyleSheet(QString::fromUtf8("#reinstaller_mon {\n"
"    background-color: #228B22;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#reinstaller_mon:hover {\n"
"    background-color: #28a428;\n"
"}\n"
"\n"
"#reinstaller_mon:pressed {\n"
"    background-color: #1c771c;\n"
"}"));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        reinstaller_mon->setIcon(icon7);
        enregistrer_m = new QPushButton(groupBoxm);
        enregistrer_m->setObjectName("enregistrer_m");
        enregistrer_m->setGeometry(QRect(10, 370, 131, 31));
        enregistrer_m->setStyleSheet(QString::fromUtf8("#enregistrer_m {\n"
"    background-color: #228B22;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#enregistrer_m:hover {\n"
"    background-color: #28a428;\n"
"}\n"
"\n"
"#enregistrer_m:pressed {\n"
"    background-color: #1c771c;\n"
"}"));
        filtrer_mon = new QComboBox(tab_16);
        filtrer_mon->addItem(QString());
        filtrer_mon->addItem(QString());
        filtrer_mon->addItem(QString());
        filtrer_mon->setObjectName("filtrer_mon");
        filtrer_mon->setGeometry(QRect(320, 50, 76, 26));
        filtrer_mon->setStyleSheet(QString::fromUtf8("#filtrer_mon {\n"
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
        trier_mon = new QComboBox(tab_16);
        trier_mon->addItem(QString());
        trier_mon->addItem(QString());
        trier_mon->addItem(QString());
        trier_mon->setObjectName("trier_mon");
        trier_mon->setGeometry(QRect(410, 50, 76, 26));
        trier_mon->setStyleSheet(QString::fromUtf8("#trier_mon {\n"
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
        taper_mon = new QLineEdit(tab_16);
        taper_mon->setObjectName("taper_mon");
        taper_mon->setGeometry(QRect(830, 50, 141, 31));
        taper_mon->setStyleSheet(QString::fromUtf8("#taper_mon {\n"
"    border: 2px solid #0F2434;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"    selection-background-color: #1D9E3A;\n"
"    selection-color: #FBFAF5;\n"
"}\n"
"\n"
"#taper_mon:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"}\n"
""));
        label_45 = new QLabel(tab_16);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(60, 30, 201, 31));
        label_45->setFont(font1);
        label_45->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(0, 0, 0);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size:  20px;\n"
"    font-weight: bold;\n"
"    padding: 4px 6px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    margin: 2px;\n"
"}"));
        supp_m = new QPushButton(tab_16);
        supp_m->setObjectName("supp_m");
        supp_m->setGeometry(QRect(450, 480, 141, 31));
        supp_m->setStyleSheet(QString::fromUtf8("#supp_m {\n"
"    background-color: #DC3545;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#supp_m:hover {\n"
"    background-color: #C82333;\n"
"}"));
        expo_tab_m = new QPushButton(tab_16);
        expo_tab_m->setObjectName("expo_tab_m");
        expo_tab_m->setGeometry(QRect(950, 480, 161, 31));
        expo_tab_m->setStyleSheet(QString::fromUtf8("#expo_tab_m {\n"
"    background-color: #007BFF;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#expo_tab_m:hover {\n"
"    background-color: #0056B3;\n"
"}"));
        expo_tab_m->setIcon(icon6);
        modifier_m = new QPushButton(tab_16);
        modifier_m->setObjectName("modifier_m");
        modifier_m->setGeometry(QRect(320, 480, 121, 31));
        modifier_m->setStyleSheet(QString::fromUtf8("#modifier_m {\n"
"    background-color: #228B22;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#modifier_m:hover {\n"
"    background-color: #28a428;\n"
"}\n"
"\n"
"#modifier_m:pressed {\n"
"    background-color: #1c771c;\n"
"}"));
        conf_rech_m = new QPushButton(tab_16);
        conf_rech_m->setObjectName("conf_rech_m");
        conf_rech_m->setGeometry(QRect(980, 50, 131, 31));
        conf_rech_m->setStyleSheet(QString::fromUtf8("#conf_rech_m {\n"
"    background-color: #6F42C1;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#conf_rech_m:hover {\n"
"    background-color: #5A2D9C;\n"
"}"));
        tab_mon = new QTableWidget(tab_16);
        if (tab_mon->columnCount() < 6)
            tab_mon->setColumnCount(6);
        QFont font2;
        font2.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setFont(font2);
        tab_mon->setHorizontalHeaderItem(0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tab_mon->setHorizontalHeaderItem(1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tab_mon->setHorizontalHeaderItem(2, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tab_mon->setHorizontalHeaderItem(3, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tab_mon->setHorizontalHeaderItem(4, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tab_mon->setHorizontalHeaderItem(5, __qtablewidgetitem47);
        if (tab_mon->rowCount() < 9)
            tab_mon->setRowCount(9);
        QFont font3;
        font3.setPointSize(13);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setFont(font3);
        tab_mon->setItem(1, 0, __qtablewidgetitem48);
        tab_mon->setObjectName("tab_mon");
        tab_mon->setGeometry(QRect(320, 90, 801, 381));
        tab_mon->setStyleSheet(QString::fromUtf8("\n"
"#tab_mon {\n"
"    background-color: #FBFAF5;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #0F2434;\n"
"    gridline-color: #0F2434;\n"
"    alternate-background-color: #E8E8E8;\n"
"}\n"
"\n"
"#tab_mon QHeaderView::section {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"    padding: 8px;\n"
"    border: 1px solid #1D9E3A;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"#tab_mon::item {\n"
"    border: 1px solid #0F2434;\n"
"    padding: 8px;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#tab_mon::item {\n"
"    color: #0F2434;\n"
"    background-color: #FBFAF5;\n"
"}\n"
"\n"
"/* Alternate row coloring */\n"
"#tab_mon::item:alternate {\n"
"    background-color: #F0F0F0;\n"
"}\n"
"\n"
"/* Hover effect on rows */\n"
"#tab_mon::item:hover {\n"
"    background-color: #E0E0E0;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"/* Selected row styling */\n"
"#tab_mon::item:selected {\n"
"    background-color: #0F2434;\n"
"    color: #FBFAF5;\n"
"}\n"
"\n"
"/* Ensure the table view itsel"
                        "f has proper borders */\n"
"#tab_mon QTableView {\n"
"    gridline-color: #0F2434;\n"
"    border: 2px solid #0F2434;\n"
"}\n"
"\n"
"/* Corner button styling */\n"
"#tab_mon QTableCornerButton::section {\n"
"    background-color: #0F2434;\n"
"    border: 1px solid #0F2434;\n"
"}"));
        label_61 = new QLabel(tab_16);
        label_61->setObjectName("label_61");
        label_61->setGeometry(QRect(20, 20, 41, 51));
        label_61->setFont(font);
        label_61->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"image: url(:/new/prefix1/img/icons_prj_cpp/Screenshot_2025-11-15_103718-removebg-preview.png);"));
        widget_m->addTab(tab_16, QString());
        tab_17 = new QWidget();
        tab_17->setObjectName("tab_17");
        tab_widget2 = new QTabWidget(tab_17);
        tab_widget2->setObjectName("tab_widget2");
        tab_widget2->setGeometry(QRect(10, 20, 991, 471));
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
        tab_18 = new QWidget();
        tab_18->setObjectName("tab_18");
        label_46 = new QLabel(tab_18);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(220, 40, 471, 71));
        label_46->setStyleSheet(QString::fromUtf8("font: 22pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        tab_widget2->addTab(tab_18, QString());
        tab_19 = new QWidget();
        tab_19->setObjectName("tab_19");
        label_47 = new QLabel(tab_19);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(90, 30, 801, 41));
        label_47->setStyleSheet(QString::fromUtf8("font: 28pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        expo_ai_m = new QPushButton(tab_19);
        expo_ai_m->setObjectName("expo_ai_m");
        expo_ai_m->setGeometry(QRect(40, 370, 161, 31));
        expo_ai_m->setStyleSheet(QString::fromUtf8("#expo_ai_m {\n"
"    background-color: #228B22;\n"
"    color: #FBFAF5;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#expo_ai_m:hover {\n"
"    background-color: #28a428;\n"
"}\n"
"\n"
"#expo_ai_m:pressed {\n"
"    background-color: #1c771c;\n"
"}"));
        expo_ai_m->setIcon(icon6);
        tab_widget2->addTab(tab_19, QString());
        widget_m->addTab(tab_17, QString());
        stackedWidget->addWidget(page_m);
        barre_nav = new QGroupBox(centralwidget);
        barre_nav->setObjectName("barre_nav");
        barre_nav->setGeometry(QRect(10, 90, 200, 641));
        barre_nav->setStyleSheet(QString::fromUtf8("#barre_nav {\n"
"    background-color: #0F2434;\n"
"    border-radius: 12px;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"    border: 1px solid #2a4a6a;\n"
"}\n"
"\n"
"#candidat_btn,\n"
"#vehicule_btn,\n"
"#moniteur_btn,\n"
"#seance_btn,\n"
"#emp_btn {\n"
"    background-color: #228B22;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"    font-size: 11px;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 0.3px;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"#candidat_btn:hover,\n"
"#vehicule_btn:hover,\n"
"#moniteur_btn:hover,\n"
"#seance_btn:hover,\n"
"#emp_btn:hover {\n"
"    background-color: #28a428;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#candidat_btn:pressed,\n"
"#vehicule_btn:pressed,\n"
"#moniteur_btn:pressed,\n"
"#seance_btn:pressed,\n"
"#emp_btn:pressed {\n"
"    background-color: #1c771c;\n"
"    transform: scale(0.98);\n"
"}\n"
"\n"
"#fermer_btn {\n"
""
                        "    background-color: #E74C3C;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"    font-size: 11px;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 0.3px;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"#fermer_btn:hover {\n"
"    background-color: #EC7063;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#fermer_btn:pressed {\n"
"    background-color: #CB4335;\n"
"    transform: scale(0.98);\n"
"}"));
        fermer_btn = new QPushButton(barre_nav);
        fermer_btn->setObjectName("fermer_btn");
        fermer_btn->setGeometry(QRect(20, 580, 150, 40));
        fermer_btn->setStyleSheet(QString::fromUtf8(""));
        seance_btn = new QPushButton(barre_nav);
        seance_btn->setObjectName("seance_btn");
        seance_btn->setGeometry(QRect(10, 450, 170, 40));
        seance_btn->setStyleSheet(QString::fromUtf8(""));
        seance_btn->setIcon(icon4);
        seance_btn->setIconSize(QSize(35, 30));
        vehicule_btn = new QPushButton(barre_nav);
        vehicule_btn->setObjectName("vehicule_btn");
        vehicule_btn->setGeometry(QRect(10, 500, 170, 40));
        vehicule_btn->setStyleSheet(QString::fromUtf8(""));
        vehicule_btn->setIcon(icon5);
        vehicule_btn->setIconSize(QSize(35, 35));
        emp_btn = new QPushButton(barre_nav);
        emp_btn->setObjectName("emp_btn");
        emp_btn->setGeometry(QRect(10, 400, 170, 40));
        emp_btn->setStyleSheet(QString::fromUtf8(""));
        emp_btn->setIcon(icon3);
        emp_btn->setIconSize(QSize(30, 30));
        moniteur_btn = new QPushButton(barre_nav);
        moniteur_btn->setObjectName("moniteur_btn");
        moniteur_btn->setGeometry(QRect(10, 350, 170, 40));
        moniteur_btn->setStyleSheet(QString::fromUtf8(""));
        moniteur_btn->setIcon(icon2);
        moniteur_btn->setIconSize(QSize(30, 30));
        label_30 = new QLabel(barre_nav);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(10, 10, 181, 191));
        label_30->setStyleSheet(QString::fromUtf8("image: url(:/ res/img/logo.png);"));
        candidat_btn = new QPushButton(barre_nav);
        candidat_btn->setObjectName("candidat_btn");
        candidat_btn->setGeometry(QRect(10, 300, 170, 40));
        candidat_btn->setStyleSheet(QString::fromUtf8(""));
        candidat_btn->setIcon(icon1);
        candidat_btn->setIconSize(QSize(25, 25));
        accueil = new QPushButton(barre_nav);
        accueil->setObjectName("accueil");
        accueil->setGeometry(QRect(10, 230, 170, 40));
        QFont font4;
        font4.setBold(true);
        accueil->setFont(font4);
        accueil->setStyleSheet(QString::fromUtf8("#accueil {\n"
"    background-color: #178FEB;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"    font-size: 11px;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 0.3px;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"#accueil:hover {\n"
"    background-color: #2B9EFF;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#accueil:pressed {\n"
"    background-color: #1279CC;\n"
"    transform: scale(0.98);\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/img/icons_prj_cpp/image-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        accueil->setIcon(icon8);
        accueil->setIconSize(QSize(25, 25));
        barre = new QGroupBox(centralwidget);
        barre->setObjectName("barre");
        barre->setGeometry(QRect(10, 10, 1491, 71));
        barre->setStyleSheet(QString::fromUtf8("#barre {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                stop:0 #1a3a52, stop:1 #0F2434);\n"
"    color: rgb(255, 255, 255);\n"
"    border: 1px solid #2a4a6a;\n"
"    border-radius: 12px;\n"
"    padding: 14px 20px;\n"
"    margin: 5px;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    text-align: center;\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        titre = new QLabel(barre);
        titre->setObjectName("titre");
        titre->setGeometry(QRect(20, 10, 231, 51));
        QFont font5;
        font5.setPointSize(26);
        titre->setFont(font5);
        titre->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        widget_v->setCurrentIndex(0);
        tab_fonc_v->setCurrentIndex(0);
        tab_widget_E->setCurrentIndex(0);
        conf_E->setDefault(false);
        tab_widget2_E->setCurrentIndex(0);
        tabWidget_s->setCurrentIndex(0);
        tab_widget_c->setCurrentIndex(0);
        tab_widget2_c->setCurrentIndex(0);
        widget_m->setCurrentIndex(0);
        tab_widget2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBoxv->setTitle(QCoreApplication::translate("MainWindow", "Ajouter un v\303\251hicule", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Matricule", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Marque", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Mod\303\250le", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ann\303\251e d'achat", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Kilom\303\251trage", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Date de r\303\251vision", nullptr));
        type_v->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir", nullptr));
        type_v->setItemText(1, QCoreApplication::translate("MainWindow", "Voiture", nullptr));
        type_v->setItemText(2, QCoreApplication::translate("MainWindow", "Moto", nullptr));
        type_v->setItemText(3, QCoreApplication::translate("MainWindow", "AutoBus", nullptr));
        type_v->setItemText(4, QCoreApplication::translate("MainWindow", "Camion poids lourd", nullptr));

        bon->setText(QCoreApplication::translate("MainWindow", "Bon", nullptr));
        panne->setText(QCoreApplication::translate("MainWindow", "En panne", nullptr));
        entretien->setText(QCoreApplication::translate("MainWindow", "Entretien", nullptr));
        conf_v->setText(QCoreApplication::translate("MainWindow", "Confirmer \342\234\224\357\270\217", nullptr));
        reins_v->setText(QCoreApplication::translate("MainWindow", "R\303\251installer \360\237\224\204", nullptr));
        modif_v->setText(QCoreApplication::translate("MainWindow", "Modifier \342\234\217\357\270\217", nullptr));
        expo_v->setText(QCoreApplication::translate("MainWindow", "Exporter", nullptr));
        filtrer_v->setItemText(0, QCoreApplication::translate("MainWindow", "Tous", nullptr));
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
        label_57->setText(QString());
        label_63->setText(QCoreApplication::translate("MainWindow", " Gestion V\303\251hicules", nullptr));
        widget_v->setTabText(widget_v->indexOf(tab), QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        tab_fonc_v->setTabText(tab_fonc_v->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Matricule", nullptr));
        conf_ai_v->setText(QCoreApplication::translate("MainWindow", "Confirmer \342\234\224\357\270\217", nullptr));
        reins_ai_v->setText(QCoreApplication::translate("MainWindow", "R\303\251installer \360\237\224\204", nullptr));
        tab_fonc_v->setTabText(tab_fonc_v->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Maintenance pr\303\251dictive", nullptr));
        widget_v->setTabText(widget_v->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Fonctionnalit\303\251", nullptr));
        frame_a->setTitle(QString());
        bien->setText(QCoreApplication::translate("MainWindow", "\360\237\221\213\342\200\213 Bienvenue \303\240 Smart Drive School.\n"
"Votre voyage vers une conduite s\303\273re et confiante commence ici.\n"
"G\303\251rez les op\303\251rations de votre auto-\303\251cole efficacement avec notre syst\303\250me de gestion complet.", nullptr));
        label_37->setText(QString());
        quantum->setText(QCoreApplication::translate("MainWindow", "D\303\251velopp\303\251 par Quantum Team", nullptr));
        label_67->setText(QCoreApplication::translate("MainWindow", " Accueil", nullptr));
        label_68->setText(QString());
        candidat->setText(QString());
        moniteur->setText(QString());
        emp->setText(QString());
        seance->setText(QString());
        vehicule->setText(QString());
        label->setText(QString());
        label_69->setText(QCoreApplication::translate("MainWindow", "Candidats", nullptr));
        label_70->setText(QCoreApplication::translate("MainWindow", "Moniteurs", nullptr));
        label_71->setText(QCoreApplication::translate("MainWindow", "Employ\303\251s", nullptr));
        label_72->setText(QCoreApplication::translate("MainWindow", "S\303\251ances", nullptr));
        label_73->setText(QCoreApplication::translate("MainWindow", "V\303\251hicules", nullptr));
        frame_emp->setTitle(QString());
        trier_E->setItemText(0, QCoreApplication::translate("MainWindow", "Trier", nullptr));
        trier_E->setItemText(1, QCoreApplication::translate("MainWindow", "A", nullptr));
        trier_E->setItemText(2, QCoreApplication::translate("MainWindow", "B", nullptr));
        trier_E->setItemText(3, QCoreApplication::translate("MainWindow", "C", nullptr));
        trier_E->setItemText(4, QCoreApplication::translate("MainWindow", "D", nullptr));
        trier_E->setItemText(5, QCoreApplication::translate("MainWindow", "E", nullptr));
        trier_E->setItemText(6, QCoreApplication::translate("MainWindow", "F", nullptr));
        trier_E->setItemText(7, QCoreApplication::translate("MainWindow", "G", nullptr));
        trier_E->setItemText(8, QCoreApplication::translate("MainWindow", "H", nullptr));
        trier_E->setItemText(9, QCoreApplication::translate("MainWindow", "I", nullptr));
        trier_E->setItemText(10, QCoreApplication::translate("MainWindow", "J", nullptr));
        trier_E->setItemText(11, QCoreApplication::translate("MainWindow", "K", nullptr));
        trier_E->setItemText(12, QCoreApplication::translate("MainWindow", "L", nullptr));
        trier_E->setItemText(13, QCoreApplication::translate("MainWindow", "M", nullptr));
        trier_E->setItemText(14, QCoreApplication::translate("MainWindow", "N", nullptr));
        trier_E->setItemText(15, QCoreApplication::translate("MainWindow", "O", nullptr));
        trier_E->setItemText(16, QCoreApplication::translate("MainWindow", "P", nullptr));
        trier_E->setItemText(17, QCoreApplication::translate("MainWindow", "Q", nullptr));
        trier_E->setItemText(18, QCoreApplication::translate("MainWindow", "R", nullptr));
        trier_E->setItemText(19, QCoreApplication::translate("MainWindow", "S", nullptr));
        trier_E->setItemText(20, QCoreApplication::translate("MainWindow", "T", nullptr));
        trier_E->setItemText(21, QCoreApplication::translate("MainWindow", "U", nullptr));
        trier_E->setItemText(22, QCoreApplication::translate("MainWindow", "V", nullptr));
        trier_E->setItemText(23, QCoreApplication::translate("MainWindow", "W", nullptr));
        trier_E->setItemText(24, QCoreApplication::translate("MainWindow", "X", nullptr));
        trier_E->setItemText(25, QCoreApplication::translate("MainWindow", "Y", nullptr));
        trier_E->setItemText(26, QCoreApplication::translate("MainWindow", "Z", nullptr));

        taper_E->setPlaceholderText(QCoreApplication::translate("MainWindow", "Taper...", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "Rechercher par Identifiant/Nom", nullptr));
        supp_E->setText(QCoreApplication::translate("MainWindow", "Supprimer \360\237\227\221\357\270\217", nullptr));
        expo_tab_E->setText(QCoreApplication::translate("MainWindow", " Exporter", nullptr));
        conf_rech_E->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Confirmer", nullptr));
        modif_E->setText(QCoreApplication::translate("MainWindow", "Modifier \342\234\217\357\270\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tab_employes->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tab_employes->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tab_employes->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tab_employes->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tab_employes->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tab_employes->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tab_employes->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Date d'embauche", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tab_employes->horizontalHeaderItem(7);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tab_employes->horizontalHeaderItem(8);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Mot de pass", nullptr));
        label_55->setText(QString());
        label_64->setText(QCoreApplication::translate("MainWindow", " Gestion Employ\303\251s", nullptr));
        groupBoxE->setTitle(QCoreApplication::translate("MainWindow", "Ajouter un employ\303\251e", nullptr));
        poste_combo->setItemText(0, QCoreApplication::translate("MainWindow", "Responsable de moniteur", nullptr));
        poste_combo->setItemText(1, QCoreApplication::translate("MainWindow", "Responsable de candidat", nullptr));
        poste_combo->setItemText(2, QCoreApplication::translate("MainWindow", "Responsable de seance", nullptr));
        poste_combo->setItemText(3, QCoreApplication::translate("MainWindow", "Responsable de vehicule", nullptr));
        poste_combo->setItemText(4, QCoreApplication::translate("MainWindow", "Responsable de employe", nullptr));

        poste_combo->setCurrentText(QCoreApplication::translate("MainWindow", "Responsable de moniteur", nullptr));
        conf_E->setText(QCoreApplication::translate("MainWindow", "Confirmer \342\234\224\357\270\217", nullptr));
        reins_E->setText(QCoreApplication::translate("MainWindow", "R\303\251installer \360\237\224\204", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        label_58->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "Date d'embauche", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_62->setText(QCoreApplication::translate("MainWindow", "Mot de pass", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        tab_widget_E->setTabText(tab_widget_E->indexOf(tab_13), QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        selon_stat_E->setItemText(0, QCoreApplication::translate("MainWindow", "Selon", nullptr));
        selon_stat_E->setItemText(1, QCoreApplication::translate("MainWindow", "Age", nullptr));
        selon_stat_E->setItemText(2, QCoreApplication::translate("MainWindow", "Nivaeu permis", nullptr));

        tab_widget2_E->setTabText(tab_widget2_E->indexOf(tab_15), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        tab_widget_E->setTabText(tab_widget_E->indexOf(tab_14), QCoreApplication::translate("MainWindow", "Fonctionnalit\303\251", nullptr));
        frame_sea->setTitle(QString());
#if QT_CONFIG(whatsthis)
        tabWidget_s->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>autre</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        QTableWidgetItem *___qtablewidgetitem17 = tab_s->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "ID_S\303\251ance", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tab_s->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tab_s->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tab_s->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Heure d\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tab_s->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Heure fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tab_s->horizontalHeaderItem(5);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Salle", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tab_s->horizontalHeaderItem(6);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Long. d\303\251part", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tab_s->horizontalHeaderItem(7);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "Lat. d\303\251part", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tab_s->horizontalHeaderItem(8);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Long. arriv\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tab_s->horizontalHeaderItem(9);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Lat. arriv\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tab_s->horizontalHeaderItem(10);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tab_s->horizontalHeaderItem(11);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        confirm_s->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Confirmer", nullptr));
        exp_s->setText(QCoreApplication::translate("MainWindow", " Exporter", nullptr));
        filtre_s->setText(QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        tri_s->setItemText(0, QCoreApplication::translate("MainWindow", "Trier par", nullptr));
        tri_s->setItemText(1, QCoreApplication::translate("MainWindow", "Date", nullptr));
        tri_s->setItemText(2, QCoreApplication::translate("MainWindow", "Type", nullptr));

        recherche_s->setPlaceholderText(QCoreApplication::translate("MainWindow", "     ID_S\303\251ance", nullptr));
        groupBoxs->setTitle(QCoreApplication::translate("MainWindow", "Ajouter  s\303\251ance", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        type_s->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir", nullptr));
        type_s->setItemText(1, QCoreApplication::translate("MainWindow", "Conduite", nullptr));
        type_s->setItemText(2, QCoreApplication::translate("MainWindow", "Code", nullptr));

        label_25->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "D\303\251but_H", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Fin_H", nullptr));
        confirm_ajout_s->setText(QCoreApplication::translate("MainWindow", "Confirmer \342\234\224\357\270\217", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "Salle", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "Long. d\303\251part", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "Lat. d\303\251part", nullptr));
        label_53->setText(QCoreApplication::translate("MainWindow", "Long. arriv\303\251e", nullptr));
        label_54->setText(QCoreApplication::translate("MainWindow", "Lat. arriv\303\251e", nullptr));
        supp_s->setText(QCoreApplication::translate("MainWindow", "Supprimer \360\237\227\221\357\270\217", nullptr));
        label_36->setText(QString());
        label_65->setText(QCoreApplication::translate("MainWindow", " Gestion S\303\251ances", nullptr));
        tabWidget_s->setTabText(tabWidget_s->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        groupBox_stats->setTitle(QCoreApplication::translate("MainWindow", "Statistiques des S\303\251ances", nullptr));
        label_totalSessions->setText(QCoreApplication::translate("MainWindow", "Total des s\303\251ances: 0", nullptr));
        label_totalHours->setText(QCoreApplication::translate("MainWindow", "Heures totales: 0h", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = stats_s->horizontalHeaderItem(0);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "\303\211l\303\250ve/Moniteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = stats_s->horizontalHeaderItem(1);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "Nb s\303\251ances", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = stats_s->horizontalHeaderItem(2);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Heures totales", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = stats_s->horizontalHeaderItem(3);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "Type dominant", nullptr));
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
        conf_rech_c->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Confirmer", nullptr));
        groupBoxc->setTitle(QCoreApplication::translate("MainWindow", "Ajouter un candidat", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Cin : :", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom :", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Date naissance :", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Adresse :", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone :", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Email :", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Niveau permis :", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Progression :", nullptr));
        enregistrer_c->setText(QCoreApplication::translate("MainWindow", "Enregistrer \360\237\222\276", nullptr));
        nvpermis_c->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir", nullptr));
        nvpermis_c->setItemText(1, QCoreApplication::translate("MainWindow", "A", nullptr));
        nvpermis_c->setItemText(2, QCoreApplication::translate("MainWindow", "B", nullptr));
        nvpermis_c->setItemText(3, QCoreApplication::translate("MainWindow", "C", nullptr));
        nvpermis_c->setItemText(4, QCoreApplication::translate("MainWindow", "D", nullptr));

        code_c->setText(QCoreApplication::translate("MainWindow", "Code", nullptr));
        conduite_c->setText(QCoreApplication::translate("MainWindow", "Conduite", nullptr));
        parc_c->setText(QCoreApplication::translate("MainWindow", "Parc", nullptr));
        modifier_c->setText(QCoreApplication::translate("MainWindow", "Modifier \342\234\217\357\270\217", nullptr));
        filtrer_c->setItemText(0, QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        filtrer_c->setItemText(1, QCoreApplication::translate("MainWindow", "Code", nullptr));
        filtrer_c->setItemText(2, QCoreApplication::translate("MainWindow", "Conduite", nullptr));
        filtrer_c->setItemText(3, QCoreApplication::translate("MainWindow", "Parc", nullptr));

        trier_c->setItemText(0, QCoreApplication::translate("MainWindow", "Trier", nullptr));
        trier_c->setItemText(1, QCoreApplication::translate("MainWindow", "Nom croissant", nullptr));
        trier_c->setItemText(2, QCoreApplication::translate("MainWindow", "Nom d\303\251croissant", nullptr));
        trier_c->setItemText(3, QCoreApplication::translate("MainWindow", "Date naissance croissante", nullptr));
        trier_c->setItemText(4, QCoreApplication::translate("MainWindow", "Date naissance d\303\251croissante", nullptr));

        supp_c->setText(QCoreApplication::translate("MainWindow", "Supprimer \360\237\227\221\357\270\217", nullptr));
        taper_c->setInputMask(QString());
        taper_c->setPlaceholderText(QCoreApplication::translate("MainWindow", "  Rechercher", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = table_candidat->horizontalHeaderItem(0);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = table_candidat->horizontalHeaderItem(1);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = table_candidat->horizontalHeaderItem(2);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = table_candidat->horizontalHeaderItem(3);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "Date naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = table_candidat->horizontalHeaderItem(4);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = table_candidat->horizontalHeaderItem(5);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = table_candidat->horizontalHeaderItem(6);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = table_candidat->horizontalHeaderItem(7);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "Niveau permis", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = table_candidat->horizontalHeaderItem(8);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "Progression", nullptr));
        expo_tab_c->setText(QCoreApplication::translate("MainWindow", " Exporter", nullptr));
        label_56->setText(QString());
        label_66->setText(QCoreApplication::translate("MainWindow", "Gestion Candidats", nullptr));
        tab_widget_c->setTabText(tab_widget_c->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        selon_stat_c->setItemText(0, QCoreApplication::translate("MainWindow", "Selon", nullptr));
        selon_stat_c->setItemText(1, QCoreApplication::translate("MainWindow", "Age", nullptr));
        selon_stat_c->setItemText(2, QCoreApplication::translate("MainWindow", "Nivaeu permis", nullptr));

        label_49->setText(QString());
        tab_widget2_c->setTabText(tab_widget2_c->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ID de candidat :", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Progress bar :", nullptr));
        label_48->setText(QString());
        tab_widget2_c->setTabText(tab_widget2_c->indexOf(tab_8), QCoreApplication::translate("MainWindow", "Progression", nullptr));
        tab_widget_c->setTabText(tab_widget_c->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Fonctionnalit\303\251", nullptr));
        groupBoxm->setTitle(QCoreApplication::translate("MainWindow", "Ajouter un moniteur ", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "T\303\251lephone", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "Exp\303\251rience ", nullptr));
        specialite->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir", nullptr));
        specialite->setItemText(1, QCoreApplication::translate("MainWindow", "Permis A", nullptr));
        specialite->setItemText(2, QCoreApplication::translate("MainWindow", "Permis B", nullptr));
        specialite->setItemText(3, QCoreApplication::translate("MainWindow", "Permis C", nullptr));
        specialite->setItemText(4, QCoreApplication::translate("MainWindow", "Permis D", nullptr));

        actif->setText(QCoreApplication::translate("MainWindow", "Actif", nullptr));
        inactif->setText(QCoreApplication::translate("MainWindow", "Inactif", nullptr));
        reinstaller_mon->setText(QCoreApplication::translate("MainWindow", "R\303\251installer", nullptr));
        enregistrer_m->setText(QCoreApplication::translate("MainWindow", "Enregistrer \360\237\222\276", nullptr));
        filtrer_mon->setItemText(0, QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        filtrer_mon->setItemText(1, QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251", nullptr));
        filtrer_mon->setItemText(2, QCoreApplication::translate("MainWindow", "disponibilit\303\251", nullptr));

        trier_mon->setItemText(0, QCoreApplication::translate("MainWindow", "Trier", nullptr));
        trier_mon->setItemText(1, QCoreApplication::translate("MainWindow", "A-Z", nullptr));
        trier_mon->setItemText(2, QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251", nullptr));

        taper_mon->setPlaceholderText(QCoreApplication::translate("MainWindow", "Taper...", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "Gestion Moniteurs ", nullptr));
        supp_m->setText(QCoreApplication::translate("MainWindow", "Supprimer \360\237\227\221\357\270\217", nullptr));
        expo_tab_m->setText(QCoreApplication::translate("MainWindow", " Exporter", nullptr));
        modifier_m->setText(QCoreApplication::translate("MainWindow", "Modifier \342\234\217\357\270\217", nullptr));
        conf_rech_m->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Confirmer", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tab_mon->horizontalHeaderItem(0);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tab_mon->horizontalHeaderItem(1);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tab_mon->horizontalHeaderItem(2);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tab_mon->horizontalHeaderItem(3);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tab_mon->horizontalHeaderItem(4);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tab_mon->horizontalHeaderItem(5);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251", nullptr));

        const bool __sortingEnabled = tab_mon->isSortingEnabled();
        tab_mon->setSortingEnabled(false);
        tab_mon->setSortingEnabled(__sortingEnabled);

        label_61->setText(QString());
        widget_m->setTabText(widget_m->indexOf(tab_16), QCoreApplication::translate("MainWindow", "Ajout ", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Statistique des sp\303\251cialit\303\251", nullptr));
        tab_widget2->setTabText(tab_widget2->indexOf(tab_18), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "Votre assistante est \303\240 votre service  !", nullptr));
        expo_ai_m->setText(QCoreApplication::translate("MainWindow", " Exporter", nullptr));
        tab_widget2->setTabText(tab_widget2->indexOf(tab_19), QCoreApplication::translate("MainWindow", "Assistante int\303\251lligente ", nullptr));
        widget_m->setTabText(widget_m->indexOf(tab_17), QCoreApplication::translate("MainWindow", "Fonctionnalit\303\251", nullptr));
        barre_nav->setTitle(QString());
        fermer_btn->setText(QCoreApplication::translate("MainWindow", "\342\234\226\357\270\217\342\200\213 Fermer", nullptr));
        seance_btn->setText(QCoreApplication::translate("MainWindow", " Gestion S\303\251ances", nullptr));
        vehicule_btn->setText(QCoreApplication::translate("MainWindow", " Gestion V\303\251hicules", nullptr));
        emp_btn->setText(QCoreApplication::translate("MainWindow", " Gestion Employ\303\251s", nullptr));
        moniteur_btn->setText(QCoreApplication::translate("MainWindow", "Gestion Moniteurs ", nullptr));
        label_30->setText(QString());
        candidat_btn->setText(QCoreApplication::translate("MainWindow", "Gestion Candidats", nullptr));
        accueil->setText(QCoreApplication::translate("MainWindow", " accueil", nullptr));
        barre->setTitle(QString());
        titre->setText(QCoreApplication::translate("MainWindow", "Smart Drive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

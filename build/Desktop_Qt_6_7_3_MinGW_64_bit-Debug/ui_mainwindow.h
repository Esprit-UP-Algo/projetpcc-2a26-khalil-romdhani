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
#include <QtWidgets/QPushButton>
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
    QFrame *frame;
    QTabWidget *tabWidget_s;
    QWidget *tab;
    QGroupBox *groupBox;
    QLineEdit *ID_s;
    QLabel *label;
    QComboBox *type_s;
    QDateEdit *date_s;
    QTimeEdit *deb_s;
    QTimeEdit *fin_s;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *confirm_ajout_s;
    QPushButton *annul_s;
    QLabel *label_8;
    QTableWidget *tab_s;
    QPushButton *confirm_s;
    QPushButton *exp_s;
    QPushButton *filtre_s;
    QComboBox *tri_s;
    QLineEdit *recherche_s;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *tab_2;
    QGroupBox *groupBox_stats;
    QLabel *label_totalSessions;
    QLabel *label_totalHours;
    QTableWidget *stats_s;
    QPushButton *refresh_s;
    QWidget *tab_3;
    QCalendarWidget *calendar_s;
    QGroupBox *Details_s;
    QListWidget *listWidget_sessions;
    QWidget *tab_4;
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
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1135, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1141, 621));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        tabWidget_s = new QTabWidget(frame);
        tabWidget_s->setObjectName("tabWidget_s");
        tabWidget_s->setGeometry(QRect(0, 0, 1131, 581));
        tabWidget_s->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 60, 331, 441));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ID_s = new QLineEdit(groupBox);
        ID_s->setObjectName("ID_s");
        ID_s->setGeometry(QRect(80, 20, 151, 41));
        ID_s->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 1px solid #0074D9;\n"
"    border-radius: 3px;\n"
"    padding: 6px;\n"
"    color: #FFFFFF;\n"
"    selection-background-color: #00C851;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00C851;\n"
"    background-color: #002B5C; /* Slightly lighter blue */\n"
"}\n"
"QLineEdit::placeholder {\n"
"    color: #AAAAAA;\n"
"}"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 63, 20));
        label->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        type_s = new QComboBox(groupBox);
        type_s->addItem(QString());
        type_s->addItem(QString());
        type_s->addItem(QString());
        type_s->setObjectName("type_s");
        type_s->setGeometry(QRect(80, 80, 151, 41));
        type_s->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(27, 27, 27);"));
        date_s = new QDateEdit(groupBox);
        date_s->setObjectName("date_s");
        date_s->setGeometry(QRect(80, 140, 151, 41));
        date_s->setStyleSheet(QString::fromUtf8(""));
        deb_s = new QTimeEdit(groupBox);
        deb_s->setObjectName("deb_s");
        deb_s->setGeometry(QRect(80, 210, 151, 41));
        deb_s->setStyleSheet(QString::fromUtf8(""));
        fin_s = new QTimeEdit(groupBox);
        fin_s->setObjectName("fin_s");
        fin_s->setGeometry(QRect(80, 280, 151, 41));
        fin_s->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 150, 63, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 220, 63, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 290, 63, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        confirm_ajout_s = new QPushButton(groupBox);
        confirm_ajout_s->setObjectName("confirm_ajout_s");
        confirm_ajout_s->setGeometry(QRect(10, 350, 121, 29));
        confirm_ajout_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00C851;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #00E676;\n"
"    transform: scale(1.05);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #00B140;\n"
"    transform: scale(0.98);\n"
"    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.2);\n"
"}\n"
"QPushButton:disabled {\n"
"    background-color: #AAAAAA;\n"
"    color: #666666;\n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        confirm_ajout_s->setIcon(icon);
        annul_s = new QPushButton(groupBox);
        annul_s->setObjectName("annul_s");
        annul_s->setGeometry(QRect(160, 350, 31, 31));
        annul_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: Red;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #00E676;\n"
"    transform: scale(1.05);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #00B140;\n"
"    transform: scale(0.98);\n"
"    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.2);\n"
"}\n"
"QPushButton:disabled {\n"
"    background-color: #AAAAAA;\n"
"    color: #666666;\n"
"}"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        annul_s->setIcon(icon1);
        annul_s->setIconSize(QSize(20, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 90, 63, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        tab_s = new QTableWidget(tab);
        if (tab_s->columnCount() < 12)
            tab_s->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tab_s->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        tab_s->setObjectName("tab_s");
        tab_s->setGeometry(QRect(350, 100, 611, 311));
        tab_s->setStyleSheet(QString::fromUtf8(""));
        tab_s->horizontalHeader()->setStretchLastSection(false);
        confirm_s = new QPushButton(tab);
        confirm_s->setObjectName("confirm_s");
        confirm_s->setGeometry(QRect(840, 60, 111, 31));
        confirm_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00C851;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #00E676;\n"
"    transform: scale(1.05);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #00B140;\n"
"    transform: scale(0.98);\n"
"    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.2);\n"
"}\n"
"QPushButton:disabled {\n"
"    background-color: #AAAAAA;\n"
"    color: #666666;\n"
"}"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        confirm_s->setIcon(icon2);
        exp_s = new QPushButton(tab);
        exp_s->setObjectName("exp_s");
        exp_s->setGeometry(QRect(350, 430, 121, 35));
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
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        exp_s->setIcon(icon3);
        filtre_s = new QPushButton(tab);
        filtre_s->setObjectName("filtre_s");
        filtre_s->setGeometry(QRect(480, 60, 90, 29));
        tri_s = new QComboBox(tab);
        tri_s->addItem(QString());
        tri_s->addItem(QString());
        tri_s->addItem(QString());
        tri_s->setObjectName("tri_s");
        tri_s->setGeometry(QRect(360, 60, 111, 28));
        tri_s->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        recherche_s = new QLineEdit(tab);
        recherche_s->setObjectName("recherche_s");
        recherche_s->setGeometry(QRect(720, 60, 113, 28));
        recherche_s->setAutoFillBackground(false);
        recherche_s->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF;\n"
"    font-size: 12px;\n"
"}"));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 10, 161, 20));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 40, 63, 20));
        tabWidget_s->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox_stats = new QGroupBox(tab_2);
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
        label_totalSessions->setStyleSheet(QString::fromUtf8("font-size: 14px; font-weight: bold;"));
        label_totalHours = new QLabel(groupBox_stats);
        label_totalHours->setObjectName("label_totalHours");
        label_totalHours->setGeometry(QRect(20, 70, 200, 30));
        label_totalHours->setStyleSheet(QString::fromUtf8("font-size: 14px; font-weight: bold;"));
        stats_s = new QTableWidget(groupBox_stats);
        if (stats_s->columnCount() < 4)
            stats_s->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        stats_s->setHorizontalHeaderItem(3, __qtablewidgetitem15);
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
        refresh_s = new QPushButton(tab_2);
        refresh_s->setObjectName("refresh_s");
        refresh_s->setGeometry(QRect(480, 30, 120, 40));
        refresh_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00C851;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #00E676;\n"
"    transform: scale(1.05);\n"
"}"));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::ViewRefresh));
        refresh_s->setIcon(icon4);
        tabWidget_s->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        calendar_s = new QCalendarWidget(tab_3);
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
        Details_s = new QGroupBox(tab_3);
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
        tabWidget_s->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        groupBox_map = new QGroupBox(tab_4);
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
        label_distance->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        label_duration = new QLabel(groupBox_route);
        label_duration->setObjectName("label_duration");
        label_duration->setGeometry(QRect(10, 200, 180, 25));
        label_duration->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
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
        label_mapTitle->setStyleSheet(QString::fromUtf8("font-size: 14px; font-weight: bold;"));
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
        tabWidget_s->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget_s->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        tabWidget_s->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>autre</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        type_s->setItemText(0, QCoreApplication::translate("MainWindow", "choisir", nullptr));
        type_s->setItemText(1, QCoreApplication::translate("MainWindow", "Conduite", nullptr));
        type_s->setItemText(2, QCoreApplication::translate("MainWindow", "Code", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "D\303\251but_H", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Fin_H", nullptr));
        confirm_ajout_s->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        annul_s->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab_s->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID_S\303\251ance", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab_s->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab_s->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab_s->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Heure d\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab_s->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Heure fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab_s->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Salle", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tab_s->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Long. d\303\251part", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tab_s->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Lat. d\303\251part", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tab_s->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Long. arriv\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tab_s->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Lat. arriv\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tab_s->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tab_s->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        confirm_s->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        exp_s->setText(QCoreApplication::translate("MainWindow", "Export Excel", nullptr));
        filtre_s->setText(QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        tri_s->setItemText(0, QCoreApplication::translate("MainWindow", "Trier par", nullptr));
        tri_s->setItemText(1, QCoreApplication::translate("MainWindow", "Date", nullptr));
        tri_s->setItemText(2, QCoreApplication::translate("MainWindow", "Type", nullptr));

        recherche_s->setPlaceholderText(QCoreApplication::translate("MainWindow", "     ID_S\303\251ance", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Gestion des seances", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        tabWidget_s->setTabText(tabWidget_s->indexOf(tab), QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        groupBox_stats->setTitle(QCoreApplication::translate("MainWindow", "Statistiques des S\303\251ances", nullptr));
        label_totalSessions->setText(QCoreApplication::translate("MainWindow", "Total des s\303\251ances: 0", nullptr));
        label_totalHours->setText(QCoreApplication::translate("MainWindow", "Heures totales: 0h", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = stats_s->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "\303\211l\303\250ve/Moniteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = stats_s->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Nb s\303\251ances", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = stats_s->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Heures totales", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = stats_s->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Type dominant", nullptr));
        refresh_s->setText(QCoreApplication::translate("MainWindow", "Actualiser", nullptr));
        tabWidget_s->setTabText(tabWidget_s->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        Details_s->setTitle(QCoreApplication::translate("MainWindow", "D\303\251tails des S\303\251ances", nullptr));
        tabWidget_s->setTabText(tabWidget_s->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Calendrier", nullptr));
        groupBox_map->setTitle(QCoreApplication::translate("MainWindow", "Planification des Trajets", nullptr));
        label_mapView->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        label_routePreview->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        groupBox_route->setTitle(QCoreApplication::translate("MainWindow", "Contr\303\264les de Route", nullptr));
        departure_s->setPlaceholderText(QCoreApplication::translate("MainWindow", "Point de d\303\251part", nullptr));
        destination_s->setPlaceholderText(QCoreApplication::translate("MainWindow", "Destination", nullptr));
        calculateRoute_s->setText(QCoreApplication::translate("MainWindow", "Calculer trajet", nullptr));
        label_distance->setText(QCoreApplication::translate("MainWindow", "Distance: -- km", nullptr));
        label_duration->setText(QCoreApplication::translate("MainWindow", "Dur\303\251e: -- min", nullptr));
        saveRoute_s->setText(QCoreApplication::translate("MainWindow", "Sauvegarder trajet", nullptr));
        clearRoute_s->setText(QCoreApplication::translate("MainWindow", "Effacer trajet", nullptr));
        label_routeStatus->setText(QCoreApplication::translate("MainWindow", "\360\237\223\215 Statut: En attente\\n\360\237\227\272\357\270\217 Pr\303\252t \303\240 calculer", nullptr));
        label_mapTitle->setText(QCoreApplication::translate("MainWindow", "\360\237\227\272\357\270\217 Carte Interactive - Planification des S\303\251ances de Conduite", nullptr));
        mapType_s->setItemText(0, QCoreApplication::translate("MainWindow", "\360\237\214\215 Vue Satellite", nullptr));
        mapType_s->setItemText(1, QCoreApplication::translate("MainWindow", "\360\237\227\272\357\270\217 Vue Carte", nullptr));
        mapType_s->setItemText(2, QCoreApplication::translate("MainWindow", "\360\237\232\227 Vue Trafic", nullptr));

        centerMap_s->setText(QCoreApplication::translate("MainWindow", "\360\237\223\215 Localiser", nullptr));
        tabWidget_s->setTabText(tabWidget_s->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Carte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

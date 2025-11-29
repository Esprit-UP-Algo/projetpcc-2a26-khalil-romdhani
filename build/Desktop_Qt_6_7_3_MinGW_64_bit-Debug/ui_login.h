/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QFrame *barre_nav;
    QLabel *label;
    QLabel *label_login;
    QLabel *label_password;
    QLineEdit *id;
    QLineEdit *mdp;
    QPushButton *motdepassoubli_E;
    QPushButton *connect;
    QLabel *label_login_2;
    QLabel *label_login_3;
    QLabel *label_sign;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(1549, 890);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 1501, 751));
        barre_nav = new QFrame(centralwidget);
        barre_nav->setObjectName("barre_nav");
        barre_nav->setGeometry(QRect(10, 10, 1501, 761));
        barre_nav->setStyleSheet(QString::fromUtf8("#barre_nav {\n"
"	background-color: rgb(0, 85, 127);\n"
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
        label = new QLabel(barre_nav);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 80, 271, 211));
        label->setPixmap(QPixmap(QString::fromUtf8(":/yyyy/images/logo.png")));
        label_login = new QLabel(barre_nav);
        label_login->setObjectName("label_login");
        label_login->setGeometry(QRect(340, 230, 181, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        label_login->setFont(font);
        label_login->setStyleSheet(QString::fromUtf8("#label_login {\n"
"    color: #FBFAF5;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    padding: 8px 4px;\n"
"    background-color: transparent;\n"
"    text-shadow: 1px 1px 2px rgba(0,0,0,0.3);\n"
"}"));
        label_password = new QLabel(barre_nav);
        label_password->setObjectName("label_password");
        label_password->setGeometry(QRect(340, 310, 161, 41));
        label_password->setFont(font);
        label_password->setStyleSheet(QString::fromUtf8("#label_password {\n"
"    color: #FBFAF5;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    padding: 8px 4px;\n"
"    background-color: transparent;\n"
"    text-shadow: 1px 1px 2px rgba(0,0,0,0.3);\n"
"}"));
        id = new QLineEdit(barre_nav);
        id->setObjectName("id");
        id->setGeometry(QRect(530, 220, 341, 51));
        id->setStyleSheet(QString::fromUtf8("#id {\n"
"    border: 1px solid #0F2434;\n"
"    border-radius: 4px;\n"
"    padding: 6px 10px;\n"
"    font-size: 13px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#id:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"    background-color: #FFFFFF;\n"
"}"));
        mdp = new QLineEdit(barre_nav);
        mdp->setObjectName("mdp");
        mdp->setGeometry(QRect(530, 310, 341, 51));
        mdp->setStyleSheet(QString::fromUtf8("#mdp {\n"
"    border: 1px solid #0F2434;\n"
"    border-radius: 4px;\n"
"    padding: 6px 10px;\n"
"    font-size: 13px;\n"
"    background-color: #FBFAF5;\n"
"    color: #0F2434;\n"
"}\n"
"\n"
"#mdp:focus {\n"
"    border: 2px solid #1D9E3A;\n"
"    background-color: #FFFFFF;\n"
"}"));
        mdp->setEchoMode(QLineEdit::EchoMode::Password);
        motdepassoubli_E = new QPushButton(barre_nav);
        motdepassoubli_E->setObjectName("motdepassoubli_E");
        motdepassoubli_E->setGeometry(QRect(520, 380, 151, 29));
        motdepassoubli_E->setStyleSheet(QString::fromUtf8("#motdepassoubli_E {\n"
"    background-color: transparent;\n"
"    color: #3498DB;\n"
"    border: none;\n"
"    padding: 4px 8px;\n"
"    font-size: 11px;\n"
"    text-decoration: underline;\n"
"    font-weight: normal;\n"
"}\n"
"\n"
"#motdepassoubli_E:hover {\n"
"    color: #2980B9;\n"
"    background-color: rgba(52, 152, 219, 0.1);\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"#motdepassoubli_E:pressed {\n"
"    color: #21618C;\n"
"}"));
        connect = new QPushButton(barre_nav);
        connect->setObjectName("connect");
        connect->setGeometry(QRect(540, 450, 171, 41));
        connect->setStyleSheet(QString::fromUtf8("#connect {\n"
"    background-color: rgb(29, 158, 58);\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    border-radius: 6px;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"\n"
"#connect:hover {\n"
"    background-color: #30AA2C;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#connect:pressed {\n"
"    background-color: #239539;\n"
"    transform: scale(0.98);\n"
"}"));
        connect->setAutoDefault(false);
        connect->setFlat(false);
        label_login_2 = new QLabel(barre_nav);
        label_login_2->setObjectName("label_login_2");
        label_login_2->setGeometry(QRect(270, 220, 71, 41));
        label_login_2->setFont(font);
        label_login_2->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/icons_prj_cpp/login.png);\n"
""));
        label_login_3 = new QLabel(barre_nav);
        label_login_3->setObjectName("label_login_3");
        label_login_3->setGeometry(QRect(260, 310, 81, 41));
        label_login_3->setFont(font);
        label_login_3->setStyleSheet(QString::fromUtf8("image: url(:/logo/img/icons_prj_cpp/mdp.png);"));
        label_sign = new QLabel(barre_nav);
        label_sign->setObjectName("label_sign");
        label_sign->setGeometry(QRect(560, 150, 261, 61));
        label_sign->setFont(font);
        label_sign->setStyleSheet(QString::fromUtf8("#label_sign {\n"
"    color: #FFFFFF;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    padding: 12px 6px;\n"
"    background-color: transparent;\n"
"    text-shadow: 0 2px 4px rgba(0,0,0,0.5);\n"
"    text-align: center;\n"
"    letter-spacing: 0.5px;\n"
"    border-bottom: 2px solid #1D9E3A;\n"
"    margin-bottom: 15px;\n"
"}"));
        menubar = new QMenuBar(Login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1508, 26));
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 16, 25));

        retranslateUi(Login);

        connect->setDefault(false);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "login", nullptr));
        label->setText(QString());
        label_login->setText(QCoreApplication::translate("Login", "ID d'utilisateur :", nullptr));
        label_password->setText(QCoreApplication::translate("Login", "Mot de passe :", nullptr));
        id->setInputMask(QString());
        id->setText(QString());
        motdepassoubli_E->setText(QCoreApplication::translate("Login", "Mot de pass oubli\303\251?", nullptr));
        connect->setText(QCoreApplication::translate("Login", "Se connecter", nullptr));
        label_login_2->setText(QString());
        label_login_3->setText(QString());
        label_sign->setText(QCoreApplication::translate("Login", "Veuillez vous identifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

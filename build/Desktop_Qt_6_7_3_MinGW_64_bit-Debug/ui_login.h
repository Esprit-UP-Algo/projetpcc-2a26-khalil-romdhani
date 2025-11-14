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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(1508, 859);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 1501, 751));
        barre_nav = new QFrame(centralwidget);
        barre_nav->setObjectName("barre_nav");
        barre_nav->setGeometry(QRect(10, 10, 1481, 731));
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
        label_login->setGeometry(QRect(360, 220, 181, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_login->setFont(font);
        label_login->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_password = new QLabel(barre_nav);
        label_password->setObjectName("label_password");
        label_password->setGeometry(QRect(360, 320, 141, 20));
        label_password->setFont(font);
        label_password->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        id = new QLineEdit(barre_nav);
        id->setObjectName("id");
        id->setGeometry(QRect(530, 220, 341, 51));
        id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        mdp = new QLineEdit(barre_nav);
        mdp->setObjectName("mdp");
        mdp->setGeometry(QRect(530, 320, 341, 51));
        mdp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        mdp->setEchoMode(QLineEdit::EchoMode::Password);
        motdepassoubli_E = new QPushButton(barre_nav);
        motdepassoubli_E->setObjectName("motdepassoubli_E");
        motdepassoubli_E->setGeometry(QRect(540, 390, 151, 29));
        motdepassoubli_E->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 36, 52);\n"
"color: rgb(29, 158, 58);"));
        connect = new QPushButton(barre_nav);
        connect->setObjectName("connect");
        connect->setGeometry(QRect(620, 450, 171, 41));
        connect->setStyleSheet(QString::fromUtf8("#connect{\n"
"    background-color: rgb(29, 158, 58); /* couleur normale */\n"
"    color: white;                       /* couleur du texte */\n"
"    border: none;\n"
"    padding: 5px 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"#connect:pressed {\n"
"    background-color: #239539; /* couleur quand le bouton est cliqu\303\251 */\n"
"}\n"
""));
        connect->setAutoDefault(false);
        connect->setFlat(false);
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
        label_login->setText(QCoreApplication::translate("Login", "ID d'utilisateur:", nullptr));
        label_password->setText(QCoreApplication::translate("Login", "Mot de pass:", nullptr));
        motdepassoubli_E->setText(QCoreApplication::translate("Login", "Mot de pass oubli\303\251?", nullptr));
        connect->setText(QCoreApplication::translate("Login", "Se connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

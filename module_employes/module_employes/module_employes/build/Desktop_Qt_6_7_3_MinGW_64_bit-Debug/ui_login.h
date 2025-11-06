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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QFrame *barre_nav;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(1312, 715);
        barre_nav = new QFrame(login);
        barre_nav->setObjectName("barre_nav");
        barre_nav->setGeometry(QRect(-10, -10, 1221, 701));
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
        label_2 = new QLabel(barre_nav);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(360, 220, 181, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(barre_nav);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(360, 320, 141, 20));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_login = new QLineEdit(barre_nav);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setGeometry(QRect(530, 220, 341, 51));
        lineEdit_login->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_password = new QLineEdit(barre_nav);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(530, 320, 341, 51));
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_2 = new QPushButton(barre_nav);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(540, 390, 151, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 36, 52);\n"
"color: rgb(29, 158, 58);"));
        pushButton = new QPushButton(barre_nav);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(620, 450, 171, 41));
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
""));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("login", "Nom d'utilisateur:", nullptr));
        label_3->setText(QCoreApplication::translate("login", "Mot de pass:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("login", "Mot de pass oubli\303\251?", nullptr));
        pushButton->setText(QCoreApplication::translate("login", "Se connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

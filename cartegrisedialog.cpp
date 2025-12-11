#include "cartegrisedialog.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QFont>
#include <QWidget>
#include <QDebug>

CarteGriseDialog::CarteGriseDialog(const QMap<QString, QVariant>& vehicleData, QWidget* parent)
    : QDialog(parent), m_vehicleData(vehicleData)
{
    setupUI();
    setWindowTitle("Carte Grise - Certificat d'Immatriculation");
    setFixedSize(1000, 400);
}

void CarteGriseDialog::saveAsJPG()
{
    QString matricule = m_vehicleData["matricule"].toString();
    QString defaultFileName = matricule + ".jpg";

    QString fileName = QFileDialog::getSaveFileName(this, "Sauvegarder la carte grise", defaultFileName, "Images JPG (*.jpg)");
    if(fileName.isEmpty()) return;

    if(!fileName.endsWith(".jpg", Qt::CaseInsensitive)) {
        fileName += ".jpg";
    }

    btnSaveJPG->hide();
    btnClose->hide();

    QPixmap pixmap = this->grab();

    btnSaveJPG->show();
    btnClose->show();

    if(pixmap.save(fileName, "JPG")) {
        QMessageBox::information(this, "Succès", "Carte grise sauvegardée avec succès");
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la sauvegarde");
    }
}

void CarteGriseDialog::setupUI()
{
    labelMatricule = new QLabel(m_vehicleData["matricule"].toString());
    labelNomPrenom = new QLabel("Bedis Akremi");
    labelAdresse = new QLabel("Tunis, Tunisie");
    labelActivite = new QLabel("Auto-école");
    labelGenre = new QLabel(m_vehicleData["type"].toString());
    labelConstructeur = new QLabel(m_vehicleData["marque"].toString());
    labelTypeConstructeur = new QLabel(m_vehicleData["modele"].toString());
    labelDPMC = new QLabel(m_vehicleData["date_achat"].toDate().toString("dd/MM/yyyy"));

    QString labelStyle = "QLabel { padding: 6px; background-color: transparent; font-weight: bold; color: black; font-size: 12px; }";
    QString matriculeStyle = "QLabel { padding: 8px; background-color: transparent; font-weight: bold; font-size: 16px; color: black; }";

    labelMatricule->setStyleSheet(matriculeStyle);
    labelNomPrenom->setStyleSheet(labelStyle);
    labelAdresse->setStyleSheet(labelStyle);
    labelActivite->setStyleSheet(labelStyle);
    labelGenre->setStyleSheet(labelStyle);
    labelConstructeur->setStyleSheet(labelStyle);
    labelTypeConstructeur->setStyleSheet(labelStyle);
    labelDPMC->setStyleSheet(labelStyle);

    labelMatricule->setAlignment(Qt::AlignCenter);
    labelMatricule->setFixedWidth(180);

    btnClose = new QPushButton("Fermer");
    btnSaveJPG = new QPushButton("Sauvegarder");

    QString buttonStyle =
        "QPushButton {"
        "    background-color: #FFD700;"
        "    color: black;"
        "    font-weight: bold;"
        "    border: 2px solid #D4AF37;"
        "    border-radius: 5px;"
        "    padding: 8px 12px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #FFEC8B;"
        "    border: 2px solid #FFD700;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #D4AF37;"
        "    border: 2px solid #B8860B;"
        "}";

    btnClose->setStyleSheet(buttonStyle);
    btnSaveJPG->setStyleSheet(buttonStyle);

    connect(btnClose, &QPushButton::clicked, this, &CarteGriseDialog::close);
    connect(btnSaveJPG, &QPushButton::clicked, this, &CarteGriseDialog::saveAsJPG);

    QHBoxLayout* contentLayout = new QHBoxLayout;
    contentLayout->setSpacing(0);

    leftColorWidget = new QWidget;
    leftColorWidget->setStyleSheet("background-color: #7594CA;");
    leftColorWidget->setFixedWidth(200);
    QVBoxLayout* leftLayout = new QVBoxLayout(leftColorWidget);

    QVBoxLayout* matriculeLayout = new QVBoxLayout;
    QLabel* matriculeTitle = new QLabel("N° immatriculation\nرقم التسجيل");
    matriculeTitle->setAlignment(Qt::AlignCenter);
    matriculeTitle->setStyleSheet("font-weight: bold; margin-bottom: 6px; color: black; font-size: 12px;");
    matriculeLayout->addWidget(matriculeTitle);
    matriculeLayout->addWidget(labelMatricule);
    matriculeLayout->addStretch();

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(btnSaveJPG);
    buttonLayout->addWidget(btnClose);

    leftLayout->addLayout(matriculeLayout);
    leftLayout->addStretch();
    leftLayout->addLayout(buttonLayout);

    rightColorWidget = new QWidget;
    rightColorWidget->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #74B5EB, stop:0.5 #A9CEDF, stop:1 #71AFE3);");
    QVBoxLayout* rightContentLayout = new QVBoxLayout(rightColorWidget);

    QLabel* headerLeft1 = new QLabel("République Tunisienne");
    QLabel* headerLeft2 = new QLabel("Certificat D'immatriculation");
    QLabel* headerRight1 = new QLabel("الجمهورية التونسية");
    QLabel* headerRight2 = new QLabel("شهادة التسجيل");

    QFont headerFont("Arial", 16, QFont::Bold);
    headerLeft1->setFont(headerFont);
    headerLeft2->setFont(headerFont);
    headerRight1->setFont(headerFont);
    headerRight2->setFont(headerFont);
    headerRight1->setAlignment(Qt::AlignRight);
    headerRight2->setAlignment(Qt::AlignRight);
    headerLeft1->setStyleSheet("background-color: transparent; color: black;");
    headerLeft2->setStyleSheet("background-color: transparent; color: black;");
    headerRight1->setStyleSheet("background-color: transparent; color: black;");
    headerRight2->setStyleSheet("background-color: transparent; color: black;");

    QLabel* flagLabel = new QLabel;
    QString imagePath = ":/image/image/tn.png";
    QPixmap flagPixmap(imagePath);

    if (flagPixmap.isNull()) {
        flagLabel->setText("TN Flag");
        flagLabel->setStyleSheet("background-color: transparent; color: red; font-weight: bold;");
    } else {
        flagPixmap = flagPixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        flagLabel->setPixmap(flagPixmap);
        flagLabel->setStyleSheet("background-color: transparent;");
    }

    flagLabel->setAlignment(Qt::AlignCenter);

    QHBoxLayout* headerLayout = new QHBoxLayout;
    QVBoxLayout* leftHeader = new QVBoxLayout;
    QVBoxLayout* rightHeader = new QVBoxLayout;

    leftHeader->addWidget(headerLeft1);
    leftHeader->addWidget(headerLeft2);
    rightHeader->addWidget(headerRight1);
    rightHeader->addWidget(headerRight2);

    headerLayout->addLayout(leftHeader);
    headerLayout->addStretch();
    headerLayout->addWidget(flagLabel);
    headerLayout->addStretch();
    headerLayout->addLayout(rightHeader);

    QGridLayout* gridLayout = new QGridLayout;
    gridLayout->setVerticalSpacing(8);
    gridLayout->setHorizontalSpacing(15);

    gridLayout->setColumnStretch(0, 0);
    gridLayout->setColumnStretch(1, 1);

    QLabel* labelNomPrenomText = new QLabel("Nom et Prénom / الإسم و اللقب:");
    QLabel* labelAdresseText = new QLabel("Adresse / العنوان:");
    QLabel* labelActiviteText = new QLabel("Activité / النشاط:");
    QLabel* labelGenreText = new QLabel("Genre / الصنف:");
    QLabel* labelConstructeurText = new QLabel("Constructeur / الصانع:");
    QLabel* labelTypeText = new QLabel("Type constructeur / نوع الصنع:");
    QLabel* labelDPMCText = new QLabel("DPMC / تاريخ أول إذن بالجولان:");

    QString labelTextStyle = "QLabel { background-color: transparent; font-weight: bold; color: black; font-size: 12px; }";
    labelNomPrenomText->setStyleSheet(labelTextStyle);
    labelAdresseText->setStyleSheet(labelTextStyle);
    labelActiviteText->setStyleSheet(labelTextStyle);
    labelGenreText->setStyleSheet(labelTextStyle);
    labelConstructeurText->setStyleSheet(labelTextStyle);
    labelTypeText->setStyleSheet(labelTextStyle);
    labelDPMCText->setStyleSheet(labelTextStyle);

    gridLayout->addWidget(labelNomPrenom, 0, 0);
    gridLayout->addWidget(labelNomPrenomText, 0, 1, Qt::AlignRight);

    gridLayout->addWidget(labelAdresse, 1, 0);
    gridLayout->addWidget(labelAdresseText, 1, 1, Qt::AlignRight);

    gridLayout->addWidget(labelActivite, 2, 0);
    gridLayout->addWidget(labelActiviteText, 2, 1, Qt::AlignRight);

    gridLayout->addWidget(labelGenre, 3, 0);
    gridLayout->addWidget(labelGenreText, 3, 1, Qt::AlignRight);

    gridLayout->addWidget(labelConstructeur, 4, 0);
    gridLayout->addWidget(labelConstructeurText, 4, 1, Qt::AlignRight);

    gridLayout->addWidget(labelTypeConstructeur, 5, 0);
    gridLayout->addWidget(labelTypeText, 5, 1, Qt::AlignRight);

    gridLayout->addWidget(labelDPMC, 6, 0);
    gridLayout->addWidget(labelDPMCText, 6, 1, Qt::AlignRight);

    rightContentLayout->addLayout(headerLayout);
    rightContentLayout->addSpacing(15);
    rightContentLayout->addLayout(gridLayout);
    rightContentLayout->addStretch();

    contentLayout->addWidget(leftColorWidget);
    contentLayout->addWidget(rightColorWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(contentLayout);

    setLayout(mainLayout);
}


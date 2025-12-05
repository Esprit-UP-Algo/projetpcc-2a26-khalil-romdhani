#ifndef CARTEGRISEDIALOG_H
#define CARTEGRISEDIALOG_H

#include <QDialog>
#include <QMap>
#include <QVariant>

class QLabel;
class QPushButton;
class QWidget;

class CarteGriseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CarteGriseDialog(const QMap<QString, QVariant>& vehicleData, QWidget* parent = nullptr);

private slots:
    void saveAsJPG();

private:
    void setupUI();
    QMap<QString, QVariant> m_vehicleData;

    QLabel* labelMatricule;
    QLabel* labelNomPrenom;
    QLabel* labelAdresse;
    QLabel* labelActivite;
    QLabel* labelGenre;
    QLabel* labelConstructeur;
    QLabel* labelTypeConstructeur;
    QLabel* labelDPMC;

    QPushButton* btnClose;
    QPushButton* btnSaveJPG;

    QWidget* leftColorWidget;
    QWidget* rightColorWidget;

};

#endif

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QVBoxLayout> // AJOUT IMPORTANT
#include "Candidat.h"
#include "StatCandidat.h"
#include "ArduinoManager.h"
#include "JournalCandidat.h"
#include "ImageVer_C.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ImageVer_C* getImageVerif() const { return m_imageVerif; }

private slots:
    // Navigation
    void on_fermer_btn_clicked();
    void on_vehicule_btn_clicked();
    void on_candidat_btn_clicked();
    void on_seance_btn_clicked();
    void on_emp_btn_clicked();
    void on_moniteur_btn_clicked();

    // Candidat operations
    void on_enregistrer_c_clicked();
    void on_modifier_c_clicked();
    void on_supp_c_clicked();
    void on_expo_tab_c_clicked();
    void on_table_candidat_doubleClicked(const QModelIndex &index);

    // Recherche et filtrage
    void onFiltrerChanged(const QString &filterText);
    void onTrierChanged(const QString &sortText);
    void on_conf_rech_c_clicked();

    // Progression
    void on_prog_idcandidat_textChanged(const QString &text);

    // Journal
    void on_viderJournal_clicked();
    void on_voirJournalComplet_clicked();
    void onArduinoButtonPressed(ArduinoManager::ButtonType button);
    void onArduinoConnectionChanged(bool connected);
    void handleArduinoConfirm();
    void initialiserArduino();  // AJOUT - nouvelle méthode
private:
    Ui::MainWindow *ui;
    Candidat c;
    int currentCandidatId;
    bool isEditingCandidat;
    StatCandidat *m_statCandidat;
    JournalCandidat *m_journalCandidat;
    ImageVer_C *m_imageVerif;
    ArduinoManager *m_arduinoManager;
    bool m_arduinoControlActive;
    int m_arduinoControlledId;
    void initialiserInterface();
    void initialiserStatistiques();
    void initialiserJournal();
    void initialiserGestionImages();
    void connecterSignaux();
    QString getCurrentProgression() const;
    void updateArduinoDisplay(int percent, const QString &progression);
    void debugArduinoState(const QString &message);
    void resetCheckboxesFromProgression(const QString &progression);
};

#endif

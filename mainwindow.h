#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QVBoxLayout>
#include "Candidat.h"
#include "StatCandidat.h"
#include "JournalCandidat.h"
#include "ImageVer_C.h"
#include "groq_manager.h"
#include "veh_func.h"
#include "veh.h"

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
    void on_fermer_btn_clicked();
    void on_acceuil_clicked();
    void on_vehicule_btn_clicked();
    void on_candidat_btn_clicked();
    void on_seance_btn_clicked();
    void on_emp_btn_clicked();
    void on_moniteur_btn_clicked();
    void on_enregistrer_c_clicked();
    void on_modifier_c_clicked();
    void on_supp_c_clicked();
    void on_expo_tab_c_clicked();
    void on_table_candidat_doubleClicked(const QModelIndex &index);
    void onFiltrerChanged(const QString &filterText);
    void onTrierChanged(const QString &sortText);
    void on_conf_rech_c_clicked();
    void on_prog_idcandidat_textChanged(const QString &text);
    void on_viderJournal_clicked();
    void on_voirJournalComplet_clicked();

private:
    Ui::MainWindow *ui;
    Candidat c;
    int currentCandidatId;
    bool isEditingCandidat;
    StatCandidat *m_statCandidat;
    JournalCandidat *m_journalCandidat;
    ImageVer_C *m_imageVerif;
    GroqManager* m_groqManager;
    veh_func* m_vehFunc;
    veh* m_veh;

    void initialiserInterface();
    void initialiserStatistiques();
    void initialiserJournal();
    void initialiserGestionImages();
    void connecterSignaux();
};

#endif

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui { class MainWindow; }
class GroqManager;  // Changed from GeminiManager

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_fermer_btn_clicked();
    void on_vehicule_btn_clicked();
    void on_candidat_btn_clicked();
    void on_seance_btn_clicked();
    void on_emp_btn_clicked();
    void on_moniteur_btn_clicked();
    void on_accueil_clicked();
    void on_vehicule_clicked();
    void on_candidat_clicked();
    void on_seance_clicked();
    void on_emp_clicked();
    void on_moniteur_clicked();
private:
    Ui::MainWindow *ui;
    GroqManager* m_groqManager;
};

#endif

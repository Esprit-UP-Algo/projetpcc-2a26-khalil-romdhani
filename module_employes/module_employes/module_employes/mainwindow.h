#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fermer_btn_clicked();
    void on_conf_ajout_clicked();
    void on_reinstaller_emp_clicked();  // ✅ nom corrigé

private:
    Ui::MainWindow *ui;
    QStandardItemModel *tab;
};

#endif // MAINWINDOW_H

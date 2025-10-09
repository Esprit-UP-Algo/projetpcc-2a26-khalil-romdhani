#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowC;
}
QT_END_NAMESPACE

class MainWindowC : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowC(QWidget *parent = nullptr);
    ~MainWindowC();

private:
    Ui::MainWindowC *ui;
};
#endif // MAINWINDOW_H

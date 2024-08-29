#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressDialog>
#include <QTimer>

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

private slots:
    void on_colorButton_clicked();
    void on_fileButton_clicked();
    void on_inputIntButton_clicked();

    void on_intputFloatButton_clicked();

    void on_itemsButton_clicked();

    void on_tipButton_clicked();

    void on_ProcessButton_clicked();
    void on_updateProgressDialog();
    void on_cancelProgressDialog();

    void on_guideButton_clicked();

private:
    Ui::MainWindow *ui;
    QProgressDialog *_progress;
    QTimer *_timer;
    int _counter;
    void StopProgressWithTimer();
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include <QDebug>
#include <QMdiSubWindow>
#include <QTextEdit>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actiondock_D_triggered()
{
    qDebug() << "show dock" << Qt::endl;
    ui->dockWidget->show();
}

void MainWindow::on_actionnew_file_N_triggered()
{
    auto text = new QTextEdit(this);
    auto childWindow = ui->mdiArea->addSubWindow(text);
    childWindow->setWindowTitle(tr("文本编辑子窗口"));
    childWindow->show();
}

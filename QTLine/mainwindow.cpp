#include "mainwindow.h"
#include <QRegExpValidator>
#include <QString>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString ip_mask = "000.000.000.000;";
    ui->ipLine->setInputMask(ip_mask);
    QString mac_mask = "HH:HH:HH:HH:HH:HH;";
    ui->macLine->setInputMask(mac_mask);
    ui->passwordLine->setEchoMode(QLineEdit::Password);

    QRegExp reg("[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+");
    auto validator = new QRegExpValidator(reg, ui->emailLine);
    ui->emailLine->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

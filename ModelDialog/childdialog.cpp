#include "childdialog.h"
#include <QDebug>
#include "ui_childdialog.h"
ChildDialog::ChildDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChildDialog)
{
    ui->setupUi(this);
}

ChildDialog::~ChildDialog()
{
    delete ui;
}

void ChildDialog::on_EnterMain_clicked()
{
    qDebug() << "accepted" << Qt::endl;
    accept();
}

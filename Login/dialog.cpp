#include "dialog.h"
#include "./ui_dialog.h"
#include "register.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::initsignals()
{
    _register = std::make_shared<Register>();
    _register->set_login(shared_from_this());
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
    _register->show();
}

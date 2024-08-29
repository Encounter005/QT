#include "maindialog.h"
#include "childdialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_EnterChild_clicked()
{
    // 并没有退出，只有所有界面都不显示了才回收
    close();
    ChildDialog childDialog;
    if (childDialog.exec() == QDialog::Accepted) {
        this->show();
    } else {
        return;
    }
}

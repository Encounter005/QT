#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "register.h"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE
class Register;
class Dialog : public QDialog, public std::enable_shared_from_this<Dialog>
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void initsignals();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    std::shared_ptr<Register> _register;
};
#endif // DIALOG_H

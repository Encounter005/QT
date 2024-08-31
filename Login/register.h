#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QPushButton>
#include <memory>

namespace Ui {
class Register;
}

class Dialog;
class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void set_login(const std::weak_ptr<Dialog> &login);
public slots:
    void ShowLogin();

private:
    Ui::Register *ui;
    std::weak_ptr<Dialog> _login;
    QPushButton *_reg_btn;
};

#endif // REGISTER_H

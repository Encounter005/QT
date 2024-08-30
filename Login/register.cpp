#include "register.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "ui_register.h"

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setMaximumSize(QSize(300, 350));
    this->setMinimumSize(QSize(300, 350));
    auto vbox_layout = new QVBoxLayout();

    auto verticalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vbox_layout->addItem(verticalSpacer1);
    QSpacerItem *name_item1 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    QLabel *name_label = new QLabel();
    name_label->setText("邮箱:");
    QLineEdit *name_edit = new QLineEdit();
    auto name_layout = new QHBoxLayout();
    name_layout->addItem(name_item1);
    name_layout->addWidget(name_label);
    name_layout->addWidget(name_edit);
    QSpacerItem *name_item2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    name_layout->addItem(name_item2);
    vbox_layout->addLayout(name_layout);

    QLabel *pwd_label = new QLabel();
    pwd_label->setText("密码:");
    QLineEdit *pwd_edit = new QLineEdit();

    auto verticalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Maximum);
    vbox_layout->addItem(verticalSpacer2);
    auto pwd_layout = new QHBoxLayout();

    QSpacerItem *pwd_item2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    QSpacerItem *pwd_item1 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    pwd_layout->addItem(pwd_item1);
    pwd_layout->addWidget(pwd_label);
    pwd_layout->addWidget(pwd_edit);
    pwd_layout->addItem(pwd_item2);
    vbox_layout->addLayout(pwd_layout);

    auto verticalSpacer3 = new QSpacerItem(40, 30, QSizePolicy::Fixed, QSizePolicy::Maximum);
    vbox_layout->addItem(verticalSpacer3);

    QSpacerItem *reg_btn_item1 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    _reg_btn = new QPushButton();
    _reg_btn->setText("注册");
    auto regbtn_layout = new QHBoxLayout();
    regbtn_layout->addItem(reg_btn_item1);
    regbtn_layout->addWidget(_reg_btn, 5);
    QSpacerItem *reg_btn_item2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    regbtn_layout->addItem(reg_btn_item2);
    vbox_layout->addLayout(regbtn_layout);

    auto verticalSpacer4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Expanding);
    vbox_layout->addItem(verticalSpacer4);
    this->setLayout(vbox_layout);
}

Register::~Register()
{
    delete ui;
}

void Register::set_login(const std::weak_ptr<Dialog> &login)
{
    _login = login;
}

void Register::ShowLogin() {}

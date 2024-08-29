#include "mainwindow.h"
#include <QButtonGroup>
#include <QColorDialog>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QInputDialog>
#include <QLabel>
#include <QMessageBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QWizard>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _counter(0)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_colorButton_clicked()
{
    QColorDialog colorDialog(Qt::blue, this);
    colorDialog.setOption(QColorDialog::ShowAlphaChannel);
    colorDialog.exec();
    QColor color = colorDialog.currentColor();
    qDebug() << " color is " << color;
}

void MainWindow::on_fileButton_clicked()
{
    QString path = QDir::currentPath();
    QString title = tr("文件对话框");
    QString filter = tr("文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*) ");
    QString aFileName = QFileDialog::getOpenFileName(this, title, path, filter);
    qDebug() << "The selected path is " << aFileName << Qt::endl;
}

void MainWindow::on_inputIntButton_clicked()
{
    bool isint = false;
    auto intdata = QInputDialog::getInt(this,
                                        tr("输入数字对话框"),
                                        tr("请输入提示"),
                                        200,
                                        -200,
                                        400,
                                        10,
                                        &isint);
    if (isint) {
        qDebug() << intdata << Qt::endl;
    }
}

void MainWindow::on_intputFloatButton_clicked()
{
    bool ok = false;
    auto floatdata = QInputDialog::getDouble(this,
                                             tr("输入浮点数对话框"),
                                             tr("请输入提示"),
                                             100.5,
                                             -100.0,
                                             300.0,
                                             1.0,
                                             &ok);
    if (ok) {
        qDebug() << floatdata << Qt::endl;
    }
}

void MainWindow::on_itemsButton_clicked()
{
    QStringList items;
    items << tr("条目一") << tr("条目二");
    bool ok = false;
    auto itemData = QInputDialog::getItem(this,
                                          tr("条目输入对话框"),
                                          tr("输入或选择条目"),
                                          items,
                                          0,
                                          true,
                                          &ok);
    if (ok) {
        qDebug() << "item is " << itemData << Qt::endl;
    }
}

void MainWindow::on_tipButton_clicked()
{
    auto ret = QMessageBox::question(this, tr("问题标题"), tr("你是单身吗"));
    if (ret == QMessageBox::Yes) {
        qDebug() << "ret is " << ret << Qt::endl;
    } else {
        return;
    }

    auto ret2 = QMessageBox::information(this, tr("通知对话框"), tr("你好单身狗"), QMessageBox::Yes);
    if (ret2 == QMessageBox::Yes) {
        qDebug() << "ret2 is " << ret2 << Qt::endl;
    } else {
        return;
    }

    auto ret3 = QMessageBox::warning(this,
                                     tr("警告对话框"),
                                     tr("你最好在这个地方发泄一下"),
                                     QMessageBox::Yes);
    if (ret3 == QMessageBox::Yes) {
        qDebug() << "ret3 is " << ret3 << Qt::endl;
    } else {
        return;
    }

    auto ret4 = QMessageBox::critical(this,
                                      tr("关键提示对话框"),
                                      tr("我梦寐以求，是love and peace"),
                                      QMessageBox::Yes);
    if (ret4 == QMessageBox::Yes) {
        qDebug() << "ret4 is " << ret4 << Qt::endl;
    } else {
        return;
    }
}

void MainWindow::on_ProcessButton_clicked()
{
    _progress = new QProgressDialog(tr("正在复制"), tr("取消复制"), 0, 5000, this);
    _progress->setWindowTitle("文件复制进度对话框");
    _progress->setWindowModality(Qt::ApplicationModal);
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &MainWindow::on_updateProgressDialog);
    connect(_progress, &QProgressDialog::canceled, this, &MainWindow::on_cancelProgressDialog);
    _timer->start(2);
}

void MainWindow::on_updateProgressDialog()
{
    _counter++;
    if (_counter > 5000) {
        StopProgressWithTimer();
        return;
    }

    _progress->setValue(_counter);
}

void MainWindow::on_cancelProgressDialog()
{
    StopProgressWithTimer();
}

void MainWindow::StopProgressWithTimer()
{
    _timer->stop();
    delete _timer;
    _timer = nullptr;
    delete _progress;
    _progress = nullptr;
    _counter = 0;
}

void MainWindow::on_guideButton_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle("Genshin");
    auto page1 = std::make_unique<QWizardPage>();
    page1->setTitle(tr("引导程序"));
    auto label1 = std::make_unique<QLabel>();
    label1->setText(tr("i will support you!"));
    auto layout = std::make_unique<QVBoxLayout>();
    layout->addWidget(label1.get());
    page1->setLayout(layout.get());
    wizard.addPage(page1.get());

    auto page2 = std::make_unique<QWizardPage>();
    page2->setTitle(tr("选择一种类型"));
    auto group = std::make_unique<QButtonGroup>(page2.get());
    auto radioButton = std::make_unique<QRadioButton>();
    radioButton->setText("MiKu");
    auto radioButton1 = std::make_unique<QRadioButton>();
    radioButton1->setText("GenShin");
    auto radioButton2 = std::make_unique<QRadioButton>();
    radioButton2->setText("Monika");
    auto radioButton3 = std::make_unique<QRadioButton>();
    radioButton3->setText("nino");
    group->addButton(radioButton.get());
    group->addButton(radioButton1.get());
    group->addButton(radioButton2.get());
    group->addButton(radioButton3.get());

    auto layout2 = std::make_unique<QVBoxLayout>();
    for (int i = 0; i < group->buttons().size(); i++) {
        layout2->addWidget(group->buttons()[i]);
    }

    page2->setLayout(layout2.get());
    wizard.addPage(page2.get());

    auto page3 = std::make_unique<QWizardPage>();
    auto label3 = std::make_unique<QLabel>();
    label3->setText(tr("Thank you for engaging"));
    auto layout3 = std::make_unique<QVBoxLayout>();
    layout3->addWidget(label3.get());
    page3->setLayout(layout3.get());
    wizard.addPage(page3.get());

    wizard.show();
    wizard.exec();
}

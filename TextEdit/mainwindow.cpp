#include "mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QTextCursor>
#include <QTextDocument>
#include <QTextFrame>
#include <QTextFrameFormat>
#include <QTextImageFormat>
#include <QTextListFormat>
#include <QTextTableFormat>
#include <QVBoxLayout>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto doc = ui->textEdit->document();
    auto root_frame = doc->rootFrame();
    QTextFrameFormat format;
    format.setBorderBrush(Qt::blue);
    format.setBorder(3);
    root_frame->setFrameFormat(format);
    ui->textEdit->insertPlainText("hello world!\n");
    ui->textEdit->insertPlainText("Hello Qt\n");

    QTextFrameFormat format2;
    format2.setBorderBrush(Qt::gray);
    format2.setMargin(10);
    format2.setPadding(5);
    format2.setBorder(2);
    format2.setBorderStyle(QTextFrameFormat::BorderStyle_Dashed);
    auto cursor = ui->textEdit->textCursor();
    cursor.insertFrame(format2);
    ui->textEdit->insertPlainText("inner text!\n");
    ui->textEdit->insertPlainText("hello QT!\n");

    auto action_frame = new QAction("Frame", this);
    connect(action_frame, &QAction::triggered, this, &MainWindow::showTextFrame);
    ui->toolBar->addAction(action_frame);

    auto action_frame2 = new QAction("文本块", this);
    connect(action_frame2, &QAction::triggered, this, &MainWindow::showTextBlock);
    ui->toolBar->addAction(action_frame2);

    auto action_font = new QAction("字体", this);
    action_font->setCheckable(true);
    connect(action_font, &QAction::triggered, this, &MainWindow::setTextFont);
    ui->toolBar->addAction(action_font);

    auto action_textTable = new QAction(tr("表格"), this);
    auto action_textList = new QAction(tr("列表"), this);
    auto action_textImage = new QAction(tr("图片"), this);
    connect(action_textTable, &QAction::triggered, this, &MainWindow::insertTable);
    ui->toolBar->addAction(action_textTable);
    connect(action_textList, &QAction::triggered, this, &MainWindow::insertList);
    ui->toolBar->addAction(action_textList);
    connect(action_textImage, &QAction::triggered, this, &MainWindow::insertImage);
    ui->toolBar->addAction(action_textImage);

    auto action_textFind = new QAction(tr("查找"), this);
    connect(action_textFind, &QAction::triggered, this, &MainWindow::textFind);
    ui->toolBar->addAction(action_textFind);
    findDialog = new QDialog(this);
    lineEdit = new QLineEdit(findDialog);
    auto button = new QPushButton(findDialog);
    button->setText(tr("查找下一个"));
    connect(button, &QPushButton::clicked, this, &MainWindow::findNext);
    auto layout = new QVBoxLayout();
    layout->addWidget(lineEdit);
    layout->addWidget(button);
    findDialog->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTextFrame()
{
    auto doc = ui->textEdit->document();
    auto rootFrame = doc->rootFrame();
    for (auto iter = rootFrame->begin(); iter != rootFrame->end(); ++iter) {
        auto cur_frame = iter.currentFrame();
        auto cur_block = iter.currentBlock();
        if (cur_frame) {
            qDebug() << "cur node is frame";
        } else if (cur_block.isVisible()) {
            qDebug() << "cur node is text block, text is " << cur_block.text();
        }
    }
}

void MainWindow::showTextBlock()
{
    auto doc = ui->textEdit->document();
    auto block = doc->firstBlock();
    for (int i = 0; i < doc->blockCount(); i++) {
        qDebug() << tr("文本块: %1, 文本块首行行号: %2, 长度: %3, 内容: %4")
                        .arg(i)
                        .arg(block.firstLineNumber())
                        .arg(block.length())
                        .arg(block.text());
        block = block.next();
    }
}

void MainWindow::setTextFont(bool checked)
{
    if (checked) {
        auto cursor = ui->textEdit->textCursor();
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(blockFormat);
        QTextCharFormat charFormat;
        charFormat.setBackground(Qt::lightGray);
        charFormat.setForeground(Qt::blue);
        charFormat.setFont(QFont(tr("FreeSans"), 12, QFont::Bold, false));
        charFormat.setFontUnderline(true);
        cursor.setCharFormat(charFormat);
        cursor.insertText("插入字体");
    } else {
        auto cursor = ui->textEdit->textCursor();
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignLeft);
        cursor.insertBlock(blockFormat);
        QTextCharFormat charFormat;
        charFormat.setBackground(Qt::black);
        charFormat.setForeground(Qt::white);
        charFormat.setFont(QFont(tr("思源宋体 CN"), 12, QFont::Normal, true));
        cursor.setCharFormat(charFormat);
        cursor.insertText("思源宋体");
    }
}

void MainWindow::insertTable()
{
    auto cursor = ui->textEdit->textCursor();
    QTextTableFormat tableFormat;
    tableFormat.setCellSpacing(2);
    tableFormat.setCellPadding(10);
    cursor.insertTable(2, 2, tableFormat);
}
void MainWindow::insertList()
{
    auto cursor = ui->textEdit->textCursor();
    QTextListFormat listFormat;
    listFormat.setStyle(QTextListFormat::ListDecimal);
    cursor.insertList(listFormat);
}
void MainWindow::insertImage()
{
    auto cursor = ui->textEdit->textCursor();
    QTextImageFormat imageFormat;
    imageFormat.setName("://head.jpg");
    cursor.insertImage(imageFormat);
}
void MainWindow::textFind()
{
    findDialog->show();
}

void MainWindow::findNext()
{
    QString string = lineEdit->text();
    bool isFind = ui->textEdit->find(string, QTextDocument::FindBackward);
    if (isFind) {
        qDebug() << tr("行号:%1, 列号:%2")
                        .arg(ui->textEdit->textCursor().blockNumber())
                        .arg(ui->textEdit->textCursor().columnNumber());
    }
}

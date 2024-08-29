#include "childdialog.h"
#include "maindialog.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDialog w;
    ChildDialog child;
    auto res = child.exec();
    if (res == QDialog::Accepted) {
        qDebug() << "child.exec() returned, res is: " << res << Qt::endl;
        w.show();
        a.exec();
    } else {
        qDebug() << "child.exec() exit, res is: " << res << Qt::endl;
        return 0;
    }
}

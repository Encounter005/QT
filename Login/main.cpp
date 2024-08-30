#include <QApplication>
#include "dialog.h"
#include "register.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<Dialog> w = std::make_shared<Dialog>();
    w->initsignals();
    w->show();
    return a.exec();
}

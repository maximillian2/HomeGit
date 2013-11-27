#include <QtGui>
#include <QtSql>
#include <QTextCodec>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);

    MainWindow *m = new MainWindow;

    m->show();
    return a.exec();
}

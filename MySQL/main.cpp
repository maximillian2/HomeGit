#include <QtGui>
#include <QtSql>
#include <QTextCodec>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);

    QApplication a(argc, argv);

    MainWindow *m = new MainWindow;

    m->show();
    return a.exec();
}

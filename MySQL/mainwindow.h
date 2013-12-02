#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void refresh(const QString);
    void make_inactive(QPushButton *);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

    void on_table_comboBox_textChanged(const QString &arg1);

    void on_table_comboBox_activated(const QString &arg1);

private:
    QSqlQueryModel *model;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

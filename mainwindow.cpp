// main window form
#include "mainwindow.h"
#include "ui_mainwindow.h"

// syslibs
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("Livers");
    db.setUserName("root");
    db.setPassword("123");

    if (!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),
        db.lastError().text());
    }

    // table combobox
    QSqlQuery tables_query;
    tables_query.exec("SHOW TABLES FROM Livers;");

    QStringList table_list;
    while(tables_query.next())
    {
        table_list << tables_query.value(0).toString();
    }
    ui->table_comboBox->addItems(table_list);

    // column combobox
    QSqlQuery columns_combobox_query;
    columns_combobox_query.exec("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_SCHEMA = 'Livers' AND TABLE_NAME = 'Education_place';");

    QStringList column_list;
    while(columns_combobox_query.next())
    {
        column_list << columns_combobox_query.value(0).toString();
    }
    ui->column_comboBox->addItems(column_list);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// button "Street"
void MainWindow::on_pushButton_clicked()
{
    make_inactive(ui->pushButton);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);


    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Street");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

// button "Family"
void MainWindow::on_pushButton_2_clicked()
{

    make_inactive(ui->pushButton_2);
    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);

    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Family");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

// button "Workplace"
void MainWindow::on_pushButton_3_clicked()
{

    make_inactive(ui->pushButton_3);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);


    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Workplace");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

// button "Livers"
void MainWindow::on_pushButton_4_clicked()
{
    ///////
    make_inactive(ui->pushButton_4);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ///////

    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Livers");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

// button "Education_place"
void MainWindow::on_pushButton_5_clicked()
{

    make_inactive(ui->pushButton_5);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton->setEnabled(true);

    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Education_place");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

// refresh column combobox
void MainWindow::refresh(const QString arg1)
{
    ui->column_comboBox->clear();
    QString str;
    str += "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_SCHEMA = 'Livers' AND TABLE_NAME = '" + arg1 + "';";

    QSqlQuery query;
    query.exec(str);

    QStringList list;
    while(query.next())
        list << query.value(0).toString();
    ui->column_comboBox->addItems(list);
}

// signal :P
void MainWindow::on_table_comboBox_activated(const QString &arg1)
{
    refresh(arg1);
}

// button "Find"
void MainWindow::on_pushButton_6_clicked()
{
    QString find_string;
    if(ui->lineEdit->text() == NULL)
        find_string = "SELECT " + ui->column_comboBox->currentText() + " FROM " + ui->table_comboBox->currentText() + ";";
    else
        find_string = "SELECT * FROM " + ui->table_comboBox->currentText() + " WHERE " + ui->column_comboBox->currentText() + " = \"" + ui->lineEdit->text() + "\";";

    /////////////////////////////////
    qWarning(find_string.toLatin1());
    /////////////////////////////////

    model = new QSqlQueryModel;
    model->setQuery(find_string);

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

void MainWindow::make_inactive(QPushButton *button)
{
    button->setEnabled(false);
}

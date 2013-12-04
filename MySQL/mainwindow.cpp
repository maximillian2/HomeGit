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

    // hide widgets until column is int
    ui->find_number_comboBox->hide();

    ui->find_number_comboBox->addItem(">");
    ui->find_number_comboBox->addItem(">=");
    ui->find_number_comboBox->addItem("<");
    ui->find_number_comboBox->addItem("<=");
    ui->find_number_comboBox->addItem("=");
    ui->find_number_comboBox->setCurrentIndex(ui->find_number_comboBox->findText("="));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// button "Street"
void MainWindow::on_pushButton_clicked()
{
    make_inactive(ui->pushButton);

    model = new QSqlRelationalTableModel;
    model->setTable("Street");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

// button "Family"
void MainWindow::on_pushButton_2_clicked()
{
    make_inactive(ui->pushButton_2);

    model = new QSqlRelationalTableModel;
    model->setTable("Family");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

// button "Workplace"
void MainWindow::on_pushButton_3_clicked()
{
    make_inactive(ui->pushButton_3);

    model = new QSqlRelationalTableModel;
    model->setTable("Workplace");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

// button "Livers"
void MainWindow::on_pushButton_4_clicked()
{
    make_inactive(ui->pushButton_4);

    model = new QSqlRelationalTableModel;
    model->setTable("Livers");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

// button "Education_place"
void MainWindow::on_pushButton_5_clicked()
{
    make_inactive(ui->pushButton_5);

    model = new QSqlRelationalTableModel;
    model->setTable("Education_place");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

// refresh column combobox
void MainWindow::refresh(const QString arg1)
{
    ui->column_comboBox->clear();
    QString str;
    str = "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_SCHEMA = 'Livers' AND TABLE_NAME = '" + arg1 + "';";

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
    model = new QSqlRelationalTableModel;
    QString find_string;

    model->setTable(ui->table_comboBox->currentText());

    if(ui->checkBox->isChecked())   // is checked
    {
        find_string.clear();
        find_string = ui->column_comboBox->currentText() + " LIKE \"" + ui->lineEdit->text() + "%\";";
        model->setFilter(find_string);
    }
    else                            // isn't checked
    {
        find_string.clear();
        find_string = ui->column_comboBox->currentText() + " = " + ui->lineEdit->text() + ";";
        model->setFilter(find_string);
    }

    if(ui->find_number_comboBox->isVisible())
    {
        find_string.clear();
        find_string = ui->column_comboBox->currentText() + " " + ui->find_number_comboBox->currentText() + " " + ui->lineEdit->text() + ";";
        model->setFilter(find_string);
    }

    qWarning(find_string.toLatin1());

    model->select();

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();       //fit into column field
    ui->tableView->show();
}

void MainWindow::make_inactive(QPushButton *button)
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    button->setEnabled(false);
}

void MainWindow::on_column_comboBox_currentIndexChanged(const QString &arg1)
{
    QString query_string;
    query_string = "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_SCHEMA = 'Livers' AND TABLE_NAME = '" + ui->table_comboBox->currentText() + "' AND COLUMN_NAME = '" + arg1 + "' and DATA_TYPE = 'int';";

    qWarning(query_string.toLatin1());

    QSqlQuery *query = new QSqlQuery;
    query->exec(query_string);

    // have result, show fields
    if(query->size())
    {
        ui->find_number_comboBox->show();
        ui->checkBox->setDisabled(true);
    }
    // no - hide if not hidden
    else
    {
        ui->checkBox->setDisabled(false);
        ui->find_number_comboBox->hide();
    }
}



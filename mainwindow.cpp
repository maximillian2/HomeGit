// main window form
#include "mainwindow.h"
#include "ui_mainwindow.h"

// syslibs
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

// button "Street"
void MainWindow::on_pushButton_clicked()
{
    model = new QSqlQueryModel;
    model->setQuery("SELECT name, marking FROM Street");
    model->setHeaderData(0, Qt::Horizontal, tr("Ім'я"));
    model->setHeaderData(1, Qt::Horizontal, tr("Позначення"));

    ui->tableView->setModel(model);
    //fit into column field
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

// button "Family"
void MainWindow::on_pushButton_2_clicked()
{
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Family");
    model->setHeaderData(0, Qt::Horizontal, tr("Код"));
    model->setHeaderData(1, Qt::Horizontal, tr("Код"));
    model->setHeaderData(2, Qt::Horizontal, tr("Родинний зв'язок"));

    ui->tableView->setModel(model);
    //fit into column field
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

// button "Workplace"
void MainWindow::on_pushButton_3_clicked()
{
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Workplace");
    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("livers_id"));
    model->setHeaderData(2, Qt::Horizontal, tr("Організація"));
    model->setHeaderData(3, Qt::Horizontal, tr("Тип"));
    model->setHeaderData(4, Qt::Horizontal, tr("Місцезнаходження"));
    model->setHeaderData(5, Qt::Horizontal, tr("Рік прийому"));
    model->setHeaderData(6, Qt::Horizontal, tr("Рік звільнення"));
    model->setHeaderData(7, Qt::Horizontal, tr("Заробітня платня"));

    ui->tableView->setModel(model);
    //fit into column field
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

// button "Livers"
void MainWindow::on_pushButton_4_clicked()
{
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Livers");

    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Дата народження"));
    model->setHeaderData(2, Qt::Horizontal, tr("Вулиця"));
    model->setHeaderData(3, Qt::Horizontal, tr("Будинок"));
    model->setHeaderData(4, Qt::Horizontal, tr("Квартира"));
    model->setHeaderData(5, Qt::Horizontal, tr("Ім'я"));
    model->setHeaderData(6, Qt::Horizontal, tr("По-батькові"));
    model->setHeaderData(7, Qt::Horizontal, tr("Прізвище"));
    model->setHeaderData(8, Qt::Horizontal, tr("Сімейний стан"));
    model->setHeaderData(9, Qt::Horizontal, tr("Соціальний стан"));
    model->setHeaderData(10, Qt::Horizontal, tr("Дата реєстрації"));


    ui->tableView->setModel(model);
    //fit into column field
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

// button "Education_place"
void MainWindow::on_pushButton_5_clicked()
{
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Education_place");

    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("livers_id"));
    model->setHeaderData(2, Qt::Horizontal, tr("Назва установи"));
    model->setHeaderData(3, Qt::Horizontal, tr("Місцезнаходження"));
    model->setHeaderData(4, Qt::Horizontal, tr("Рік вступу"));
    model->setHeaderData(5, Qt::Horizontal, tr("Рік закінчення"));
    model->setHeaderData(6, Qt::Horizontal, tr("Вид установи"));

    ui->tableView->setModel(model);
    //fit into column field
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();

}

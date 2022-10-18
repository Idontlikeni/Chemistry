#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1030,550);
    this->table = Mtable();
    this->currentElement = ChElement();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked()
{
    QString name = ui->nameEdit->text();
    QString number = ui->numberEdit->text();
    QString group = ui->groupEdit->text();
    QString period = ui->periodEdit->text();
    if(number != ""){
        currentElement = this->table.elements[number.toInt()];
    }else if(name != ""){
        for (int i = 1; i < 110; i++) {
            if(name.toLower() == this->table.elements[i].get_name().toLower()){
                currentElement = this->table.elements[i];
            }
        }
    }else if(group != "" && period != ""){
        for (int i = 1; i < 110; i++) {
            if(this->table.elements[i].get_position().x == period.toInt() && this->table.elements[i].get_position().y == group.toInt()){
                currentElement = this->table.elements[i];
            }
        }
    }

    ui->nameEdit->setText(currentElement.get_name());
    ui->numberEdit->setText(QString::number(currentElement.get_number()));
    ui->groupEdit->setText(QString::number(currentElement.get_position().y));
    ui->periodEdit->setText(QString::number(currentElement.get_position().x));

    ui->outputLabel->setText(currentElement.calculate_conf());
    qDebug() << currentElement.get_name() << currentElement.get_position().x << currentElement.get_position().y << currentElement.get_number() << currentElement.calculate_conf();
}

void MainWindow::on_pushButton_clicked()
{
    ui->nameEdit->setText("");
    ui->numberEdit->setText("");
    ui->groupEdit->setText("");
    ui->periodEdit->setText("");
}

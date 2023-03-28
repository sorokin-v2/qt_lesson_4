#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rb_topRadioButton->setText("Наименование верхней радиокнопки");
    ui->rb_bottomRadioButton->setText("Наименование нижней радиокнопки");
    ui->rb_topRadioButton->setChecked(true);

    for(int i = 0; i < 10; ++i){
        ui->cb_comboBox->addItem("Элемент " + QString::number(i));
    }

    ui->pbtn_pushButton->setText("Измененное наименование кнопки");
    ui->pbtn_pushButton->setCheckable(true);

    ui->pg_progressBar->setMinimum(0);
    ui->pg_progressBar->setMaximum(100);
    ui->pg_progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbtn_pushButton_clicked()
{
    int newValue = ui->pg_progressBar->value() + int((ui->pg_progressBar->maximum() - ui->pg_progressBar->minimum()) / 10);
    if(newValue <= 100){
        ui->pg_progressBar->setValue(newValue);
    }
    else{
        ui->pg_progressBar->setValue(0);
    }
}


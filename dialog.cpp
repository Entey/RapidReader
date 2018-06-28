#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{

}

void Dialog::on_pushButton_3_clicked()
{

}

void Dialog::on_pushButton_4_clicked()
{

}

void Dialog::on_pushButton_5_clicked()
{

}

void Dialog::on_pushButton_6_clicked()
{

}

void Dialog::on_pushButton_clicked()
{

}

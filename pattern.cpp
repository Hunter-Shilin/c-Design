#include "pattern.h"
#include "ui_pattern.h"
#include <QPainter>
Pattern::Pattern(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pattern)
{
    ui->setupUi(this);
    QPainter p;
    p.drawPixmap(rect(), QPixmap(":/new/prefix1/image2/timg.jpg"));
}

Pattern::~Pattern()
{
    delete ui;
}

void Pattern::on_pushButton_clicked()//人人
{
    choice = 1;
    emit mySignal2();
}

void Pattern::on_pushButton_2_clicked()//人机
{
    choice = 2;
    emit mySignal2();
}


void Pattern::on_pushButton_3_clicked()//机机
{
    choice = 3;
    emit mySignal2();
}

int Pattern::getChoice() {
    return choice;
}

void Pattern::on_pushButton_4_clicked()
{
    emit mySignal3();
}

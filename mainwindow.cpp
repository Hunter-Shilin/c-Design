#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->resize(800, 500);
    //this->setWindowTitle("六子棋");
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    ui->setupUi(this);

    //处理子窗口的信号
    //ChessBoard->main
    connect(&c, &ChessBoard::mySignal1,
            [=]() {
                c.hide();
                this->show();
            }

            );
    //pattern->chessboard
    connect(&ptn, &Pattern::mySignal2,
            [=]() {
                int tmp = ptn.getChoice();
                c.setSchema(tmp);
                ptn.hide();
                c.show();
            }

            );
    connect(&ptn, &Pattern::mySignal3,
            [=]() {
                ptn.hide();
                this->show();
            }

            );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//开始游戏进入pattern
{
    ptn.show();
    this->hide();
}


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        //
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons() & Qt::LeftButton) {
        move(e->globalPos() - p);
    }
}

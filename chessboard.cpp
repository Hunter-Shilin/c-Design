#include "chessboard.h"
#include "ui_chessboard.h"
#include <QPainter>
#include <QDebug>
#include <QPen>
#include <QMouseEvent>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QDialog>
#include <QVector>
#define cout qDebug()
ChessBoard::ChessBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChessBoard)
{
    chessX = -1;
    chessY = -1;
    cas = 0;
    memset(IsEmpty, 0, sizeof(IsEmpty));
    ui->setupUi(this);
    this->resize(1500, 900);
    this->setWindowTitle("对弈中");
}

ChessBoard::~ChessBoard()
{
    delete ui;
}

void ChessBoard::paintEvent(QPaintEvent *) {
    QPainter p(this);

    p.drawPixmap(rect(), QPixmap(":/new/prefix1/image2/chessboard_bg.png"));
    startX = width()/20;
    startY = height()/40;
    gridW = width()*4/125;
    gridH = height()*9/200;
    startY += 20;
    //drawline
    QPen pen;
    pen.setWidth(4);//线宽
    p.setPen(pen);
    //cout << width() << " " << height();
    for(int i = 0; i <= 20; i++) {
        //horizontal
        p.drawLine(startX, startY + i*gridH, startX + 20*gridW, startY + i*gridH);
        //upright
        p.drawLine(startX + i*gridW, startY, startX + i*gridW, startY + 20*gridH);

        //cout << i << " " << " " << j;
    }

    //画棋子
//    if(chessX != -1 && chessY != -1) {
//        cout << cas;
//        if(cas%2 == 1){//黑棋
//            p.drawPixmap(startX + chessX*gridW - gridW/2, startY + chessY*gridH - gridH/2, gridW, gridH,
//                         QPixmap(":/new/prefix1/image2/black.png"));
//        }
//        else{//白旗
//            p.drawPixmap(startX + chessX*gridW - gridW/2, startY + chessY*gridH - gridH/2, gridW, gridH,
//                         QPixmap(":/new/prefix1/image2/white.png"));
//        }
//    }
    for(int i = 0; i < v.size(); i++) {
        if(v[i].kind%2 == 1) {
            p.drawPixmap(startX + v[i].x*gridW - gridW/2, startY + v[i].y*gridH - gridH/2, gridW, gridH,
                         QPixmap(":/new/prefix1/image2/black.png"));
        }
        else {
            p.drawPixmap(startX + v[i].x*gridW - gridW/2, startY + v[i].y*gridH - gridH/2, gridW, gridH,
                         QPixmap(":/new/prefix1/image2/white.png"));
        }
    }
//    if(IsWin(v[v.size()-1]) == true) {
//        //End(v[v.size()-1].kind);
//    }
}


bool ChessBoard::IsWin(node t) {//当前下的棋子判断是否有赢家产生
    int sum = 0;
    int flag = t.kind%2;//1->black   0->white
    int x = t.x, y = t.y;
    //水平
    for(int i = x; i <= 20; i++) {
        if(IsEmpty[i][y]%2 == flag) {
            sum++;
        }
        else break;
    }
    for(int i = x-1; i>=0; i--) {
        if(IsEmpty[i][y]%2 == flag) {
            sum++;
        }
        else break;
    }
    if(sum>=6) {
        cout<<"YES";
        return true;
    }
    //垂直
    sum=0;
    for(int i = y; i<=20; i++) {
        if(IsEmpty[x][i]%2 == flag) {
            sum++;
        }
        else break;
    }
    for(int i = y-1; i>=0; i--) {
        if(IsEmpty[x][i]%2 == flag) {
            sum++;
        }
        else break;
    }
    if(sum>=6) {
        cout<<"YES";
        return true;
    }
    sum = 0;


    return false;
}

void ChessBoard::End(int flag) {
    if(flag%2 == 1) {
        QMessageBox::about(this, "Game Over", "游戏结束，黑棋胜");
    }
    else {
        QMessageBox::about(this, "Game Over", "游戏结束，白棋胜");
    }
    v.clear();
    cas = 0;
    emit mySignal1();
}


void ChessBoard::Illegal() {//下棋操作非法

    QMessageBox::about(this, "Tips", "此下棋操作有误，请重新选落棋点");
}


void ChessBoard::on_pushButton_2_clicked() {
    v.clear();
    cas = 0;
    emit mySignal1();
}

void ChessBoard::mousePressEvent(QMouseEvent *e) {

    int x = e->x();
    int y = e->y();
//    cout<<startX+20*gridW<<" "<<startY+20*gridH;
//    cout<<startY;
//    cout << x << " " << y;
    if(x >= startX-gridW/2 && x <= startX+20*gridW+gridW/2
            && y >= startY && y <= startY+20*gridH+gridH/2) {
//        cout << x << " " << y;
        chessX = (x - startX + gridW/2)/gridW;
        chessY = (y - startY + gridH/2)/gridH;
        cout<<chessX<<" "<<chessY;
        if(false != IsEmpty[chessX][chessY]) {
            Illegal();
        }
        else {
            cas++;
            IsEmpty[chessX][chessY] = cas;
            node tmp;
            tmp.x = chessX;
            tmp.y = chessY;
            tmp.kind = cas;
            v.push_back(tmp);
            update();
        }
    }
    else {//未在棋盘内下棋
        Illegal();
    }
}

void ChessBoard::on_pushButton_clicked() {
    //vector<node>::iterator it;
    if(false == v.size()) return ;
    auto it = v.end()-1;
    v.erase(it);
    update();
}

void ChessBoard::setSchema(int tmp) {
    schema = tmp;
}

void ChessBoard::on_pushButton_3_clicked() {//和棋
    QMessageBox::about(this, "和棋", "双方和棋");
    v.clear();
    cas = 0;
    emit mySignal1();
}

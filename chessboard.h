#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include <QVector>

namespace Ui {
class ChessBoard;
}

struct node
{
    int x, y, kind;
};
class ChessBoard : public QWidget
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);

public:
    explicit ChessBoard(QWidget *parent = 0);
    ~ChessBoard();
    void Illegal();//下棋操作是否合法
    bool IsWin(node);//是否产生赢家
    bool IsDeadGame();//是否和棋
    void End(int);//产生赢家，结束本轮游戏
    void setSchema(int);//设定模式

signals:
    void mySignal1();//回到主界面

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ChessBoard *ui;
    int cas;//下棋的次数 黑棋先若cas%2==1下黑棋，反之下白棋
    int gridW;//网格宽度
    int gridH;//网格高度
    int startX;//开始下标
    int startY;//结束下标
    int chessX, chessY;
    int IsEmpty[25][25];//0代表空
    int schema;
    QVector<node> v;
};

#endif // CHESSBOARD_H

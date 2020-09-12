#ifndef PATTERN_H
#define PATTERN_H

#include <QWidget>

namespace Ui {
class Pattern;
}

class Pattern : public QWidget
{
    Q_OBJECT

public:
    explicit Pattern(QWidget *parent = 0);
    ~Pattern();
    int getChoice();

signals:
    void mySignal2();//pattern->chessboard
    void mySignal3();//pattern->main

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Pattern *ui;
    int choice;
};

#endif // PATTERN_H

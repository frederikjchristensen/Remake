#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QTime>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_verticalSlider_valueChanged(int value);

private:
    Ui::Dialog *ui;
    QTime timer1;
    QTime timer2;
    QTime timer3;
    QTime timer4;
    bool tswitch;
    bool treset;
};

#endif // DIALOG_H

#include "dialog.h"
#include "ui_dialog.h"
#include "serialportreader.h"

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

void Dialog::on_verticalSlider_valueChanged(int value)
{
    ui->speedbar->setValue(value);
    if(value < 100 && value >75){
        ui->label->setText(QString("<span style=\" font-size:24pt; color:#00ff00;\">Question 1</span>"));
        ui->label_2->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 2</span>"));
        ui->label_3->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 3</span>"));
        ui->label_4->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 4</span>"));
        timer1.restart();
        timer2.restart();
        timer3.restart();
        timer4.restart();
    }
    else if(value < 75 && value >= 50){
        if(tswitch == false){
            timer3.start();
            tswitch = true;
        }
        else if(tswitch == true){
            ui->bar_2->setValue(timer2.elapsed());
                if(tswitch == true && timer2.elapsed()> 3000){
                        ui->bar_2->setValue(3000);
                        ui->label->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 1</span>"));
                        ui->label_2->setText(QString("<span style=\" font-size:24pt; color:#00ff00;\">Question 2</span>"));
                        ui->label_3->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 3</span>"));
                        ui->label_4->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 4</span>"));
                        qDebug("Answer 2 Chosen");
                        //tswitch = false;
    }
        }
    }
    else if(value < 49 && value > 25){
        if(tswitch == false){
            timer3.start();
            tswitch = true;
        }
        else if(tswitch == true){
            ui->bar_3->setValue(timer3.elapsed());
                if(timer3.elapsed()> 3000){
                        ui->bar_3->setValue(3000);
                        ui->label->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 1</span>"));
                        ui->label_2->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 2</span>"));
                        ui->label_3->setText(QString("<span style=\" font-size:24pt; color:#00ff00;\">Question 3</span>"));
                        ui->label_4->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 4</span>"));
                        qDebug("Answer 3 Chosen");
                        //tswitch = false;
    }
        }
                }
    else if(value < 25 && value > 1){
        if(tswitch == false){
            timer4.start();
            tswitch = true;
        }
        else if(tswitch == true){
            ui->bar_4->setValue(timer4.elapsed());
                if(tswitch == true && timer4.elapsed()> 3000){
                        ui->bar_4->setValue(3000);
                        ui->label->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 1</span>"));
                        ui->label_2->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 2</span>"));
                        ui->label_3->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 3</span>"));
                        ui->label_4->setText(QString("<span style=\" font-size:24pt; color:#00ff00;\">Question 4</span>"));
                        qDebug("Answer 4 Chosen");
                        //tswitch = false;
            }

        }
                }
    else{
        ui->label->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 1</span>"));
        ui->label_2->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 2</span>"));
        ui->label_3->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 3</span>"));
        ui->label_4->setText(QString("<span style=\" font-size:24pt; color:#000000;\">Question 4</span>"));

    }
}

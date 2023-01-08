#ifndef MYCALCULATOR_H
#define MYCALCULATOR_H

#include "QLabel"
#include "QLineEdit"
#include <QWidget>
#include "QString"
#include "qmenu.h"
#include "qmenubar.h"
#include "qpushbutton.h"
#include <QValidator>
#include <stack>
#include <QStack>
#include <QRegExp>

struct operations
{
    QString operat;
    int prior;
};


class MyValidator : public QValidator
{
public:
    MyValidator(QObject *parent): QValidator(parent)
    {}
    virtual State validate(QString &str,int  &pos) const
    {
        QRegExp rxp=QRegExp(QObject::tr("[A-Za-zА-Яа-я|!|@|#|$|%|&|_|=|\"|?|№|:|;|?|<|>|,|{|}|\\[|\\]|~|\\s]"));
        if(str.contains(rxp)){ return Invalid;}
        return Acceptable;
        pos=0;
    }
};

class MyCaclulator : public QWidget
{
    Q_OBJECT
public:
    explicit MyCaclulator(QWidget *parent = nullptr);
    QMenuBar *bar_mnu=new QMenuBar;
    QMenu *mnu=new QMenu("Меню");
    QLineEdit *resh=new QLineEdit;
    operations item;
    QLabel *polska=new QLabel;
    QLineEdit *expression=new QLineEdit;
    QString str;
    QPushButton *cast= new QPushButton("Решить");
    QList <QString> numb;
    QStack <operations> oper;
    QStack <double> call;
    QLabel *double_answ=new QLabel;
    QString nwst;


    void show_n_calculate();
    void calculate(QList<QString> &numb);
    int priority(QString &STR);
public slots:
    void Take_to_stack();
    void  NEW_WINDOW();


};

#endif // MYCALCULATOR_H

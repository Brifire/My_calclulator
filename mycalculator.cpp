#include "mycalculator.h"
#include "QLabel"
#include "QBoxLayout"
#include "qlineedit.h"
#include "qobjectdefs.h"
#include <QString>
#include <QDebug>
#include <iostream>
#include <iterator>
#include <QtMath>
#include <QRegExp>
#include <QAction>
#include <QMessageBox>
#include <QApplication>



MyCaclulator::MyCaclulator(QWidget *parent)
    : QWidget{parent}
{
    QLabel *startMenu=new QLabel("Введите выражение");
    QLabel *head_2=new QLabel("Запись в обратной польской:");
    QLabel *head_3=new QLabel("Решение:");
    startMenu->setBuddy(expression);
    head_2->setBuddy(head_3);
    QObject::connect(cast,SIGNAL(clicked(bool)),this,SLOT(Take_to_stack()));
    bar_mnu->addMenu(mnu);
    bar_mnu->platformMenuBar();
    QAction *help=new QAction("Справка");
    QAction *ext=new QAction("Выход");
    mnu->addAction(help);
    mnu->addAction(ext);
    QObject::connect(ext,SIGNAL(triggered(bool)),QApplication::instance(),SLOT(quit()));
    QObject::connect(help,SIGNAL(triggered(bool)),this,SLOT(NEW_WINDOW()));
    MyValidator *razdva=new MyValidator(expression);
    expression->setValidator(razdva);
    QVBoxLayout *Play=new QVBoxLayout;
    Play->setMenuBar(bar_mnu);
    Play->addWidget(startMenu);
    Play->addWidget(expression);
    Play->addWidget(cast);
    Play->addWidget(head_2);
    Play->addWidget(polska);
    Play->addWidget(head_3);
    Play->addWidget(double_answ);
    this->setLayout(Play);
    this->setWindowTitle("Calculator");
}

void MyCaclulator::show_n_calculate()
{

    QString str_for_polska;
    QString str_for_it;
    auto it=numb.begin();
    while(it!=numb.end())
    {
        str_for_it=(*it);
        str_for_polska+=str_for_it;
        it++;
    }
    polska->setText(str_for_polska);
    calculate(numb);
    double db=call.top();
    double_answ->setText(QString::number(db));
    numb.clear();
}

void MyCaclulator::calculate(QList<QString> &numb)
{
    double a,b,f;
    QString c;
    QList<QString>::Iterator IT=numb.begin();
    while (IT!=numb.end())
    {
        QString SSS=*IT;
        if(SSS!='+'&&SSS!='*'&&SSS!='-'&&SSS!='/'&&SSS!='^')
        {
            c=(*IT);
            a=c.toDouble();
            call.push(a);

        }
        if(SSS=='+'||SSS=='-'||SSS=='*'||SSS=='/'||SSS=='^')
        {
            c=(*IT);
            switch (c[0].toLatin1())
            {
            case '+':
                a=call.top();
                call.pop();
                b=call.top();
                call.pop();
                f=a+b;
                call.push(f);

                break;
            case '*':
                a=call.top();
                call.pop();
                b=call.top();
                call.pop();
                f=a*b;
                call.push(f);

                break;
            case '-':
                a=call.top();
                call.pop();
                b=call.top();
                call.pop();
                f=b-a;
                call.push(f);

                break;
            case '/':
                a=call.top();
                call.pop();
                b=call.top();
                call.pop();
                f=b/a;
                call.push(f);

                break;
            case '^':
                a=call.top();
                call.pop();
                b=call.top();
                call.pop();
                f=pow(b,a);
                call.push(f);
            default:

                break;
            }
        }
        ++IT;

    }

}

void MyCaclulator::Take_to_stack()
{
    int i=0;
    std::string EXP;
    EXP=expression->text().toStdString();
    std::cout<<EXP<<std::endl<<EXP.size()<<std::endl;
    str=expression->text();
    //str="123*(5)(-5)";
    if(str.isEmpty())
    {
        QMessageBox::critical(this,"Ошибка","Вы не ввели выражение");
        oper.clear();
        numb.clear();
        return;
    }
    polska->clear();

    bool flag=false;
    bool skobka=false;
    QString nwst_2;
    nwst=str[0];


    for ( i = 0; i < str.size(); ++i)
    {

        nwst=str[i];
        if(i>=1&&(str[i-1]=='.'||str[i-1]=='-'||str[i-1]=='+'||str[i-1]=='*'||str[i-1]=='^'||str[i-1]=='/')&&(str[i]=='.'||str[i]=='-'||str[i]=='+'||str[i]=='*'||str[i]=='/'||str[i]=='^'))
        {
         QMessageBox::critical(this,"Ошибка","Неправильно введенное выражение");
         oper.clear();
         numb.clear();
         return;
        };
        if(str[0]=='-'&&i==0) flag=true;
        if(i>0)
        {
            if (str[i-1]=='('&&str[i]=='-')
                flag=true;
        }


        if((nwst>='0'&& nwst<='9')||flag==true)
        {
            while ((str[i]!='+'&&str[i]!='-'&&str[i]!='*'&&str[i]!='/'&&str[i]!='\0'&&str[i]!=')'&&str[i]!='^')||(flag==true))
            {
                nwst_2+=str[i];
                ++i;
                flag=false;
                if(i>=1&&str[i-1]=='.'&&str[i]=='.')
                {
                    QMessageBox::critical(this,"Ошибка","Неправельно введенное выражение");
                    oper.clear();
                    numb.clear();
                    return;
                }
            }
            numb.append(nwst_2);
            nwst_2=' ';
            --i;
            continue;
        }
        if(nwst=='(')
        {
            skobka=true;
            item.operat=nwst;
            item.prior=1;
            oper.push_back(item);
        }
        if(nwst==')')
        {
            if(skobka==false)
            {
                QMessageBox::critical(this,"Ошибка","Неправельно введенное выражение");
                oper.clear();
                numb.clear();
                return;
            }
            while (oper.top().operat!='(')
            {
                numb.append(oper.top().operat);
                oper.pop();
            }
            oper.pop();
            skobka=false;
        }
        if(nwst=='+'||nwst=='-'||nwst=='*'||nwst=='/'||nwst=='^')
        {
            int a=priority(nwst);

            if(oper.isEmpty()||oper.top().prior<a)
            {
                int b=priority(nwst);
                item.prior=b;
                item.operat=nwst;
                oper.push_back(item);
            }
            else if(!oper.isEmpty()&& (oper.top().prior==a||oper.top().prior>a))
            {
                while(oper.top().prior==a||oper.top().prior>a)
                {
                    numb.append(oper.top().operat);
                    oper.pop();
                    if(oper.isEmpty()) break;
                }
                item.operat=nwst;
                item.prior=priority(nwst);
                oper.append(item);
            }

        }

    }

    while(!oper.isEmpty())
    {
        if(oper.top().operat=='(')
        {
            QMessageBox::critical(this,"Ошибка","Неправельно введенное выражение");
            oper.clear();
            numb.clear();
            return;
        }
        numb.append(oper.top().operat);
        oper.pop();
    }
    show_n_calculate();
}

void MyCaclulator::NEW_WINDOW()
{
QMessageBox::about(this,"Информация","Данная программа считывает выражение, далее переводит выражение в обратную польскую запись, а потом расчитывает данное выражение\nК примеру:\n(2*2)^2 \n23+5*2 \nНедопустимые выражения:\n--21+3 \n15++4 \n12**23 \nДля того чтобы записать отрицательное число, используйте скобку.\nК примеру: \n -2-(-5)\nДля записи дробных выражение используйте '.' " );
}


int MyCaclulator::priority(QString &STR)
{
    if(STR=='^') return 4;
    if(STR=='*'||STR=='/') return 3;
    if(STR=='+'||STR=='-') return 2;
    if(STR=='(') return 1;
    return 0;
}

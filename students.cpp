#include "students.h"
#include <QTabWidget>
#include "qlabel.h"
#include "qtablewidget.h"
#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QValidator>
Students::Students(QWidget *parent)
    : QWidget{parent}
{
QPushButton *ADD=new  QPushButton("Make new student");
QPushButton *Open=new QPushButton("Open what u have  been done");
QPushButton *DELETE=new QPushButton("DELETE ALL");
QObject::connect(ADD,SIGNAL(clicked(bool)),this,SLOT(MakeStudent()));
QObject::connect(Open,SIGNAL(clicked(bool)),this,SLOT(OPEN()));
QObject::connect(DELETE,SIGNAL(clicked(bool)),this,SLOT(Delete_Previous_Element()));
QHBoxLayout *Lay=new QHBoxLayout;
Lay->addWidget(ADD);
Lay->addWidget(Open);
Lay->addWidget(DELETE);
setLayout(Lay);
}

void Students::MakeStudent()
{
   QDoubleValidator *DOUBLE=new QDoubleValidator;
   QPushButton *Button_save=new QPushButton("Add Student");
   QWidget *raz=new QWidget;
   QLabel *NAME=new QLabel("NAME") ;
   QLabel *POINT=new QLabel("POINT") ;
   QLineEdit *name=new QLineEdit;
   NAME->setBuddy(name);
   QLineEdit *points= new QLineEdit;
   POINT->setBuddy(points);
   points->setValidator(DOUBLE);
   raz->focusWidget();
   QHBoxLayout* SecLay=new QHBoxLayout;
   SecLay->addWidget(NAME);
     SecLay->addWidget(name);
   SecLay->addWidget(POINT);
   SecLay->addWidget(points);
   SecLay->addWidget(Button_save);
   raz->setLayout(SecLay);
   QObject::connect(Button_save,SIGNAL(clicked(bool)),this,SLOT(Save_st()));
   sschecked();
   raz->show();



}

void Students::Delete_Previous_Element()
{

}

void Students::OPEN()
{
     QTableWidget *dva=new QTableWidget(ss,1);

     for (int i = 0; i < ss; ++i)
     {
      QTableWidgetItem *dsa=new QTableWidgetItem;
      QTableWidgetItem *sad=new QTableWidgetItem;
      dsa->setText(elements->first());
      sad->setText(elements->last());
      dva->setItem(i,i,dsa);
      dva->setItem(i,i+1,sad);
     }
dva->show();

}

void Students::Save_st()
{
    QString str_name=name->text();
    QString str_double=points->text();
    elements->insert(str_name,str_double);
}



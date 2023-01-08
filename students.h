#ifndef STUDENTS_H
#define STUDENTS_H

#include <QPushButton>
#include <QWidget>
#include <QStack>
#include <QMap>
#include <QLineEdit>

class Students : public QWidget
{
    Q_OBJECT
private:
    QMap<QString,QString> *elements=new QMap<QString,QString>;
     QWidget *raz=new QWidget;
      QLineEdit *name=new QLineEdit;
      QLineEdit *points= new QLineEdit;
      int ss=0;
public:
    explicit Students(QWidget *parent = nullptr);
    void sschecked();
public slots:
    void MakeStudent();
    void Delete_Previous_Element();
    void OPEN();
    void Save_st();
signals:
    void NewSt();
};

#endif // STUDENTS_H

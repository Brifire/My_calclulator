#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
private:
    int m_value=0;
public:
    explicit Counter(QObject *parent = nullptr);
public slots:
    void sender();

signals:
void counterchanged(int);
void goodbye();
};

#endif // COUNTER_H

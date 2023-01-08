#include "counter.h"

Counter::Counter(QObject *parent)
    : QObject{parent}
{

}

void Counter::sender()
{
    emit counterchanged(++m_value);
    if(m_value==5)
    {
        emit  goodbye();

    }
}

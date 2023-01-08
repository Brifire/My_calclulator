#include "mousefilter.h"

MouseFilter::MouseFilter(QObject *pobj):QObject(pobj)
{

}
bool MouseFilter::eventFilter(QObject *pobj, QEvent *pe)
{
    if(pe->type())
}

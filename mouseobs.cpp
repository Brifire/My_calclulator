#include "mouseobs.h"
#include "qevent.h"

MouseObs::MouseObs(QWidget *pwgt)
    : QLabel{pwgt}
{
setAlignment(Qt::AlignCenter);
setText("Mouse interactions\n(Press a mouse button)");
}

void MouseObs::mousePressEvent(QMouseEvent *pe)
{
    dumpEvent(pe,"Mouse Pressed");
}

void MouseObs::mouseReleaseEvent(QMouseEvent *pe)
{
    dumpEvent(pe,"Mouse Relesed");
}

void MouseObs::mouseMoveEvent(QMouseEvent *pe)
{
    dumpEvent(pe,"Mouse is moving");
}

void MouseObs::dumpEvent(QMouseEvent *pe, const QString &strMessage)
{
    setText(strMessage
            +"\n buttons()="+buttonsInfo(pe)
            +"\n x()="+QString::number(pe->x())
            +"\n y()="+QString::number(pe->y())
            +"\n globalx()="+QString::number(pe->globalX())
            +"\n globaly()="+QString::number(pe->globalY())
            +"\n modifirs()="+ modifiersInfo(pe)
            );
}

QString MouseObs::modifiersInfo(QMouseEvent *pe)
{
    QString strModiers;
    if(pe->modifiers()&Qt::ShiftModifier)
    {
        strModiers+="Shift";
    }
    if(pe->modifiers()&Qt::ControlModifier)
    {
        strModiers+="Control";
    }
    if(pe->modifiers()&Qt::AltModifier)
    {
        strModiers+="Alt";
    }
    return strModiers;
}

QString MouseObs::buttonsInfo(QMouseEvent *pe)
{
    QString strButtons;
    if(pe->buttons()&Qt::LeftButton)
    {
        strButtons+="Left";
    }
    if(pe->buttons()&Qt::RightButton)
    {
        strButtons+="Right";
    }
    if(pe->buttons()&Qt::MiddleButton)
    {
        strButtons+="Middle";
    }
    return strButtons;
}

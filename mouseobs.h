#ifndef MOUSEOBS_H
#define MOUSEOBS_H

#include <QWidget>
#include <QLabel>

class MouseObs : public QLabel
{
    Q_OBJECT
public:
    explicit MouseObs(QWidget *parent = nullptr);
protected:
    virtual void mousePressEvent(QMouseEvent *pe);
    virtual void mouseReleaseEvent(QMouseEvent *pe);
    virtual void mouseMoveEvent(QMouseEvent *pe);

    void dumpEvent(QMouseEvent *pe,const QString &strMessage);
    QString modifiersInfo(QMouseEvent *pe);
    QString buttonsInfo (QMouseEvent *pe);
signals:

};

#endif // MOUSEOBS_H

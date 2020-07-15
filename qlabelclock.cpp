#include "qlabelclock.h"
#include <QDateTime>
#include <QTimer>
#include <QMouseEvent>

QLabelClock::QLabelClock(QWidget *parent): QLabel(parent)
{
    this->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz"));
    this->setStyleSheet("background-color: black; color: white; font-size: 20px; font-family: Microsoft YaHei");

    //创建定时器
    timer = new QTimer(parent);
    //定时器timeout信号与时间刷新函数进行绑定/关联
    //信号与槽机制实现
    connect(timer, &QTimer::timeout, this, &QLabelClock::refresh);
    timer->start(1);//ms
}

void QLabelClock::refresh()
{
    if (1 == refreshEnable)
        //刷新文本内容
        this->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz"));
}

//鼠标按下事件处理函数
//事件机制
void QLabelClock::mousePressEvent(QMouseEvent *ev)
{
    if (ev->buttons() == Qt::LeftButton)
    {
        if(this->refreshEnable)
            this->refreshEnable = 0;
        else
            this->refreshEnable = 1;
    }
}

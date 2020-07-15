#ifndef QLABELCLOCK_H
#define QLABELCLOCK_H

#include <QWidget>
#include <QLabel>

class QLabelClock : public QLabel
{
   Q_OBJECT
//私有函数
private:
    QString now();
signals:
    void clicked();
//公有
public:
    QTimer *timer;
    int refreshEnable = 1;

    //构造函数
    QLabelClock(QWidget *parent);

    void refresh();

    void refreshToggle();

    void sendClickedSignal();
protected:
    void mousePressEvent(QMouseEvent *ev) override;

};

#endif // QLABELCLOCK_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include "qlabelclock.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建界面
    QWidget *widgetMain = new QWidget();

    // 修改参数
    widgetMain->setWindowTitle("温度"); //可显示团队名称
    widgetMain->resize(300,150);
    widgetMain->setStyleSheet("background-color: black");

    // 创建标签
    QLabel *labelTemperatureText = new QLabel();

    // 修改便签内容
    labelTemperatureText->setText("T-");
    // 设置父控件
    labelTemperatureText->setParent(widgetMain);
    labelTemperatureText->setGeometry(0, 50, 50, 50);
    labelTemperatureText->setStyleSheet("background-color: black; color: white; font-size: 40px; font-family: Microsoft YaHei"); // todo 完成字号、字体设置

    // 创建标签
    QLabel *labelTemperatureData = new QLabel(widgetMain);
    // 修改标签内容
    labelTemperatureData->setText("36.5");
    labelTemperatureData->setGeometry(50, 0, 150, 150);
    labelTemperatureData->setStyleSheet("background-color: black; color: rgb(255,0,255); font-size: 60px; font-family: Microsoft YaHei");// todo 完成字号、字体设置

    // 创建标签
    QLabel *labeldegree = new QLabel(widgetMain);
    // 修改标签内容
    labeldegree->setText("℃");
    labeldegree->setGeometry(200, 0, 50, 100);
    labeldegree->setStyleSheet("background-color: black; color: rgb(255,0,255); font-size: 30px; font-family: Microsoft YaHei");// todo 完成字号、字体设置

    QLabelClock *labelClock = new QLabelClock(widgetMain);
    labelClock->setGeometry(0,150-30,300,30);

    // 更新主窗口显示内容
    widgetMain->show();

    return a.exec();
}

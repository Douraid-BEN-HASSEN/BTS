#ifndef CCHARLYROBOT_H
#define CCHARLYROBOT_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>
#include <QPushButton>

class CCharlyrobot : public QMainWindow
{
    Q_OBJECT

public:
    CCharlyrobot(QWidget *parent = 0);
    ~CCharlyrobot();

public slots:
    void hotkey();
private:
    QSerialPort *m_portSerie;
    QTimer hotkeyTMR;
    QPushButton hautBTN;
    QPushButton basBTN;
    QPushButton droiteBTN;
    QPushButton gaucheBTN;
    int xPos, yPos, zPos;
};

#endif // CCHARLYROBOT_H

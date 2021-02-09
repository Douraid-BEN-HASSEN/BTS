#include "ccharlyrobot.h"
#include <Windows.h>
#include <string>
#include <QByteArray>
#include <iostream>

CCharlyrobot::CCharlyrobot(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(100, 75);
    xPos, yPos, zPos = 0;

    m_portSerie = new QSerialPort;

    // Configuration
    m_portSerie->setPortName("COM1");
    m_portSerie->setBaudRate(9600);
    m_portSerie->setDataBits(QSerialPort::Data8);
    m_portSerie->setStopBits(QSerialPort::OneStop);
    m_portSerie->setParity(QSerialPort::NoParity);

    // On ouvre le port en lecture/ecriture
    m_portSerie->open(QIODevice::ReadWrite);

    hautBTN.setParent(this);
    hautBTN.setGeometry(30, 5, 25, 25);
    hautBTN.setText("^");
    hautBTN.setStyleSheet("background-color: white");

    basBTN.setParent(this);
    basBTN.setGeometry(30, 30, 25, 25);
    basBTN.setText("v");
    basBTN.setStyleSheet("background-color: white");

    droiteBTN.setParent(this);
    droiteBTN.setGeometry(55, 30, 25, 25);
    droiteBTN.setText(">");
    droiteBTN.setStyleSheet("background-color: white");

    gaucheBTN.setParent(this);
    gaucheBTN.setGeometry(5, 30, 25, 25);
    gaucheBTN.setText("<");
    gaucheBTN.setStyleSheet("background-color: white");

    hotkeyTMR.start(1);
    connect(&hotkeyTMR, SIGNAL(timeout()), this, SLOT(hotkey()));

    m_portSerie->write("@03\r@0R3\r");
}

void CCharlyrobot::hotkey(){
    if(GetAsyncKeyState(VK_UP)){
        hautBTN.setStyleSheet("background-color: green");
        yPos += 5;
        std::string message = "@0A" + std::to_string(xPos) + "5000," + std::to_string(yPos) + ",5000\r";
        m_portSerie->write(QByteArray::fromStdString(message));
    }else{
        hautBTN.setStyleSheet("background-color: white");
    }

    if(GetAsyncKeyState(VK_DOWN)){
        basBTN.setStyleSheet("background-color: green");
        yPos -= 5;
        std::string message = "@0A" + std::to_string(xPos) + "5000," + std::to_string(yPos) + ",5000\r";
        m_portSerie->write(QByteArray::fromStdString(message));
    }else{
        basBTN.setStyleSheet("background-color: white");
    }

    if(GetAsyncKeyState(VK_LEFT)){
        gaucheBTN.setStyleSheet("background-color: green");
        xPos -= 5;
        std::string message = "@0A" + std::to_string(xPos) + "5000," + std::to_string(yPos) + ",5000\r";
        m_portSerie->write(QByteArray::fromStdString(message));

    }else{
        gaucheBTN.setStyleSheet("background-color: white");
    }

    if(GetAsyncKeyState(VK_RIGHT)){
        droiteBTN.setStyleSheet("background-color: green");
        xPos += 5;
        std::string message = "@0A" + std::to_string(xPos) + "5000," + std::to_string(yPos) + ",5000\r";
        m_portSerie->write(QByteArray::fromStdString(message));

    }else{
        droiteBTN.setStyleSheet("background-color: white");
    }
}

CCharlyrobot::~CCharlyrobot()
{

}



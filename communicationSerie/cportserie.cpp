#include "cportserie.h"

CPortSerie::CPortSerie(QWidget *parent)
    : QMainWindow(parent)
{
       this->resize(800,600);

       socket = new QSerialPort(this);

       laConnexion = new QLabel("En Attente de connexion", this);
       laConnexion->setGeometry(400,150,200,50);

       bConnexion = new QPushButton("Connexion", this);
       bConnexion->setGeometry(400,200,200,50);

       laSaisie = new QLabel("Saisir un message", this);
       laSaisie->setGeometry(200,100,200,50);

       bEnvoyer = new QPushButton("Envoyer", this);
       bEnvoyer->setGeometry(200,200,200,50);

       leMsg = new QLineEdit(this);
       leMsg->setGeometry(200,150,200,50);

       connect(bEnvoyer,SIGNAL(clicked(bool)),this,SLOT(envoyerDonnee()));
       connect(bConnexion,SIGNAL(clicked(bool)),this,SLOT(connexion()));
}

CPortSerie::~CPortSerie()
{
    delete leMsg;
    delete bEnvoyer;
    delete laSaisie;
    delete bConnexion;
    delete laConnexion;
    delete socket;
}

void CPortSerie::envoyerDonnee(void)
{
    msg = leMsg->text();
    // Envoit de la donnée

}

void CPortSerie::connexion(void)
{
    socket->setPort(QSerialPortInfo('COM1'));
    if(socket->open(QIODevice::ReadWrite) == true){

        socket->setBaudRate(QSerialPort::Baud9600);
        socket->setDataBits(QSerialPort::Data7);
        socket->setParity(QSerialPort::EvenParity);
        socket->setStopBits(QSerialPort::OneStop);

        laConnexion->setText("Connexion éffectuée");
    }else{
        laConnexion->setText("Connexion échouée");
    }


}

#ifndef CPORTSERIE_H
#define CPORTSERIE_H

#include <QMainWindow>
#include <QSerialPort>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QString>
#include <QLineEdit>
#include <QByteArray>

class CPortSerie : public QMainWindow
{
    Q_OBJECT

public:
    CPortSerie(QWidget *parent = 0);
    ~CPortSerie();

private :
    QSerialPort *socket;
    QLabel *laSaisie;
    QPushButton *bEnvoyer;
    QLabel *laConnexion;
    QPushButton *bConnexion;
    QLineEdit *leMsg;

    QString msg;
    QString msgEnca;
    QByteArray trame;

public slots :

    void connexion(void);
    void envoyerDonnee(void);
};

#endif // CPORTSERIE_H

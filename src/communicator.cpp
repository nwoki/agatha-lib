/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#include "../include/communicator.h"
#include "../include/player.h"
#include "responsegrabber.h"

#include <QtNetwork/QUdpSocket>
#include <QtCore/QMutex>
#include <QtCore/QMutexLocker>

using namespace Agatha;

class Agatha::CommunicatorPrivate
{
public:
    CommunicatorPrivate()
        : agathaIp("default")
        , agathaPort(12345)
        , udpSocket(NULL)
        , mutex(new QMutex(QMutex::Recursive))
        , grabber(NULL)
        {}

    ~CommunicatorPrivate()
    {
        if (grabber) {
            grabber->stop();
            grabber->wait();
        }
        delete grabber;
        delete udpSocket;
        udpSocket = NULL;
    }

    std::string agathaIp;
    int agathaPort;
    std::string authToken;  /// TODO token diverso ad ogni richiesta.

    QUdpSocket *udpSocket;
    QMutex *mutex;
    ResponseGrabber *grabber;
};

Communicator::Communicator(const std::string &agathaIp, int agathaPort, const std::string &authToken)
    : d(new CommunicatorPrivate)
{
    d->agathaIp = agathaIp;
    d->agathaPort = agathaPort;
    d->authToken = authToken;

    /// TODO info for the socket binding will have to be given by the bot so users can set custom port
    /// TODO controllare che non sia stato già creato.
    /// BTW: il comando bind serve per specificare su quale interfaccia e porta aprire il socket, non a chi trasmettere.
    /// vedi comando QUdpSocket::writeDatagram per invio dati.
    d->udpSocket = new QUdpSocket();
    d->udpSocket->bind(QHostAddress(d->agathaIp.c_str()), d->agathaPort);

    // set and start the datagrams grabber
    if (d->grabber) delete (d->grabber);
    d->grabber = new ResponseGrabber(d->udpSocket, d->mutex);
    d->grabber->start();
}

Communicator::~Communicator()
{
    delete d;
}

void Communicator::add(Player *player)
{
    QMutexLocker locker(d->mutex);
    /// TODO come prima, invia direttamente la richiesta attraverso il socket.
}

void Communicator::ban(Player *player)
{
    QMutexLocker locker(d->mutex);
    /// TODO come prima, invia direttamente la richiesta attraverso il socket.
}

void Communicator::isBanned(Player *player)
{
    QMutexLocker locker(d->mutex);
    /// TODO come prima, invia direttamente la richiesta attraverso il socket.
}


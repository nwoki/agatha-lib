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
#include "callbacklauncher.h"
#include "buffer.h"

#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>
#include <QtCore/QMutex>
#include <QtCore/QMutexLocker>

using namespace Agatha;

class Agatha::CommunicatorPrivate
{
public:
    CommunicatorPrivate()
        : agathaIp(QHostAddress())
        , agathaPort(12345)
        , multiThread(false)
        , udpSocket(NULL)
        , mutex(new QMutex(QMutex::Recursive))
        , buffer(NULL)
        , grabber(NULL)
        , callbackLauncher(NULL)
        {}

    ~CommunicatorPrivate()
    {
        if (grabber) {
            grabber->stop();
            grabber->wait(1000);
            delete grabber;
        }
        if (callbackLauncher) {
            if (multiThread) callbackLauncher->stop();
            callbackLauncher->wait(1000);
            delete callbackLauncher;
        }
        if (buffer) delete buffer;
        delete mutex;
        if (udpSocket) {
            udpSocket->close();
            delete udpSocket;
        }
    }

    QHostAddress agathaIp;
    int agathaPort;
    bool multiThread;

    QUdpSocket *udpSocket;
    QMutex *mutex;
    Buffer *buffer;
    ResponseGrabber *grabber;
    CallbackLauncher *callbackLauncher;
};

// inizialize the static field
Communicator *Communicator::instance = NULL;

Communicator::Communicator(const int localPort, const std::string &agathaIp, const int agathaPort, const bool multiThread)
    : d(new CommunicatorPrivate)
{
    d->agathaIp = QHostAddress(agathaIp.c_str());
    d->agathaPort = agathaPort;
    d->multiThread = multiThread;

    /// TODO info for the socket binding will have to be given by the bot so users can set custom port
    /// BTW: il comando bind serve per specificare su quale interfaccia e porta aprire il socket, non a chi trasmettere.
    /// vedi comando QUdpSocket::writeDatagram per invio dati.
    d->udpSocket = new QUdpSocket();

    //create the buffer
    d->buffer = new Buffer();

    // set and start the datagrams grabber
    d->grabber = new ResponseGrabber(d->udpSocket, d->mutex, d->buffer);
    d->grabber->start();

    //create the callbackLauncher
    d->callbackLauncher = new CallbackLauncher( d->buffer );
    if ( d->multiThread ) d->callbackLauncher->start();
}

Communicator::~Communicator()
{
    delete d;
    instance = NULL;
}

Communicator* Communicator::createCommunicatorInstance(const int localPort, const std::string &agathaIp, const int agathaPort, const bool multiThread)
{
    if (!instance) {
        instance = new Communicator(localPort, agathaIp, agathaPort, multiThread);

        //look if we should use the ipv4 or ipv6: decide it depending on the agathaip (use the same protocol).
        QHostAddress t;
        if ( QHostAddress(agathaIp.c_str()).protocol() == QAbstractSocket::IPv6Protocol ) {
            t = QHostAddress(QHostAddress::AnyIPv6); //IPv6
        } else {
            t = QHostAddress(QHostAddress::Any); //IPv4
        }
        if ( instance->d->udpSocket->bind(t, localPort) ) {
            delete instance;
            instance = NULL;
        }
    }
    return instance;
}

Communicator* Communicator::getCommunicatorInstance()
{
    return instance;
}

void Communicator::registerCallbacks(const std::vector<AgathaCallback *> &callbackObjects)
{
    d->callbackLauncher->setCallbacks(callbackObjects);
}

void Communicator::add(Player *player, const std::string &token)
{
    QMutexLocker locker(d->mutex);

    RequestMaker t;
    d->udpSocket->writeDatagram( t.createRequest(token, RequestMaker::URT_411, RequestMaker::ADD_PLAYER, player), d->agathaIp, d->agathaPort);
}

void Communicator::ban(Player *player, const std::string &token)
{
    QMutexLocker locker(d->mutex);
    RequestMaker t;
    d->udpSocket->writeDatagram( t.createRequest(token, RequestMaker::URT_411, RequestMaker::BAN, player), d->agathaIp, d->agathaPort);
}

void Communicator::isBanned(Player *player, const std::string &token)
{
    QMutexLocker locker(d->mutex);
    RequestMaker t;
    d->udpSocket->writeDatagram( t.createRequest(token, RequestMaker::URT_411, RequestMaker::IS_BANNED, player), d->agathaIp, d->agathaPort);
}

void Communicator::doYourJob()
{
    if (!d->multiThread) {
        d->callbackLauncher->takeData();
    }
}

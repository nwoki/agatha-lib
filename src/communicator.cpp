/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#include "../include/communicator.h"
#include "../include/player.h"
#include "requestmaker.h"

#include <QtNetwork/QUdpSocket>

using namespace Agatha;

class Agatha::CommunicatorPrivate
{
public:
    ~CommunicatorPrivate()
    {
        delete udpSocket;
    }

    std::string agathaIp;
    int agathaPort;
    std::string authToken;

    QUdpSocket *udpSocket;
    /// TODO QThreadPool for handling Request objects (inherit QThread)
};

Communicator::Communicator(const std::string &agathaIp, int agathaPort, const std::string &authToken)
    : d(new CommunicatorPrivate)
{
    d->agathaIp = agathaIp;
    d->agathaPort = agathaPort;
    d->authToken = authToken;

    /// TODO info for the socket binding will have to be given by the bot so users can set custom port
    d->udpSocket = new QUdpSocket();
    d->udpSocket->bind(QHostAddress(d->agathaIp.c_str()), d->agathaPort);
}

Communicator::~Communicator()
{
    delete d->udpSocket;
    delete d;
}

void Communicator::add(Player *player)
{
}

void Communicator::ban(Player *player)
{
}

void Communicator::isBanned(Player *player)
{
}


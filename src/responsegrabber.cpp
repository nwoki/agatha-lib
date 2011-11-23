/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */

#include "../include/player.h"
#include "responsegrabber.h"

#include <QtCore/QMutexLocker>

using namespace Agatha;

ResponseGrabber::ResponseGrabber(QUdpSocket* socket, QMutex* mutex, QObject* parent)
    : QThread(parent)
    , m_socket(socket)
    , m_mutex(mutex)
{
    moveToThread(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
    exec();
}

ResponseGrabber::~ResponseGrabber()
{
    this->quit();
}

void ResponseGrabber::stop()
{
    if(currentThread() != this)
    {
        QMetaObject::invokeMethod(this, "stop",
                                  Qt::QueuedConnection);
    }
    else
    {
        quit();
    }
}

void ResponseGrabber::readData()
{
    QMutexLocker(m_mutex);
    // TODO read data from socket
}
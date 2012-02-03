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

ResponseGrabber::ResponseGrabber(QUdpSocket *socket, QMutex *mutex, Buffer *buffer, QObject *parent)
    : QThread(parent)
    , m_socket(socket)
    , m_mutex(mutex)
    , m_buffer(buffer)
{
}

void ResponseGrabber::run()
{
    moveToThread(this);
    m_buffer->moveToThread(this);
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(readData()));
    exec();
}

ResponseGrabber::~ResponseGrabber()
{
    quit();
}

void ResponseGrabber::stop()
{
    if(currentThread() != this) {
        QMetaObject::invokeMethod(this, "stop", Qt::QueuedConnection);
    } else {
        quit();
    }
}

void ResponseGrabber::readData()
{
    QMutexLocker locker(m_mutex);

    // TODO read data from socket
}

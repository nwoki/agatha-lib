/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */

#ifndef RESPONSEGRABBER_H
#define RESPONSEGRABBER_H

#include "requestmaker.h"

#include <QtCore/QThread>
#include <QtCore/QMutex>
#include <QtNetwork/QUdpSocket>

namespace Agatha {

class ResponseGrabber : public QThread
{
    Q_OBJECT
public:
    ResponseGrabber(QUdpSocket *socket, QMutex *mutex, QObject *parent = 0);
    ~ResponseGrabber();
    void stop();

public slots:
    void readData();
private:
    QUdpSocket *m_socket;
    QMutex *m_mutex;  //mutex of the socket.
};

};

#endif  // RESPONSEGRABBER_H
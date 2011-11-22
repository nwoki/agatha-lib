/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */

#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QMutex>
#include <QVector>
#include "request.h"
#include "../include/player.h"

namespace Agatha {


class ThreadManager : QObject {
    Q_OBJECT

public:
    ThreadManager(QObject* parent = 0);
    ~ThreadManager();

public slots:
    void threadTerminated(Request* thread = 0);
    
private:
    QMutex *lock;
    QVector<Request *> threads;  //TODO valutare se usare un array di dimensioni fisse
};


};

#endif  // THREADMANAGER_H

/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */

#ifndef CALLBACKLAUNCHER_H
#define CALLBACKLAUNCHER_H

#include "buffer.h"
#include "../include/agathacallback.h"

#include <QtCore/QThread>

namespace Agatha {

class CallbackLauncher : public QThread
{
    Q_OBJECT
public:
    CallbackLauncher( Buffer *buf, QObject *parent = 0 );
    ~CallbackLauncher();
    void run();
    void stop();

public slots:
    void takeData();

private:
    void executeCallbacks();

    Buffer *m_buffer;
};

};

#endif //CALLBACKLAUNCHER_H

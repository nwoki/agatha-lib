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
#include <vector>

namespace Agatha {

class CallbackLauncher : public QThread
{
    Q_OBJECT
public:
    CallbackLauncher( Buffer *buf, QObject *parent = 0 );
    ~CallbackLauncher();
    void run();
    void setCallbacks(const std::vector<AgathaCallback *> &callbacks);

public slots:
    void takeData();
    void stop();

private:
    void executeCallbacks();

    Buffer *m_buffer;
    std::vector<AgathaCallback *> m_callbacks;
};

};

#endif //CALLBACKLAUNCHER_H

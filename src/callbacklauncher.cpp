/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */

#include "callbacklauncher.h"

#include <QtCore/QString>
#include <iostream>

using namespace Agatha;

CallbackLauncher::CallbackLauncher(Buffer *buf, QObject *parent)
    : QThread(parent)
    , m_buffer(buf)
{
}

CallbackLauncher::~CallbackLauncher()
{
    if ( this->isRunning() ) quit();
}

void CallbackLauncher::setCallbacks(const std::vector< AgathaCallback* > &callbacks)
{
    m_callbacks = callbacks;
}

void CallbackLauncher::run()
{
    moveToThread(this);
    connect(m_buffer, SIGNAL(newData()), this, SLOT(takeData()));
    exec();
}

void CallbackLauncher::stop()
{
    if(currentThread() != this) {
        QMetaObject::invokeMethod(this, "stop", Qt::QueuedConnection);
    } else {
        quit();
    }
}

void CallbackLauncher::executeCallbacks()
{
    while ( m_buffer->containsData() ){
        QString t = m_buffer->get();
        qDebug() << "Data received: " << t << "\n";
    }
}

void CallbackLauncher::takeData()
{
    //the event loop will manage just one event at time. So i don't need to manage multiple access, even if
    //i get 1 call for every new data inserted.
    executeCallbacks();
}

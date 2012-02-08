/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */
#include "buffer.h"

#include <QtCore/QMutexLocker>

using namespace Agatha;

Buffer::Buffer(QObject *parent) 
    : QObject(parent)
    , m_mutex(new QMutex(QMutex::Recursive))
    , m_data(QVector<QString>())
{
}

Buffer::~Buffer()
{
    m_mutex->lock();
    m_data.clear();
    m_mutex->unlock();
    delete m_mutex;
}

void Buffer::add(QString response)
{
    QMutexLocker lock(m_mutex);
    m_data.push_back(response);
    emit newData();
}

QString Buffer::get()
{
    QMutexLocker lock(m_mutex);
    if (m_data.empty()) {
        return NULL;
    }
    QString temp = m_data.first();
    m_data.pop_front();
    return temp;
}

bool Buffer::containsData()
{
    QMutexLocker lock(m_mutex);
    return !(m_data.empty()); 
}

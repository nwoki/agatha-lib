/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */

#ifndef BUFFER_H
#define BUFFER_H

#include <QtCore/QObject>
#include <QtCore/QVector>
#include <QtCore/QMutex>

#include "../include/response.h"

namespace Agatha {

class Buffer : public QObject
{
    Q_OBJECT
public:
    Buffer(QObject *parent = 0);
    ~Buffer();
    void add(Response *response);
    Response *get();
    bool containsData(); // returns true if it contains some responses.

signals:
    void newData();
private:
    QMutex *m_mutex; // mutex -> access to data.
    QVector<Response *> m_data;
};

};

#endif  // BUFFER_H
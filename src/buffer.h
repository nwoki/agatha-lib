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
#include <QtCore/QString>

namespace Agatha {

class Buffer : public QObject
{
    Q_OBJECT
public:
    Buffer(QObject *parent = 0);
    ~Buffer();
    void add(QString response);
    QString get();
    bool containsData(); // returns true if it contains some responses.

signals:
    void newData();
private:
    QMutex *m_mutex; // mutex -> access to data.
    QVector<QString> m_data;
};

};

#endif  // BUFFER_H

/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */

#include "threadManager.h"

using namespace Agatha;

ThreadManager::ThreadManager(QObject* parent): QObject(parent)
    , lock(new QMutex(QMutex::Recursive))
    , threads(QVector<Request *>(20))
{}

ThreadManager::~ThreadManager()
{}

void ThreadManager::threadTerminated(Request* thread)
{}
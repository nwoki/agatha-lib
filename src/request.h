/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#ifndef REQUEST_H
#define REQUEST_H

#include "requestmaker.h"

#include <QtCore/QThread>

namespace Agatha {

class Player;

class Request : public QThread
{
public:
    Request();
    ~Request();

private:

};

};

#endif  // REQUEST_H
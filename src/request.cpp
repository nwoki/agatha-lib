/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#include "../include/player.h"
#include "request.h"

using namespace Agatha;

Request::Request(RequestMaker::RequestType type, Player *player, QObject *parent)
    : QThread(parent)
{
}

Request::~Request()
{
}
/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#include "../include/player.h"
#include "requestmaker.h"

using namespace Agatha;

RequestMaker::RequestMaker()
{
}

RequestMaker::~RequestMaker()
{
}

QByteArray RequestMaker::createRequest(RequestMaker::RequestType type, Player *player)
{
    QByteArray request;

    if (type == IS_BANNED) {
        // TODO create ban query request
    } else if (type == BAN) {
        // TODO create ban request
    }

    return request;
}

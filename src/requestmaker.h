/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#ifndef REQUEST_MAKER_H
#define REQUEST_MAKER_H

#include <string>

#include <QtCore/QByteArray>

namespace Agatha {

class Player;

/**
 * Class used to generate requests to send to Agatha servers
 * @author Francesco Nwokeka
 */

class RequestMaker
{
public:
    enum RequestType {
        BAN,        /** used to tell Agatha to ban a given player */
        IS_BANNED,  /** used to query Agatha if a player has been banned */
    };

    RequestMaker();
    ~RequestMaker();

    /**
     * Creates a request for the given player to send to Agatha
     * @param type request type
     * @param player player info to add in request
     */
    QByteArray createRequest(RequestType type, Player *player);

private:
    /// QJson pointer to generate the json for sending
};

};

#endif  // REQUEST_MAKER_H
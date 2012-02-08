/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#ifndef REQUEST_MAKER_H
#define REQUEST_MAKER_H

#include "qjson/include/QJson/Serializer"

#include <string>

#include <QtCore/QByteArray>

namespace Agatha {

class Player;

/**
 * Class used to generate requests to send to Agatha servers
 * @author Francesco Nwokeka
 */

// take a look at this too: http://blog.vcreatelogic.com/2011/12/simple-json-parser-streamer-in-qt/
////TODO static class.

class RequestMaker
{
public:
    /**
     * @enum GameType the game for which we request Agatha's resources
     */
    enum GameType {
        URT_411     /** UrbanTerror 4.1.1 */
    };

    /**
     * @enum RequestType command request type for interaction with Agatha
     */
    enum RequestType {
        ADD_PLAYER, /** used to tell Agatha to add a given player to the database */
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
    QByteArray createRequest(const std::string &token, GameType game, RequestType type, Player *player);

private:
    QJson::Serializer m_jsonSerializer;
};

};

#endif  // REQUEST_MAKER_H